#ifndef game_manager_h
#define game_manager_h

#include "menu.h"

class GameManager 
{
private:
	SceneManager* sceneManager;
	Menu* menu;

	Scenes menuInputScenes[maxButtonsMenu];
public:
	GameManager();
	~GameManager();

	void Init();
	void Deinit();
	void Run();
};

#endif
