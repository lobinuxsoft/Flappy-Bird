#ifndef variables_h
#define variables_h

#include <iostream>

#include "raylib.h"

using namespace std;

//Window
const int screenWidth = 800;
const int screenHeight = 450;
const short fps = 60;
static const char* tittle = "Flappy Bird";

//Scenes
enum class Scenes {menu, credits, gameplay, exit};
const Scenes initialScene = Scenes::menu;

//Buttons
const int pressButtonKey = MOUSE_LEFT_BUTTON;
const int buttonFontSize = 20;
const Color textColor = RED;
const Color buttonColor = BLACK;

//Menu
const short maxButtonsMenu = 3;
const Color menuClearBackgroundColor = WHITE;

//Credits
const Color creditsClearBackgroundColor = WHITE;
const Color creditsColor = BLACK;
const short creditsFontSize = 25;

//Gameplay
const Color gameClearBackgroundColor = WHITE;

//Character
enum class Move_Status {movingUp, movingDown, still};
const int moveUpKey = KEY_W;
const int moveDownKey = KEY_S;
const Color characterColor = YELLOW;

//Obstacle 
const Color obstacleColor = BLUE;
const float baseObstacleVelocity = 200;

//Texture
const Color texturesColor = WHITE;
const float backgroundSize = 2.0f;
const float backgroundYPos = 20.0f;

#endif
