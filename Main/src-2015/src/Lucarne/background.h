// Sylvain.Lefebvre@inria.fr  2015-03-10
#pragma once

// ------------------------------------------------------------------

#include<string>
#include <vector>

using namespace std;

// ------------------------------------------------------------------

#include "drawimage.h"

// ------------------------------------------------------------------

typedef struct
{
	map<v2i, vector<DrawImage*>> screens;

  v2i pos;
  v2i oldPos;
  
  int                     screenw;
  int                     screenh;
  int moving;
  time_t startTime;
} Background;

// ------------------------------------------------------------------

void loadGround(v2i pos);
Background *background_init(int w, int h);
void        background_draw(Background*, time_t lastFrame);
void background_draw(Background *bkg, v2i pos, v2i leftCorner);
bool nextLeftBackground(Background *bkg, time_t lastFrame);
bool nextRightBackground(Background *bkg, time_t lastFrame);
bool nextUpBackground(Background *bkg, time_t lastFrame);
bool nextDownBackground(Background *bkg, time_t lastFrame);
void loadBackground(Background *bkg, v2i pos);

// ------------------------------------------------------------------
