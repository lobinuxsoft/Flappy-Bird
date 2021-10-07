#include "game_manager.h"

int main() 
{	
	GameManager* game = new GameManager();

	game->Run();

	delete game;

	return 0;
}