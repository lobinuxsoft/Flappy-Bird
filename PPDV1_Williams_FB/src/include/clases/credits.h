#ifndef credits_h
#define credits_h

#include "button.h"

namespace FlappyBird 
{
	class Credits
	{
	private:
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