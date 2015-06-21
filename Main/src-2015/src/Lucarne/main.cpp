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
//#include "Sound.h"

#include <time.h>


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
Entity*         g_Boy = NULL;
Entity*         g_Girl = NULL;

int             numFootContacts1 = 0;
int             numLeftContacts1 = 0;
int             numRightContacts1 = 0;
int             numFootContacts2 = 0;
int             numLeftContacts2 = 0;
int             numRightContacts2 = 0;

bool music_playing = false;

// ------------------------------------------------------------------

// 'mainKeyPressed' is called everytime a key is pressed
void mainKeyPressed(uchar key)
{
	if (g_GameState == ShowingSplash){
		g_GameState = ShowingMenu;
	}
	else if (g_GameState == ShowingMenu){
		if (key == 'p'){
			g_GameState = Playing;
			int i = rand() % 4 + 1;
			stringstream ss;
			ss << "theme" << i << ".wav";
			string s = ss.str();
			std::cerr << s;
			//play_sound(s);
		}
		else if (key == 'e'){
			SimpleUI::shutdown();
			exit(0);
		}
	}
	else{
		if (key == LIBSL_KEY_ESC){
			g_GameState = End;
		}
		g_Keys[key] = true;
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
		string src = executablePath() + "/data/general/SplashScreen.png";
		DrawImage* imag = new DrawImage(src.c_str(), v3b(255, 0, 255));
		imag->draw(0, 0);
	}
	else if (g_GameState == ShowingMenu){
		clearScreen();
		string src = executablePath() + "/data/general/Mainmenu.png";
		DrawImage* imag = new DrawImage(src.c_str(), v3b(255, 0, 255));
		imag->draw(0, 0);
	}
	else if (g_GameState == Playing){
		// music
		/*if (!music_playing){
			play_sound("theme.wav");
			music_playing = true;
		}*/
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
			if (entity_get_pos(g_Boy)[0] >= c_ScreenW || entity_get_pos(g_Girl)[0] >= c_ScreenW) { //Right
				if (nextRightBackground(g_Bkg, g_LastFrame) == true) {
					v4i spawn = loadLevelData(g_Bkg);
					entity_set_pos(g_Boy, v2f(spawn[0], spawn[1]));
					entity_set_pos(g_Girl, v2f(spawn[2], spawn[3]));
				}
				else {
					if (entity_get_pos(g_Boy)[0] >= c_ScreenW) {
						entity_set_pos(g_Boy, v2f(c_ScreenW, entity_get_pos(g_Boy)[1]));
					}
					else {
						entity_set_pos(g_Girl, v2f(c_ScreenW, entity_get_pos(g_Girl)[1]));
					}
				}
			}
			else if (entity_get_pos(g_Boy)[0] <= 0 || entity_get_pos(g_Girl)[0] <= 0) { //Left
				if (nextLeftBackground(g_Bkg, g_LastFrame) == true) {
					v4i spawn = loadLevelData(g_Bkg);
					entity_set_pos(g_Boy, v2f(spawn[0], spawn[1]));
					entity_set_pos(g_Girl, v2f(spawn[2], spawn[3]));
				}
				else {
					if (entity_get_pos(g_Boy)[0] <= 0) {
						entity_set_pos(g_Boy, v2f(0, entity_get_pos(g_Boy)[1]));
					}
					else {
						entity_set_pos(g_Girl, v2f(0, entity_get_pos(g_Girl)[1]));
					}
				}
			}
			else if (entity_get_pos(g_Boy)[1] <= 0 || entity_get_pos(g_Girl)[1] <= 0) { //Down
				if (nextDownBackground(g_Bkg, g_LastFrame) == true) {
					v4i spawn = loadLevelData(g_Bkg);
					entity_set_pos(g_Boy, v2f(spawn[0], spawn[1]));
					entity_set_pos(g_Girl, v2f(spawn[2], spawn[3]));
				}
				else {
					if (entity_get_pos(g_Boy)[1] <= 0) {
						entity_set_pos(g_Boy, v2f(entity_get_pos(g_Boy)[0], 0));
					}
					else {
						entity_set_pos(g_Girl, v2f(entity_get_pos(g_Girl)[0], 0));
					}
				}
			}
			else if (entity_get_pos(g_Boy)[1] >= c_ScreenH || entity_get_pos(g_Girl)[1] >= c_ScreenH) { //Up
				if (nextUpBackground(g_Bkg, g_LastFrame) == true) {
					v4i spawn = loadLevelData(g_Bkg);
					entity_set_pos(g_Boy, v2f(spawn[0], spawn[1]));
					entity_set_pos(g_Girl, v2f(spawn[2], spawn[3]));
				}
				else {
					if (entity_get_pos(g_Boy)[1] >= c_ScreenH) {
						entity_set_pos(g_Boy, v2f(entity_get_pos(g_Boy)[0], c_ScreenH));
					}
					else {
						entity_set_pos(g_Girl, v2f(entity_get_pos(g_Girl)[0], c_ScreenH));
					}
				}
			}

			//// Display
			clearScreen();
			// -> draw background
			background_draw(g_Bkg, g_LastFrame, v2i(entity_get_pos(g_Girl)));
			// -> draw all entities
			for (int a = 0; a < (int)g_Entities.size(); a++) {
				entity_draw(g_Entities[a]);
			}
		}
		else {
			clearScreen();
			background_draw(g_Bkg, g_LastFrame, v2i(-2000, -2000));
		}

		// -> draw physics debug layer
		//phy_debug_draw();
	}
	else if (g_GameState == End){
		clearScreen();
		string src = executablePath()+ "/data/general/GameOver.png";
		DrawImage* imag = new DrawImage(src.c_str(), v3b(255, 0, 255));
		imag->draw(0, 0);
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

		//init random seed
		srand(time(NULL));

		///// Level creation

		// create background
		g_Bkg = background_init(c_ScreenW, c_ScreenH);

		// init physics
		phy_init();

		// bind tilemap to physics
		loadLevelData(g_Bkg);
		
		g_Boy = entity_create("boy", "boy.lua", v2i(0, 0));
		entity_set_pos(g_Boy, v2f(300, 200));
		g_Entities.push_back(g_Boy);

		g_Girl = entity_create("girl", "girl.lua", v2i(0, 0));
		entity_set_pos(g_Girl, v2f(600, 200));
		g_Entities.push_back(g_Girl);

		//init_sound();
		//std::cerr << executablePath();
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

