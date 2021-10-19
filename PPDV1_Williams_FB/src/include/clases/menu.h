#ifndef menu_h
#define menu_h

#include "button.h"

namespace FlappyBird 
{
	class Menu
	{
	private:
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
