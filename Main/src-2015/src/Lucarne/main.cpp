// Sylvain.Lefebvre@inria.fr  2015-03-10
// ------------------------------------------------------------------

#include "common.h"
#include "drawimage.h"

LIBSL_WIN32_FIX;

// ------------------------------------------------------------------

#include "tilemap.h"
#include "entity.h"
#include "background.h"
#include "physics.h"

// ------------------------------------------------------------------

// Constants
int    c_ScreenW = 1024;
int    c_ScreenH = 576;

// ------------------------------------------------------------------
enum GameState {
	Uninitialized, ShowingSplash, ShowingMenu, Playing, End
};
GameState       g_GameState = Uninitialized;
time_t          g_LastFrame = 0;

bool            g_Keys[256];

Tilemap        *g_Tilemap = NULL;
Background     *g_Bkg = NULL;

vector<Entity*> g_Entities;
Entity*         g_Player = NULL;

int             numFootContacts1 = 0;
int             numLeftContacts1 = 0;
int             numRightContacts1 = 0;
int             numFootContacts2 = 0;
int             numLeftContacts2 = 0;
int             numRightContacts2 = 0;

// ------------------------------------------------------------------

// 'mainKeyPressed' is called everytime a key is pressed
void mainKeyPressed(uchar key)
{
	if (g_GameState == ShowingSplash){
		g_GameState = ShowingMenu;
	}
	else if (g_GameState == ShowingMenu){
		std::cerr << Console::red << (int)key << Console::gray << std::endl;
		if (key == (int) 'p'){
			g_GameState = Playing;
		}
		else if (key == (char)'e'){
			SimpleUI::shutdown();
			exit(0);
		}
	}
	else{
		g_Keys[key] = true;

		if (key == ' ') {
			Entity *c = entity_create("coin0", 1, "coin.lua", v2i(0, 0));
			entity_set_pos(c, v2f(256 + ((rand() % 128) - 64), 350));
			g_Entities.push_back(c);
		}
	}

}

// ------------------------------------------------------------------

// 'mainKeyUnpressed' is called everytime a key is released
void mainKeyUnpressed(uchar key)
{
	g_Keys[key] = false;
}


//----------------------------------------------------------------
// 'mainRender' is called everytime the screen is drawn

void mainRender()
{
	if (g_GameState == Uninitialized){
		g_GameState = ShowingSplash;
	}
	else if (g_GameState == ShowingSplash){
		clearScreen();
		string src = sourcePath() + "/data/General/SplashScreen.png";
		DrawImage* imag = new DrawImage(src.c_str(), v3b(255, 0, 255));
		imag->draw(0, 0);
	}
	else if (g_GameState == ShowingMenu){
		clearScreen();
		string src = sourcePath() + "/data/General/Mainmenu.png";
		DrawImage* imag = new DrawImage(src.c_str(), v3b(255, 0, 255));
		imag->draw(0, 0);
	}

	else if (g_GameState == Playing){
		//// Compute elapsed time
		time_t now = milliseconds();
		time_t el = now - g_LastFrame;
		if (el > 20) {
			g_LastFrame = now;
		}

		//// Physics
		if (g_Bkg->moving == 0){
			phy_step();

			//// Logic

			// -> step all entities
			for (int a = 0; a < (int)g_Entities.size(); a++) {
				entity_step(g_Entities[a], el);
			}

			//Background & border interaction with the player
			if (entity_get_pos(g_Player)[0] >= c_ScreenW) { //Right
				if (nextRightBackground(g_Bkg, g_LastFrame) == true) {
					entity_set_pos(g_Player, v2f(0, entity_get_pos(g_Player)[1]));
				}
				else {
					entity_set_pos(g_Player, v2f(c_ScreenW, entity_get_pos(g_Player)[1]));
				}
			}
			else if (entity_get_pos(g_Player)[0] <= 0) { //Left
				if (nextLeftBackground(g_Bkg, g_LastFrame) == true) {
					entity_set_pos(g_Player, v2f(c_ScreenW, entity_get_pos(g_Player)[1]));
				}
				else {
					entity_set_pos(g_Player, v2f(0, entity_get_pos(g_Player)[1]));
				}
			}
			else if (entity_get_pos(g_Player)[1] <= 0) { //Down
				if (nextDownBackground(g_Bkg, g_LastFrame) == true) {
					entity_set_pos(g_Player, v2f(entity_get_pos(g_Player)[0], c_ScreenH));
				}
				else {
					entity_set_pos(g_Player, v2f(entity_get_pos(g_Player)[0], 0));
				}
			}
			else if (entity_get_pos(g_Player)[1] >= c_ScreenH) { //Up
				if (nextUpBackground(g_Bkg, g_LastFrame) == true) {
					entity_set_pos(g_Player, v2f(entity_get_pos(g_Player)[0], 0));
				}
				else {
					entity_set_pos(g_Player, v2f(entity_get_pos(g_Player)[0], c_ScreenH));
				}
			}
		}

		//// Display

		clearScreen();
		// -> draw background
		background_draw(g_Bkg, g_LastFrame);
		// -> draw all entities
		for (int a = 0; a < (int)g_Entities.size(); a++) {
			entity_draw(g_Entities[a]);
		}
		// -> draw physics debug layer
		phy_debug_draw();
	}
	else if (g_GameState == End){
		// print Game over!
	}
	return;

}


// ------------------------------------------------------------------

// 'main' is the starting point of the application
int main(int argc, const char **argv)
{
	try { // error handling

		// opens a window
		SimpleUI::init(c_ScreenW, c_ScreenH, "Tilemap");
		// set the render function to be 'mainRender' defined above
		SimpleUI::onRender = mainRender;
		// set the keyboard function
		SimpleUI::onKeyPressed = mainKeyPressed;
		SimpleUI::onKeyUnpressed = mainKeyUnpressed;

		// init drawimage library
		drawimage_init(c_ScreenW, c_ScreenH);

		// keys
		for (int i = 0; i < 256; i++) {
			g_Keys[i] = false;
		}

		///// Level creation

		// create background
		g_Bkg = background_init(c_ScreenW, c_ScreenH);

		// init physics
		phy_init();

		// bind tilemap to physics
		loadGround(g_Bkg->pos);

		// load a simple entity
		{
			Entity *c = entity_create("coin0", 0, "coin.lua", v2i(0, 0));
			g_Entities.push_back(c);
			entity_set_pos(c, v2f(32, 32));
		} {
			Entity *c = entity_create("coin1", 0, "coin.lua", v2i(0, 0));
			g_Entities.push_back(c);
			entity_set_pos(c, v2f(96, 32));
		} {
			Entity *c = entity_create("coin2", 0, "coin.lua", v2i(0, 0));
			g_Entities.push_back(c);
			entity_set_pos(c, v2f(128, 32));
		} {
			Entity *c = entity_create("player", 0, "player.lua", v2i(0, 0));
			entity_set_pos(c, v2f(196, 256));
			g_Player = c;
			g_Entities.push_back(c);
		}

		g_LastFrame = milliseconds();

		// enter the main loop
		SimpleUI::loop();

		// terminate physics
		phy_terminate();
		// terminate drawimage
		drawimage_terminate();

		// close the window
		SimpleUI::shutdown();

	}
	catch (Fatal& f) { // error handling
		std::cerr << Console::red << f.message() << Console::gray << std::endl;
	}

	return 0;
}

// ------------------------------------------------------------------

