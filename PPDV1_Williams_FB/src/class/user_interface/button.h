#ifndef button_h
#define button_h

#include "raylib.h"

#include "class/variables.h"
#include "class/scenes/scene_manager.h"

namespace FlappyBird 
{
	class Button
	{
	private:
		Rectangle rec;
		Color color;
		const char* text;
	public:
		Button(Rectangle rec, Color color, const char* text);

		bool IsMouseOnButton();
		bool IsButtonPressed();
		void DrawButton();
		void ChangeSceneWhenButtonPressed(SceneManager* sceneManager, Scenes nextScene);
	};
}

#endif
