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
	map<v3i, vector<DrawImage*>> screens;
	Tex2DRGBA_Ptr mask;

  v2i pos;
  v2i oldPos;
  
  int                     screenw;
  int                     screenh;
  int moving;
  time_t startTime;
} Background;

// ------------------------------------------------------------------

v4i loadLevelData(Background *bkg);
Background *background_init(int w, int h);
void background_draw(Background *bkg, time_t lastFrame,v2i playerpos);
void        background_draw(Background*, time_t lastFrame, int world, bool negative, v2i maskpos);
void background_draw(Background *bkg, v3i pos, v2i leftCorner, bool negative, v2i maskpos);
bool nextLeftBackground(Background *bkg, time_t lastFrame);
bool nextRightBackground(Background *bkg, time_t lastFrame);
bool nextUpBackground(Background *bkg, time_t lastFrame);
bool nextDownBackground(Background *bkg, time_t lastFrame);
void loadBackground(Background *bkg, v2i pos,int world);

// ------------------------------------------------------------------
