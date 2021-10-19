#ifndef game_manager_h
#define game_manager_h

#include "menu.h"
#include "credits.h"
#include "gameplay.h"
#include "gameplay_vs.h"

namespace FlappyBird 
{
	class GameManager
	{
	private:
		SceneManager* sceneManager;
		Menu* menu;
		Credits* credits;
		Gameplay* gameplay;
		GameplayVs* gameplayVs;

		Scenes menuInputScenes[maxButtonsMenu];

		bool exit;
	public:
		GameManager();
		~GameManager();

		void Init();
		void Deinit();
		void Run();
	};
}

#endif
