// ------------------------------------------------------------------

#include "common.h"
#include "drawimage.h"
#include "script.h"
#include "background.h"
#include "physics.h"
#include <fstream>

extern b2World *g_World;
b2Body *currentBody = NULL;

RenderTarget2DRGBA_Ptr g_Rt;

// ------------------------------------------------------------------

float ANIMATION_TIME = 3000.0f;

Background *background_init(int screenw,int screenh)
{
	g_Rt = RenderTarget2DRGBA_Ptr(new RenderTarget2DRGBA(screenw, screenh));
  Background *bkg = new Background;
  bkg->pos = v2i(0, 0);
  bkg->screenw = screenw;
  bkg->screenh = screenh;
  bkg->moving = 0;
  loadBackground(bkg, bkg->pos, 0); // load first world bkg
  loadBackground(bkg, bkg->pos, 1); // load second world bkg
  ImageRGBA_Ptr img( loadImage<ImageRGB>((sourcePath() + "/data/screens/mask.png").c_str())->cast<ImageRGBA>() );
  bkg->mask = Tex2DRGBA_Ptr( new Tex2DRGBA(img->pixels()) );
  return bkg;
}

void loadBackground(Background *bkg, v2i pos, int world) {
	if (bkg->screens.find(v3i(pos,world)) != bkg->screens.end()) {
		return;
	}
	bool failed = false;
	DrawImage* puzzle[3];
	for (int i = 0; i < 3; i++) {
		string postfix = world == 0 ? "" : "_b";
		string name = executablePath() + "/data/screens/" + to_string(pos[0]) + "_" + to_string(pos[1]) + "_" + to_string(i) + postfix + ".png";
		if (LibSL::System::File::exists(name.c_str())) {
			puzzle[i] = new DrawImage(name.c_str(), v3b(255, 0, 255));
		}
		else {
			failed = true;
		}
	}
	if (!failed) {
		bkg->screens[v3i(pos, world)] = vector<DrawImage*>();
		bkg->screens[v3i(pos, world)].push_back(puzzle[0]);
		bkg->screens[v3i(pos, world)].push_back(puzzle[1]);
		bkg->screens[v3i(pos, world)].push_back(puzzle[2]);
		loadBackground(bkg, pos + v2i(1, 0), world);
		loadBackground(bkg, pos + v2i(-1, 0), world);
		loadBackground(bkg, pos + v2i(0, 1), world);
		loadBackground(bkg, pos + v2i(0, -1), world);
	}
}

v4i loadLevelData(Background *bkg) {
	// define the dynamic body for the entire tilemap
	if (currentBody != NULL) {
		g_World->DestroyBody(currentBody);
	}
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(0.0f, 0.0f);
	currentBody = g_World->CreateBody(&bodyDef);

	//Load data files
	vector<string> postfix = { "_b", "_g" };
	v4i spawn;
	for (int i = 0; i < 2; i++) {
		int length;
		vector<int> sizex = vector<int>();
		vector<int> sizey = vector<int>();
		vector<float> angle = vector<float>();
		vector<int> ctrx = vector<int>();
		vector<int> ctry = vector<int>();
		fstream file;
		string currentLine;

		file.open(executablePath() + "/data/screens/" + to_string(bkg->pos[0]) + "_" + to_string(bkg->pos[1]) + postfix[i] + ".dat", fstream::in);

		//Read spawn points
		if (i == 0) {
			getline(file, currentLine);
			spawn[0] = stoi(currentLine);
			getline(file, currentLine);
			spawn[1] = stoi(currentLine);
		}
		else {
			getline(file, currentLine);
			spawn[2] = stoi(currentLine);
			getline(file, currentLine);
			spawn[3] = stoi(currentLine);
		}

		//Read number of boxes
		getline(file, currentLine);
		getline(file, currentLine);
		length = stoi(currentLine);

		for (int j = 0; j < length; j++) {
			getline(file, currentLine); // Separator line

			getline(file, currentLine);
			sizex.push_back(stoi(currentLine));
			getline(file, currentLine);
			sizey.push_back(stoi(currentLine));
			getline(file, currentLine);
			angle.push_back(stof(currentLine));
			getline(file, currentLine);
			ctrx.push_back(stoi(currentLine));
			getline(file, currentLine);
			ctry.push_back(stoi(currentLine));
		}

		for (int j = 0; j < length; j++) {
			// define a box shape.
			b2PolygonShape box;
			box.SetAsBox(
				in_meters(sizex[j] / 2), in_meters(sizey[j] / 2),  // size
				b2Vec2(in_meters(ctrx[j]), in_meters(ctry[j])), // center
				angle[j]);
			// define the dynamic body fixture.
			b2FixtureDef fixtureDef;
			fixtureDef.shape = &box;
			// set the box density to be zero, so it will be static.
			fixtureDef.density = 1.0f;
			// override the default friction.
			fixtureDef.friction = 0.6f;
			// how bouncy?
			fixtureDef.restitution = 0.1f;
			if (i == 0) {
				fixtureDef.userData = ((void*)100);
			}
			else {
				fixtureDef.userData = ((void*)200);
			}
			currentBody->CreateFixture(&fixtureDef);
		}
	}
	return spawn;
}

// ------------------------------------------------------------------

void background_draw(Background *bkg, time_t lastFrame, v2i playerpos)
{

	glPushAttrib(GL_ENABLE_BIT);
	g_Rt->clear();
	g_Rt->bind();
	glViewport(0, 0, g_Rt->w(), g_Rt->h());
	// draw second world
	background_draw(bkg,lastFrame, 1, true, playerpos );
	////////////////////
	g_Rt->unbind();

	// draw first world
	background_draw(bkg, lastFrame, 0, false, playerpos);
	////////////////////

	// composite both
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	Transform::ortho2D(LIBSL_PROJECTION_MATRIX, 0, 1, 0, 1);
	Transform::identity(LIBSL_MODELVIEW_MATRIX);
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,g_Rt->texture());
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(0, 0);
	glTexCoord2i(1, 0); glVertex2i(1, 0);
	glTexCoord2i(1, 1); glVertex2i(1, 1);
	glTexCoord2i(0, 1); glVertex2i(0, 1);
	glEnd();
	glPopAttrib();
}

// ------------------------------------------------------------------

void background_draw(Background *bkg, time_t lastFrame,int world,bool negative, v2i maskpos)
{
	if (bkg->moving == 0) {
		background_draw(bkg, v3i(bkg->pos, world), v2i(0, 0), negative, maskpos);
	}
	else if (bkg->moving == 1) {// 1=Right
		background_draw(bkg, v3i(bkg->oldPos,world), v2i(-(lastFrame - bkg->startTime) * bkg->screenw / ANIMATION_TIME, 0), negative, maskpos);
		background_draw(bkg, v3i(bkg->pos, world), v2i((bkg->screenw - (lastFrame - bkg->startTime) * bkg->screenw / ANIMATION_TIME), 0), negative, maskpos);
		if (lastFrame - bkg->startTime > ANIMATION_TIME) {
			bkg->moving = 0;
		}
	}
	else if (bkg->moving == 2) {//2=Left
		background_draw(bkg, v3i(bkg->oldPos, world), v2i((lastFrame - bkg->startTime) * bkg->screenw / ANIMATION_TIME, 0), negative, maskpos);
		background_draw(bkg, v3i(bkg->pos, world), v2i(-(bkg->screenw - (lastFrame - bkg->startTime) * bkg->screenw / ANIMATION_TIME), 0), negative, maskpos);
		if (lastFrame - bkg->startTime > ANIMATION_TIME) {
			bkg->moving = 0;
		}
	}
	else if (bkg->moving == 3) {//3=Up
		background_draw(bkg, v3i(bkg->oldPos, world), v2i(0, (lastFrame - bkg->startTime) * bkg->screenh / ANIMATION_TIME), negative, maskpos);
		background_draw(bkg, v3i(bkg->pos, world), v2i(0, -(bkg->screenh - (lastFrame - bkg->startTime) * bkg->screenh / ANIMATION_TIME)), negative, maskpos);
		if (lastFrame - bkg->startTime > ANIMATION_TIME) {
			bkg->moving = 0;
		}
	}
	else if (bkg->moving == 4) {//4=Down
		background_draw(bkg, v3i(bkg->oldPos, world), v2i(0, -(lastFrame - bkg->startTime) * bkg->screenh / ANIMATION_TIME), negative, maskpos);
		background_draw(bkg, v3i(bkg->pos, world), v2i(0, (bkg->screenh - (lastFrame - bkg->startTime) * bkg->screenh / ANIMATION_TIME)), negative, maskpos);
		if (lastFrame - bkg->startTime > ANIMATION_TIME) {
			bkg->moving = 0;
		}
	}
}

void background_draw(Background *bkg, v3i pos, v2i leftCorner, bool negative, v2i maskpos) {
	for (int i = 0; i < 3; i++) {
		if (bkg->screens.find(pos) != bkg->screens.end()) {
			bkg->screens.find(pos)->second[i]->drawMasked(leftCorner[0], leftCorner[1], bkg->mask, negative, maskpos);
		}
	}
}

bool nextLeftBackground(Background *bkg, time_t lastFrame) {
	bkg->oldPos = bkg->pos;
	bkg->pos[0]--;
	if (bkg->screens.find(v3i(bkg->pos,0)) == bkg->screens.end() || bkg->moving != 0) {
		bkg->pos[0]++;
		return false;
	}
	bkg->moving = 2;
	bkg->startTime = lastFrame;
	return true;
}

bool nextRightBackground(Background *bkg, time_t lastFrame) {
	bkg->oldPos = bkg->pos;
	bkg->pos[0]++;
	if (bkg->screens.find(v3i(bkg->pos,0)) == bkg->screens.end() || bkg->moving != 0) {
		bkg->pos[0]--;
		return false;
	}
	bkg->moving = 1;
	bkg->startTime = lastFrame;
	return true;
}

bool nextUpBackground(Background *bkg, time_t lastFrame) {
	bkg->oldPos = bkg->pos;
	bkg->pos[1]++;
	if (bkg->screens.find(v3i(bkg->pos,0)) == bkg->screens.end() || bkg->moving !=0) {
		bkg->pos[1]--;
		return false;
	}
	bkg->moving = 3;
	bkg->startTime = lastFrame;
	return true;
}

bool nextDownBackground(Background *bkg, time_t lastFrame) {
	bkg->oldPos = bkg->pos;
	bkg->pos[1]--;
	if (bkg->screens.find(v3i(bkg->pos,0)) == bkg->screens.end() || bkg->moving != 0) {
		bkg->pos[1]++;
		return false;
	}
	bkg->moving = 4;
	bkg->startTime = lastFrame;
	return true;
}

// ------------------------------------------------------------------
