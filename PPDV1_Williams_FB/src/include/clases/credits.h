#ifndef credits_h
#define credits_h

#include "button.h"

namespace FlappyBird 
{
	class Credits
	{
	private:
		Button* goMenuButton;

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
		Credits();
		~Credits();

		void Input(SceneManager* sceneManager);
		void Update();
		void Draw();
	};
}

#endif