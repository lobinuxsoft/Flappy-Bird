#include "scene_manager.h"

namespace FlappyBird 
{
	SceneManager::SceneManager()
	{
		SetCurrentScene(initialScene);
	}

	void SceneManager::SetCurrentScene(Scenes curScene)
	{
		this->currentScene = curScene;
	}
	Scenes SceneManager::GetCurrentScene()
	{
		return currentScene;
	}
}