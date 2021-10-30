#ifndef menu_h
#define menu_h

#include "raylib.h"

#include "class/game_objects/background_parallax.h"
#include "class/user_interface/button.h"
#include "scene_manager.h"

namespace FlappyBird
{
	class Menu
	{
	private:
		BackgroundParallax* backgroundParallax;
		Button* playButton;
		Button* playerVSButton;
		Button* creditsButton;
		Button* exitButton;

	public:
		Menu(Rectangle recs[maxButtonsMenu], const char* texts[maxButtonsMenu]);
		~Menu();

		void Input(SceneManager* sceneManager, Scenes scenes[maxButtonsMenu]);
		void Update();
		void Draw();
	};
}

#endif
