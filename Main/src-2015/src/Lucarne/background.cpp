// ------------------------------------------------------------------

#include "common.h"
#include "drawimage.h"
#include "script.h"
#include "background.h"
#include "physics.h"
#include <fstream>

extern b2World *g_World;
b2Body *currentBody = NULL;

// ------------------------------------------------------------------

float ANIMATION_TIME = 3000.0f;

Background *background_init(int screenw,int screenh)
{
  Background *bkg = new Background;
  bkg->pos = v2i(0, 0);
  bkg->screenw = screenw;
  bkg->screenh = screenh;
  bkg->moving = 0;
  loadBackground(bkg, bkg->pos);
  return bkg;
}

void loadBackground(Background *bkg, v2i pos) {
	if (bkg->screens.find(pos) != bkg->screens.end()) {
		return;
	}
	bool failed = false;
	DrawImage* puzzle[3];
	for (int i = 0; i < 3; i++) {
		string name = executablePath() + "/data/screens/" + to_string(pos[0]) + "_" + to_string(pos[1]) + "_" + to_string(i) + ".png";
		if (LibSL::System::File::exists(name.c_str())) {
			puzzle[i] = new DrawImage(name.c_str(), v3b(255, 0, 255));
		}
		else {
			failed = true;
		}
	}
	if (!failed) {
		bkg->screens[pos] = vector<DrawImage*>();
		bkg->screens[pos].push_back(puzzle[0]);
		bkg->screens[pos].push_back(puzzle[1]);
		bkg->screens[pos].push_back(puzzle[2]);
		loadBackground(bkg, pos + v2i(1, 0));
		loadBackground(bkg, pos + v2i(-1, 0));
		loadBackground(bkg, pos + v2i(0, 1));
		loadBackground(bkg, pos + v2i(0, -1));
	}
}

void loadGround(v2i pos) {
	// define the dynamic body for the entire tilemap
	if (currentBody != NULL) {
		g_World->DestroyBody(currentBody);
	}
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(0.0f, 0.0f);
	currentBody = g_World->CreateBody(&bodyDef);

	//Load text file for ground
	int length;
	int sizey;
	vector<int> sizex = vector<int>();
	vector<float> angle = vector<float>();
	vector<int> ctrx = vector<int>();
	vector<int> ctry = vector<int>();
	fstream file;
	string currentLine;

	file.open(sourcePath() + "/data/scripts/" + to_string(pos[0]) + "_" + to_string(pos[1]) + "_0_sol.txt", fstream::in);


	getline(file, currentLine);
	length = stof(currentLine);
	getline(file, currentLine);
	sizey = stof(currentLine);

	for (int i = 0; i < length; i++) {
		getline(file, currentLine);
		sizex.push_back(stoi(currentLine));
		getline(file, currentLine);
		angle.push_back(stof(currentLine));
		getline(file, currentLine);
		ctrx.push_back(stoi(currentLine));
		getline(file, currentLine);
		ctry.push_back(stoi(currentLine));
	}

	for (int i = 0; i < length; i++) {
		// define a box shape.
		b2PolygonShape box;
		box.SetAsBox(
			in_meters(sizex[i] / 2), in_meters(sizey / 2),  // size
			b2Vec2(in_meters(ctrx[i]), in_meters(ctry[i])), // center
			angle[i]);
		// define the dynamic body fixture.
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &box;
		// set the box density to be zero, so it will be static.
		fixtureDef.density = 1.0f;
		// override the default friction.
		fixtureDef.friction = 0.6f;
		// how bouncy?
		fixtureDef.restitution = 0.1f;
		// user data; set to NULL to distinguish from entities
		fixtureDef.userData = (void*)NULL;
		// add the shape to the body.
		currentBody->CreateFixture(&fixtureDef);
	}
}

// ------------------------------------------------------------------

void background_draw(Background *bkg, time_t lastFrame)
{
	if (bkg->moving == 0) {
		background_draw(bkg, bkg->pos, v2i(0, 0));
	}
	else if (bkg->moving == 1) {// 1=Right
		background_draw(bkg, bkg->oldPos, v2i(-(lastFrame - bkg->startTime) * bkg->screenw / ANIMATION_TIME, 0));
		background_draw(bkg, bkg->pos, v2i((bkg->screenw - (lastFrame - bkg->startTime) * bkg->screenw / ANIMATION_TIME), 0));
		if (lastFrame - bkg->startTime > ANIMATION_TIME) {
			bkg->moving = 0;
		}
	}
	else if (bkg->moving == 2) {//2=Left
		background_draw(bkg, bkg->oldPos, v2i((lastFrame - bkg->startTime) * bkg->screenw / ANIMATION_TIME, 0));
		background_draw(bkg, bkg->pos, v2i(-(bkg->screenw - (lastFrame - bkg->startTime) * bkg->screenw / ANIMATION_TIME), 0));
		if (lastFrame - bkg->startTime > ANIMATION_TIME) {
			bkg->moving = 0;
		}
	}
	else if (bkg->moving == 3) {//3=Up
		background_draw(bkg, bkg->oldPos, v2i(0, (lastFrame - bkg->startTime) * bkg->screenh / ANIMATION_TIME));
		background_draw(bkg, bkg->pos, v2i(0, -(bkg->screenh - (lastFrame - bkg->startTime) * bkg->screenh / ANIMATION_TIME)));
		if (lastFrame - bkg->startTime > ANIMATION_TIME) {
			bkg->moving = 0;
		}
	}
	else if (bkg->moving == 4) {//4=Down
		background_draw(bkg, bkg->oldPos, v2i(0, -(lastFrame - bkg->startTime) * bkg->screenh / ANIMATION_TIME));
		background_draw(bkg, bkg->pos, v2i(0, (bkg->screenh - (lastFrame - bkg->startTime) * bkg->screenh / ANIMATION_TIME)));
		if (lastFrame - bkg->startTime > ANIMATION_TIME) {
			bkg->moving = 0;
		}
	}
}

void background_draw(Background *bkg, v2i pos, v2i leftCorner) {
	for (int i = 0; i < 3; i++) {
		bkg->screens.find(pos)->second[i]->draw(leftCorner[0], leftCorner[1]);
	}
}

bool nextLeftBackground(Background *bkg, time_t lastFrame) {
	bkg->oldPos = bkg->pos;
	bkg->pos[0]--;
	if (bkg->screens.find(bkg->pos) == bkg->screens.end() || bkg->moving != 0) {
		bkg->pos[0]++;
		return false;
	}
	bkg->moving = 2;
	bkg->startTime = lastFrame;
	loadGround(bkg->pos);
	return true;
}

bool nextRightBackground(Background *bkg, time_t lastFrame) {
	bkg->oldPos = bkg->pos;
	bkg->pos[0]++;
	if (bkg->screens.find(bkg->pos) == bkg->screens.end() || bkg->moving != 0) {
		bkg->pos[0]--;
		return false;
	}
	bkg->moving = 1;
	bkg->startTime = lastFrame;
	loadGround(bkg->pos);
	return true;
}

bool nextUpBackground(Background *bkg, time_t lastFrame) {
	bkg->oldPos = bkg->pos;
	bkg->pos[1]++;
	if (bkg->screens.find(bkg->pos) == bkg->screens.end() || bkg->moving !=0) {
		bkg->pos[1]--;
		return false;
	}
	bkg->moving = 3;
	bkg->startTime = lastFrame;
	loadGround(bkg->pos);
	return true;
}

bool nextDownBackground(Background *bkg, time_t lastFrame) {
	bkg->oldPos = bkg->pos;
	bkg->pos[1]--;
	if (bkg->screens.find(bkg->pos) == bkg->screens.end() || bkg->moving != 0) {
		bkg->pos[1]++;
		return false;
	}
	bkg->moving = 4;
	bkg->startTime = lastFrame;
	loadGround(bkg->pos);
	return true;
}

// ------------------------------------------------------------------
