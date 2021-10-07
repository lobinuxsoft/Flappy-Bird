#ifndef game_manager_h
#define game_manager_h

#include "raylib.h"

class GameManager 
{
private:
	const int screenWidth = 800;
	const int screenHeight = 450;
public:
	GameManager();
	~GameManager();

	void Run();
};

#endif
