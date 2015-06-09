// ------------------------------------------------------------------

#include "common.h"
#include "drawimage.h"
#include "script.h"
#include "entity.h"

// The World (in physics.cpp)
extern b2World *g_World;

// get access to foot contact from main.cpp
extern int             numFootContacts1;
extern int             numLeftContacts1;
extern int             numRightContacts1;
extern int             numFootContacts2;
extern int             numLeftContacts2;
extern int             numRightContacts2;


// ------------------------------------------------------------------

// get access to keys table from main.cpp
extern bool g_Keys[256];

// ------------------------------------------------------------------

const int g_FrameDelay = 100; // ms between frames

Entity *g_Current = NULL;

map<string, DrawImage*> g_Animations;


// ------------------------------------------------------------------

DrawImage *loadAnimation(string filename)
{
	try {
		if (g_Animations.find(filename) == g_Animations.end()) {
			DrawImage *img = new DrawImage((executablePath() + "/data/sprites/" + filename).c_str(), v3b(255, 0, 255));
			g_Animations[filename] = img;
			return img;
		}
		else {
			return g_Animations[filename];
		}
	}
	catch (Fatal& f) { // error handling
		std::cerr << Console::red << f.message() << Console::gray << std::endl;
	}
	return NULL;
}

// ------------------------------------------------------------------

void lua_addanim(string filename, int framespacing)
{
	sl_assert(g_Current != NULL);
	SpriteAnim *s = new SpriteAnim;
	s->animframes = loadAnimation(filename);
	s->framespacing = framespacing;
	s->numframes = (int)ceil(s->animframes->w() / framespacing);
	g_Current->anims[filename] = s;
}

// ------------------------------------------------------------------

void lua_playanim(string filename, bool looping)
{
	sl_assert(g_Current != NULL);
	if (g_Current->anims.find(filename) == g_Current->anims.end()) {
		cerr << Console::red << "cannot find anim '" << filename << "'" << Console::gray << endl;
		return;
	}
	g_Current->currentAnim = filename;
	g_Current->currentFrame = 0;
	g_Current->lastAnimUpdate = milliseconds();
	g_Current->animIsPlaying = true;
	g_Current->animIsALoop = looping;
}

// ------------------------------------------------------------------

void lua_stopanim()
{
	sl_assert(g_Current != NULL);
	g_Current->animIsPlaying = false;
}

// ------------------------------------------------------------------

void lua_print(string str)
{
	cerr << Console::white << str << Console::gray << endl;
}

// ------------------------------------------------------------------

void lua_set_velocity_x(float v)
{
	sl_assert(g_Current != NULL);
	b2Vec2 vel = g_Current->body->GetLinearVelocity();
	g_Current->body->SetLinearVelocity(b2Vec2(v, vel.y));
}

// ------------------------------------------------------------------

void lua_set_velocity_y(float v)
{
	sl_assert(g_Current != NULL);
	b2Vec2 vel = g_Current->body->GetLinearVelocity();
	g_Current->body->SetLinearVelocity(b2Vec2(vel.x, v));
}


void lua_set_force(float ix, float iy)
{
	sl_assert(g_Current != NULL);
	g_Current->body->ApplyForce(g_Current->body->GetMass() * b2Vec2(ix, iy), g_Current->body->GetWorldCenter());
}
// ------------------------------------------------------------------

void lua_set_impulse(float ix, float iy)
{
	sl_assert(g_Current != NULL);
	g_Current->body->ApplyLinearImpulse(g_Current->body->GetMass()* b2Vec2(ix, iy), g_Current->body->GetWorldCenter());
}

void lua_set_jump(float ix_foot, float iy_foot, float ix_left, float iy_left, float ix_right, float iy_right){

	static t_time tmJump = milliseconds();
	t_time now = milliseconds();
	if (now - tmJump > 200) {
		if ((g_Current->name == "player"  && numLeftContacts1 > 0 && numFootContacts1 == 0) || (g_Current->name == "player2" && numLeftContacts2 > 0 && numFootContacts2 == 0))
		{
			lua_set_velocity_x(ix_left);
			lua_set_velocity_y(iy_left);

		}
		else if ((g_Current->name == "player" && numRightContacts1 > 0 && numFootContacts1 == 0) || (g_Current->name == "player2" && numRightContacts2 > 0 && numFootContacts2 == 0))
		{
			lua_set_velocity_x(ix_right);
			lua_set_velocity_y(iy_right);
		}

		else if ((g_Current->name == "player"  && numFootContacts1 > 0) || (g_Current->name == "player2" && numFootContacts2 > 0))
		{
			lua_set_velocity_x(ix_foot);
			lua_set_velocity_y(iy_foot);

		}
		tmJump = now;
	}
}

void lua_set_walk(float ix_vel, float ix_jmp){
	if ((g_Current->name == "player" && numFootContacts1 > 0) || (g_Current->name == "player2" &&  numFootContacts2 > 0)){
		lua_set_velocity_x(ix_vel);
	}

	else if ((g_Current->name == "player" && (numRightContacts1 > 0 && ix_jmp >= 0) && numFootContacts1 == 0) || (g_Current->name == "player2" && (numRightContacts2 > 0 && ix_jmp >= 0) && numFootContacts2 == 0)){
		lua_set_velocity_x(0);
		lua_set_velocity_y(-1);

	}

	else if ((g_Current->name == "player" && (numLeftContacts1 > 0 && ix_jmp <= 0) && numFootContacts1 == 0) || (g_Current->name == "player2" && (numLeftContacts2 > 0 && ix_jmp <= 0) && numFootContacts2 == 0)){
		lua_set_velocity_x(0);
		lua_set_velocity_y(-1);
	}

	else{
		b2Vec2 vel = g_Current->body->GetLinearVelocity();
		static t_time tmJump = milliseconds();
		t_time now = milliseconds();
		if (now - tmJump > 300) {
			lua_set_impulse(ix_jmp / 100, 0);
			tmJump = now;
		}

		if (vel.x > abs(ix_vel)){
			lua_set_velocity_x(abs(ix_vel));
		}
		else if (vel.x < -abs(ix_vel)){
			lua_set_velocity_x(-abs(ix_vel));
		}

	}

}





// ------------------------------------------------------------------

void begin_script_call(Entity *e)
{
	g_Current = e;
	for (int i = 'a'; i <= 'z'; i++) {
		string name = "Key__";
		name[4] = (char)i;
		globals(e->script->lua)[name] = g_Keys[i];
	}
	globals(e->script->lua)["name"] = e->name;
	v2f pos = entity_get_pos(e);
	globals(e->script->lua)["pos_x"] = pos[0];
	globals(e->script->lua)["pos_y"] = pos[1];
	globals(e->script->lua)["killed"] = e->killed;

}

// ------------------------------------------------------------------

void end_script_call(Entity *e)
{
	// feedback globals
	//e->pos[0] = luabind::object_cast<float>(globals(e->script->lua)["pos_x"]);
	//e->pos[1] = luabind::object_cast<float>(globals(e->script->lua)["pos_y"]);
	e->killed = luabind::object_cast<bool>(globals(e->script->lua)["killed"]);
	g_Current = NULL;
}

// ------------------------------------------------------------------

Entity *entity_create(string name, string script, v2i pos)
{
	Entity *e = new Entity;

	e->name = name;
	e->currentAnim = "";
	e->currentFrame = 0;
	e->lastAnimUpdate = 0;
	e->pos = pos;
	e->killed = false;
	e->animIsPlaying = false;

	/// scripting
	e->script = script_create();
	// install our own functions into the script
	{
		module(e->script->lua)
			[
				def("addanim", &lua_addanim),
				def("playanim", &lua_playanim),
				def("print", &lua_print),
				def("stopanim", &lua_stopanim),
				def("set_velocity_x", &lua_set_velocity_x),
				def("set_velocity_y", &lua_set_velocity_y),
				def("set_impulse", &lua_set_impulse),
				def("set_force", &lua_set_force),
				def("set_jump", &lua_set_jump),
				def("set_walk", &lua_set_walk)
			];
	}
	// load the script (global space gets executed)
	g_Current = e;
	script_load(e->script, executablePath() + "/data/scripts/" + script);
	g_Current = NULL;

	// read physics properties
	float ctrx = in_meters(luabind::object_cast<float>(globals(e->script->lua)["physics_center_x"]));
	float ctry = in_meters(luabind::object_cast<float>(globals(e->script->lua)["physics_center_y"]));
	float szx = in_meters(luabind::object_cast<float>(globals(e->script->lua)["physics_size_x"]));
	float szy = in_meters(luabind::object_cast<float>(globals(e->script->lua)["physics_size_y"]));
	bool  can_sleep = luabind::object_cast<bool>(globals(e->script->lua)["physics_can_sleep"]);
	bool  can_rotate = luabind::object_cast<bool>(globals(e->script->lua)["physics_rotation"]);

	/// physics
	// define the dynamic body

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 0.0f);
	e->body = g_World->CreateBody(&bodyDef);
	e->body->SetSleepingAllowed(can_sleep);
	e->body->SetFixedRotation(!can_rotate);


	// setup damping
	e->body->SetLinearDamping(0.0f);
	//e->body->SetAngularDamping(0.01f);
	// define a box shape for our dynamic body.
	b2PolygonShape box;
	box.SetAsBox(szx, szy, b2Vec2(ctrx, ctry), 0.0f);

	// define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &box;

	// set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// override the default friction.
	fixtureDef.friction = 0.6f;

	// how bouncy?
	fixtureDef.restitution = 0.0f;

	// user data (pointer to entity being created)
	fixtureDef.userData = (void*)(e);

	// add the shape to the body.
	e->body->CreateFixture(&fixtureDef);

	if (e->name == "player"){

		fixtureDef.density = 0.0f;
		fixtureDef.friction = 0.0f;
		fixtureDef.restitution = 0.0f;
		//add foot sensor fixture
		box.SetAsBox(szx - in_meters(2), in_meters(2), b2Vec2(ctrx, ctry - szy - in_meters(2)), in_meters(0));
		fixtureDef.isSensor = true;
		b2Fixture* footSensorFixture = e->body->CreateFixture(&fixtureDef);
		footSensorFixture->SetUserData((void*)1);


		box.SetAsBox(in_meters(2), szy - in_meters(3), b2Vec2(ctrx - szx - in_meters(2), ctry), in_meters(0));
		fixtureDef.isSensor = true;
		b2Fixture* leftSensorFixture = e->body->CreateFixture(&fixtureDef);
		leftSensorFixture->SetUserData((void*)2);


		box.SetAsBox(szx - in_meters(3), in_meters(2), b2Vec2(ctrx, ctry + szy + in_meters(2)), in_meters(0));
		fixtureDef.isSensor = true;
		b2Fixture* headSensorFixture = e->body->CreateFixture(&fixtureDef);
		headSensorFixture->SetUserData((void*)3);


		box.SetAsBox(in_meters(2), szy - in_meters(3), b2Vec2(ctrx + szx + in_meters(2), ctry), in_meters(0));
		fixtureDef.isSensor = true;
		b2Fixture* rightSensorFixture = e->body->CreateFixture(&fixtureDef);
		rightSensorFixture->SetUserData((void*)4);

	}


	if (e->name == "player2"){

		fixtureDef.density = 0.0f;
		fixtureDef.friction = 0.0f;
		fixtureDef.restitution = 0.0f;
		//add foot sensor fixture
		box.SetAsBox(szx - in_meters(2), in_meters(2), b2Vec2(ctrx, ctry - szy - in_meters(2)), in_meters(0));
		fixtureDef.isSensor = true;
		b2Fixture* footSensorFixture = e->body->CreateFixture(&fixtureDef);
		footSensorFixture->SetUserData((void*)5);


		box.SetAsBox(in_meters(2), szy - in_meters(3), b2Vec2(ctrx - szx - in_meters(2), ctry), in_meters(0));
		fixtureDef.isSensor = true;
		b2Fixture* leftSensorFixture = e->body->CreateFixture(&fixtureDef);
		leftSensorFixture->SetUserData((void*)6);


		box.SetAsBox(szx - in_meters(3), in_meters(2), b2Vec2(ctrx, ctry + szy + in_meters(2)), in_meters(0));
		fixtureDef.isSensor = true;
		b2Fixture* headSensorFixture = e->body->CreateFixture(&fixtureDef);
		headSensorFixture->SetUserData((void*)7);


		box.SetAsBox(in_meters(2), szy - in_meters(3), b2Vec2(ctrx + szx + in_meters(2), ctry), in_meters(0));
		fixtureDef.isSensor = true;
		b2Fixture* rightSensorFixture = e->body->CreateFixture(&fixtureDef);
		rightSensorFixture->SetUserData((void*)8);

	}

	return e;
}

// ------------------------------------------------------------------

v2f     entity_get_pos(Entity *e)
{
	b2Vec2 position = e->body->GetTransform().position;
	return v2f(in_px(position.x), in_px(position.y));
}

// ------------------------------------------------------------------

float   entity_get_angle(Entity *e)
{
	return e->body->GetTransform().R.GetAngle();
}

// ------------------------------------------------------------------

void    entity_set_pos(Entity *e, v2f p)
{
	e->body->SetTransform(b2Vec2(in_meters(p[0]), in_meters(p[1])), 0.0f);
	e->initialCoordinates = p;
}

// ------------------------------------------------------------------

void    entity_draw(Entity *e)
{
	if (e->killed ) {
		return;
	}
	if (e->anims.find(e->currentAnim) == e->anims.end()) {
		// error: the selected animation is unkown
		return;
	}
	// draw on screen
	int fspc = e->anims[e->currentAnim]->framespacing;
	v2i sz = v2i(fspc, e->anims[e->currentAnim]->animframes->h());
	int frame = min(e->currentFrame, e->anims[e->currentAnim]->numframes - 1);
	v2f pos = entity_get_pos(e);
	e->anims[e->currentAnim]->animframes->drawSub(
		(v2i(pos) - sz / 2) /*centered to match physics*/, sz,
		v2i(frame * fspc, 0), sz
		);
	// next frame
	if (e->animIsPlaying) {
		time_t now = milliseconds();
		if (now - e->lastAnimUpdate > g_FrameDelay) {
			if (e->animIsALoop) {
				e->currentFrame = (e->currentFrame + 1) % e->anims[e->currentAnim]->numframes;
			}
			else {
				if (e->currentFrame == e->anims[e->currentAnim]->numframes - 1) {
					// call script event 
					begin_script_call(e);
					try {
						call_function<void>(e->script->lua, "onAnimEnd");
					}
					catch (luabind::error& e) {
						cerr << Console::red << e.what() << ' ' << Console::gray << endl;
					}
					end_script_call(e);
					// increment to number of frame
					e->currentFrame++;
				}
				else if (e->currentFrame < e->anims[e->currentAnim]->numframes) {
					e->currentFrame++;
				}
			}
			e->lastAnimUpdate = now;
		}
	}
}

// ------------------------------------------------------------------

void    entity_step(Entity *e, time_t elapsed)
{
	if (e->killed) {
		// does the body still exist?
		if (e->body != NULL) {
			// remove from simulation!
			g_World->DestroyBody(e->body);
			e->body = NULL;
		}
		return;
	}
	g_Current = e;

	// setup global variables in script
	globals(e->script->lua)["elapsed"] = (int)elapsed;
	// call stepping function from script
	begin_script_call(e);
	try {
		call_function<void>(e->script->lua, "step");
	}
	catch (luabind::error& e) {
		cerr << Console::red << e.what() << ' ' << Console::gray << endl;
	}
	end_script_call(e);
}

// ------------------------------------------------------------------

void    entity_contact(Entity *e, Entity *with)
{
	// call stepping function from script
	
	begin_script_call(e);
	try {
		call_function<void>(e->script->lua, "contact", with->name);
		if (with->name == "player"){
			e->killed = true;
		}
	}
	catch (luabind::error& e) {
		cerr << Console::red << e.what() << ' ' << Console::gray << endl;
	}
	end_script_call(e);
}

// ------------------------------------------------------------------

AAB<2>  entity_bbox(Entity *e)
{
	AAB<2> bx;
	v2f sz = v2f(e->anims[e->currentAnim]->framespacing, e->anims[e->currentAnim]->animframes->h());
	v2f pos = entity_get_pos(e);
	bx.addPoint(pos - sz / 2.0f);
	bx.addPoint(pos + sz / 2.0f);
	return bx;
}

// -----------------------------------------------------------------
