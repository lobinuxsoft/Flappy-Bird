#ifndef game_manager_h
#define game_manager_h

#include "menu.h"
#include "credits.h"

class GameManager 
{
private:
	SceneManager* sceneManager;
	Menu* menu;
	Credits* credits;

	Scenes menuInputScenes[maxButtonsMenu];
public:
	GameManager();
	~GameManager();

	void Init();
	void Deinit();
	void Run();
};

#endif
