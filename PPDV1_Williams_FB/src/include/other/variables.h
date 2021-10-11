#ifndef variables_h
#define variables_h

#include "raylib.h"

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

#endif
