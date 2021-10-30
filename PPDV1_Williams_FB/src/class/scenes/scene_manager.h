#ifndef scene_manager_h
#define scene_manager_h

#include "class/variables.h"

namespace FlappyBird 
{
	class SceneManager
	{
	private:
		Scenes currentScene;
	public:
		SceneManager();

		void SetCurrentScene(Scenes currentScene);
		Scenes GetCurrentScene();
	};
}

#endif

