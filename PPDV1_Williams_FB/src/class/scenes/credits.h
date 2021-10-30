#ifndef credits_h
#define credits_h

#include "class/game_objects/background_parallax.h"
#include "class/user_interface/button.h"

namespace FlappyBird 
{
	class Credits
	{
	private:

		BackgroundParallax* backgroundParallax;
		Button* goMenuButton;

	public:
		Credits();
		~Credits();

		void Input(SceneManager* sceneManager);
		void Update();
		void Draw();
	};
}

#endif