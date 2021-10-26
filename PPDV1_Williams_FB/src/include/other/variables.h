#ifndef variables_h
#define variables_h

#include <iostream>

#include "raylib.h"

using namespace std;

namespace FlappyBird 
{
	//Window
	const int screenWidth = 800;
	const int screenHeight = 450;
	const short fps = 60;
	static const string tittle = "ARTIC BIRD xD";
	const Color tittleColor = BLACK;
	const short tittleFontSize = 50;

	//Scenes
	enum class Scenes { menu, credits, gameplay, gameplayVS, exit };
	const Scenes initialScene = Scenes::menu;

	//Buttons
	const int pressButtonKey = MOUSE_LEFT_BUTTON;
	const int buttonFontSize = 20;
	const Color textColor = RED;
	const Color buttonColor = BLACK;

	//Menu
	const short maxButtonsMenu = 4;
	const Color menuClearBackgroundColor = WHITE;
	static const string version = "V0.3";

	//Credits
	const Color creditsClearBackgroundColor = WHITE;
	const Color creditsColor = BLACK;
	const short creditsFontSize = 25;

	//Gameplay
	const Color gameClearBackgroundColor = WHITE;

	//Character
	enum class Move_Status { jumping, falling, still };
	enum class Texture_Shown { down, mid, up };
	const int jumpKey1 = KEY_SPACE;
	const int jumpKey2 = KEY_UP;
	const Color characterColor = WHITE;
	const float baseFallingSpeed = 7.5f;
	const float maxFallingSpeed = 50.0f;
	const float gravity = 20.5f;
	const float maxTimeJumping = 0.25f;
	const short fallingMultipliyer = 20;
	const short baseVelocity = 450;
	const float changeAnimationTime = 0.2f;
	const short maxFallingRotation = 80;
	const short fallingRotationMultiplyer = 120;

	//Obstacle 
	const Color obstacleColor = BLUE;
	const float baseObstacleVelocity = 100;

	//Texture
	const Color texturesColor = WHITE;
	const float backgroundSize = 2.0f;
	const float backgroundYPos = 20.0f;
}

#endif
