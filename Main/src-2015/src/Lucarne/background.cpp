// ------------------------------------------------------------------

#include "common.h"
#include "drawimage.h"
#include "script.h"
#include "background.h"

// ------------------------------------------------------------------

Background *background_init(int screenw,int screenh)
{
  Background *bkg = new Background;
  bkg->pos = v2i(0, 0);
  bkg->screenw = screenw;
  bkg->screenh = screenh;
  return bkg;
}

// ------------------------------------------------------------------

void background_draw(Background *bkg)
{
	for (int i = 0; i < 3; i++) {
		bkg->screens[i]->draw(0, 0);
	}
}

bool nextLeftBackground(Background *bkg) {
	bkg->pos[0]--;
	if (loadBackground(bkg) == false) {
		bkg->pos[0]++;
		return false;
	}
	return true;
}

bool nextRightBackground(Background *bkg) {
	bkg->pos[0]++;
	if (loadBackground(bkg) == false) {
		bkg->pos[0]--;
		return false;
	}
	return true;
}

bool nextUpBackground(Background *bkg) {
	bkg->pos[1]++;
	if (loadBackground(bkg) == false) {
		bkg->pos[1]--;
		return false;
	}
	return true;
}

bool nextDownBackground(Background *bkg) {
	bkg->pos[1]--;
	if (loadBackground(bkg) == false) {
		bkg->pos[1]++;
		return false;
	}
	return true;
}

bool loadBackground(Background *bkg) {
	for (int i = 0; i < 3; i++) {
		string name = sourcePath() + "/data/screens/" + to_string(bkg->pos[0]) + "_" + to_string(bkg->pos[1]) + "_" + to_string(i) + ".png";
		if (LibSL::System::File::exists(name.c_str())) {
			bkg->screens[i] = new DrawImage(name.c_str(), v3b(255, 0, 255));
		}
		else {
			return false;
		}
	}
	return true;
}

// ------------------------------------------------------------------
