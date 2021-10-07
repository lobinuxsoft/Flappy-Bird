#ifndef game_manager_h
#define game_manager_h

#include "menu.h"

class GameManager 
{
private:
	SceneManager* sceneManager;
public:
	GameManager();
	~GameManager();

	void Init();
	void Deinit();
	void Run();
};

#endif
