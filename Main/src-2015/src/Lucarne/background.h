// Sylvain.Lefebvre@inria.fr  2015-03-10
#pragma once

// ------------------------------------------------------------------

#include<string>

using namespace std;

// ------------------------------------------------------------------

#include "drawimage.h"

// ------------------------------------------------------------------

typedef struct
{
  DrawImage* screens[3];

  v2i pos;
  
  int                     screenw;
  int                     screenh;
} Background;

// ------------------------------------------------------------------

Background *background_init(int w, int h);
void        background_draw(Background*);
bool nextLeftBackground(Background *bkg);
bool nextRightBackground(Background *bkg);
bool nextUpBackground(Background *bkg);
bool nextDownBackground(Background *bkg);
bool loadBackground(Background *bkg);

// ------------------------------------------------------------------
