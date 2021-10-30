#ifndef menu_h
#define menu_h

#include "raylib.h"

#include "class/user_interface/button.h"
#include "scene_manager.h"

namespace FlappyBird
{
	class Menu
	{
	private:
		Button* playButton;
		Button* playerVSButton;
		Button* creditsButton;
		Button* exitButton;

		Texture2D backgroundSky;
		Texture2D backgroundClouds;
		Texture2D backgroundMountain;
		Texture2D midgroundCloudsTwo;
		Texture2D midgroundCloudsOne;
		Texture2D foregroundLonelyCloud;

		float scrollingBack;
		float scrollingBackTwo;
		float scrollingMidOne;
		float scrollingMidTwo;
		float scrollingFore;

		void LoadTextures();
		void ResizeTextures();
		void UnloadTextures();
		void DrawBackgroundTextures();
		void BackgroundTexturesParallax();

	public:
		Menu(Rectangle recs[maxButtonsMenu], const char* texts[maxButtonsMenu]);
		~Menu();

		void Input(SceneManager* sceneManager, Scenes scenes[maxButtonsMenu]);
		void Update();
		void Draw();
	};
}

#endif
