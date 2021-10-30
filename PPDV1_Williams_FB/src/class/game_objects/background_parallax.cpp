#include "background_parallax.h"

void FlappyBird::BackgroundParallax::LoadTextures()
{
	backgroundSky = LoadTexture("assets/background/sky.png");
	backgroundMountain = LoadTexture("assets/background/glacial_mountains.png");
	midgroundCloudsTwo = LoadTexture("assets/background/clouds_mg_2.png");
	midgroundCloudsOne = LoadTexture("assets/background/clouds_mg_1.png");
	backgroundClouds = LoadTexture("assets/background/clouds_bg.png");
	foregroundLonelyCloud = LoadTexture("assets/background/cloud_lonely.png");
}

void FlappyBird::BackgroundParallax::ResizeTextures()
{
	backgroundSky.width = GetScreenWidth();
	backgroundSky.height = GetScreenHeight();
}

void FlappyBird::BackgroundParallax::UnloadTextures()
{
	UnloadTexture(backgroundSky);
	UnloadTexture(backgroundMountain);
	UnloadTexture(midgroundCloudsTwo);
	UnloadTexture(midgroundCloudsOne);
	UnloadTexture(backgroundClouds);
	UnloadTexture(foregroundLonelyCloud);
}

void FlappyBird::BackgroundParallax::DrawBackgroundTextures()
{
	DrawTexture(backgroundSky, 0, 0, texturesColor);

	DrawTextureEx(backgroundClouds, { scrollingBack, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
	DrawTextureEx(backgroundClouds, { backgroundClouds.width * 2.0f + scrollingBack, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

	DrawTextureEx(backgroundMountain, { scrollingBackTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
	DrawTextureEx(backgroundMountain, { backgroundMountain.width * 2.0f + scrollingBackTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

	DrawTextureEx(midgroundCloudsTwo, { scrollingMidOne, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
	DrawTextureEx(midgroundCloudsTwo, { midgroundCloudsTwo.width * 2.0f + scrollingMidOne, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

	DrawTextureEx(midgroundCloudsOne, { scrollingMidTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
	DrawTextureEx(midgroundCloudsOne, { midgroundCloudsOne.width * 2.0f + scrollingMidTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

	DrawTextureEx(foregroundLonelyCloud, { scrollingFore, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
	DrawTextureEx(foregroundLonelyCloud, { foregroundLonelyCloud.width * 2.0f + scrollingFore, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
}

void FlappyBird::BackgroundParallax::BackgroundTexturesParallax()
{
	scrollingBack -= 10.0f * GetFrameTime();
	scrollingBackTwo -= 25.0f * GetFrameTime();
	scrollingMidOne -= 50.0f * GetFrameTime();
	scrollingMidTwo -= 75.0f * GetFrameTime();
	scrollingFore -= 125.0f * GetFrameTime();

	if (scrollingBack <= -backgroundClouds.width * 2) { scrollingBack = 0; }
	if (scrollingBackTwo <= -backgroundMountain.width * 2) { scrollingBackTwo = 0; }
	if (scrollingMidOne <= -midgroundCloudsTwo.width * 2) { scrollingMidOne = 0; }
	if (scrollingMidTwo <= -midgroundCloudsOne.width * 2) { scrollingMidTwo = 0; }
	if (scrollingFore <= -foregroundLonelyCloud.width * 2) { scrollingFore = 0; }
}

FlappyBird::BackgroundParallax::BackgroundParallax()
{
	LoadTextures();
	ResizeTextures();

	scrollingBack = 0.0f;
	scrollingBackTwo = 0.0f;
	scrollingMidOne = 0.0f;
	scrollingMidTwo = 0.0f;
	scrollingFore = 0.0f;
}

FlappyBird::BackgroundParallax::~BackgroundParallax()
{
	UnloadTextures();
}

void FlappyBird::BackgroundParallax::Update()
{
	BackgroundTexturesParallax();
}

void FlappyBird::BackgroundParallax::Draw()
{
	DrawBackgroundTextures();
}
