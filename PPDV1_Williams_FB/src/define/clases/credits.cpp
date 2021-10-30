#include "credits.h"

namespace FlappyBird 
{
	void Credits::LoadTextures()
	{
		backgroundSky = LoadTexture("assets/background/sky.png");
		backgroundMountain = LoadTexture("assets/background/glacial_mountains.png");
		midgroundCloudsTwo = LoadTexture("assets/background/clouds_mg_2.png");
		midgroundCloudsOne = LoadTexture("assets/background/clouds_mg_1.png");
		backgroundClouds = LoadTexture("assets/background/clouds_bg.png");
		foregroundLonelyCloud = LoadTexture("assets/background/cloud_lonely.png");
	}

	void Credits::ResizeTextures()
	{
		backgroundSky.width = GetScreenWidth();
		backgroundSky.height = GetScreenHeight();
	}

	void Credits::UnloadTextures()
	{
		UnloadTexture(backgroundSky);
		UnloadTexture(backgroundMountain);
		UnloadTexture(midgroundCloudsTwo);
		UnloadTexture(midgroundCloudsOne);
		UnloadTexture(backgroundClouds);
		UnloadTexture(foregroundLonelyCloud);
	}

	void Credits::DrawBackgroundTextures()
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

	void Credits::BackgroundTexturesParallax()
	{
		scrollingBack -= 0.1f;
		scrollingBackTwo -= 0.25f;
		scrollingMidOne -= 0.5f;
		scrollingMidTwo -= 0.75f;
		scrollingFore -= 1.25f;

		if (scrollingBack <= -backgroundClouds.width * 2) { scrollingBack = 0; }
		if (scrollingBackTwo <= -backgroundMountain.width * 2) { scrollingBackTwo = 0; }
		if (scrollingMidOne <= -midgroundCloudsTwo.width * 2) { scrollingMidOne = 0; }
		if (scrollingMidTwo <= -midgroundCloudsOne.width * 2) { scrollingMidTwo = 0; }
		if (scrollingFore <= -foregroundLonelyCloud.width * 2) { scrollingFore = 0; }
	}

	Credits::Credits()
	{
		goMenuButton = new Button({ static_cast<float>(GetScreenWidth() / 2) - 150, static_cast<float>(GetScreenHeight() / 2), 300.0f, 40.0f }, buttonColor, "MENU");

		LoadTextures();
		ResizeTextures();

		scrollingBack = 0.0f;
		scrollingBackTwo = 0.0f;
		scrollingMidOne = 0.0f;
		scrollingMidTwo = 0.0f;
		scrollingFore = 0.0f;
	}

	Credits::~Credits()
	{
		delete goMenuButton;

		UnloadTextures();
	}

	void Credits::Input(SceneManager* sceneManager)
	{
		goMenuButton->ChangeSceneWhenButtonPressed(sceneManager, Scenes::menu);
	}

	void Credits::Update()
	{
		BackgroundTexturesParallax();
	}

	void Credits::Draw()
	{
		BeginDrawing();

		ClearBackground(creditsClearBackgroundColor);

		DrawBackgroundTextures();

		goMenuButton->DrawButton();

		DrawText("GAME DEVELOPED BY WILLIAMS FACUNDO", GetScreenWidth() / 2 - 240, GetScreenHeight() / 2 - 100, creditsFontSize, creditsColor);
		DrawText("Assistant programmer MATIAS GALARZA", GetScreenWidth() / 2 - 240, GetScreenHeight() / 2 - 50, creditsFontSize, creditsColor);
		DrawText(version.c_str(), GetScreenWidth() - 100, GetScreenHeight() - 100, creditsFontSize + 10, creditsColor);

		EndDrawing();
	}
}