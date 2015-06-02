// Sylvain.Lefebvre@inria.fr  2015-03-24
#pragma once

// ------------------------------------------------------------------

#include<string>

using namespace std;

// ------------------------------------------------------------------

#include "drawimage.h"
#include "script.h"
#include "physics.h"

// ------------------------------------------------------------------

typedef struct {
	DrawImage *animframes;
	int        framespacing;
	int        numframes;
} SpriteAnim;


struct bodyUserData {
	int entityType;
	b2Fixture* footSensorFixture;
	string name;
};
// ------------------------------------------------------------------

typedef struct
{
	string                   name;
	map<string, SpriteAnim*> anims;

	string                   currentAnim;
	int                      currentFrame;
	time_t                   lastAnimUpdate;
	bool                     animIsPlaying;
	bool                     animIsALoop;

	// v2f                      pos; ==> this is now in the physics body
	bool                     killingContact;
	int                      killer;
	int                      life;
	int                      score;
	v2f                      initialCoordinates;
	v2i                      pos;

	Script                  *script;

	b2Body                  *body;

	b2Fixture* footSensorFixture;

	int numFootContacts;

} Entity;

// ------------------------------------------------------------------

Entity *entity_create(string fname, int killer, string script, v2i pos);
void    entity_draw(Entity *e);
void    entity_step(Entity *e, time_t elapsed);
void    entity_contact(Entity *e, Entity *with);
AAB<2>  entity_bbox(Entity *e);

v2f     entity_get_pos(Entity *e);
float   entity_get_angle(Entity *e);
void    entity_set_pos(Entity *e, v2f p);

// ------------------------------------------------------------------