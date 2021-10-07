#ifndef variables_h
#define variables_h

#include "raylib.h"

//Window
const int screenWidth = 800;
const int screenHeight = 450;
const short fps = 60;
static const char* tittle = "Flappy Bird";

//Scenes
enum class Scenes {menu, credits, gameplay};
const Scenes initialScene = Scenes::menu;

#endif
