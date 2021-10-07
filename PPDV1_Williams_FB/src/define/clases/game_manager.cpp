#include "game_manager.h"

GameManager::GameManager() 
{
	InitWindow(100,100," a ");
}
GameManager::~GameManager() 
{
	CloseWindow();
}