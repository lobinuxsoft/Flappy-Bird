#ifndef background_parallax_h
#define background_parallax_h

#include "raylib.h"

#include "class/variables.h"

namespace FlappyBird
{
	class BackgroundParallax
	{
	private:
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
		BackgroundParallax();
		~BackgroundParallax();
		void Update();
		void Draw();
	};
}

#endif
