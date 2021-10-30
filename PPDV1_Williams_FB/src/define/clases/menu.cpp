#include "menu.h"

namespace FlappyBird 
{
	void Menu::LoadTextures()
	{
		backgroundSky = LoadTexture("assets/background/sky.png");
		backgroundMountain = LoadTexture("assets/background/glacial_mountains.png");
		midgroundCloudsTwo = LoadTexture("assets/background/clouds_mg_2.png");
		midgroundCloudsOne = LoadTexture("assets/background/clouds_mg_1.png");
		backgroundClouds = LoadTexture("assets/background/clouds_bg.png");
		foregroundLonelyCloud = LoadTexture("assets/background/cloud_lonely.png");
	}

	void Menu::ResizeTextures()
	{
		backgroundSky.width = GetScreenWidth();
		backgroundSky.height = GetScreenHeight();
	}

	void Menu::UnloadTextures()
	{
		UnloadTexture(backgroundSky);
		UnloadTexture(backgroundMountain);
		UnloadTexture(midgroundCloudsTwo);
		UnloadTexture(midgroundCloudsOne);
		UnloadTexture(backgroundClouds);
		UnloadTexture(foregroundLonelyCloud);
	}

	void Menu::DrawBackgroundTextures()
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

	void Menu::BackgroundTexturesParallax()
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

	Menu::Menu(Rectangle recs[maxButtonsMenu], const char* texts[maxButtonsMenu])
	{
		playButton = new Button(recs[0], buttonColor, texts[0]);
		playerVSButton = new Button(recs[1], buttonColor, texts[1]);
		creditsButton = new Button(recs[2], buttonColor, texts[2]);
		exitButton = new Button(recs[3], buttonColor, texts[3]);

		LoadTextures();
		ResizeTextures();

		scrollingBack = 0.0f;
		scrollingBackTwo = 0.0f;
		scrollingMidOne = 0.0f;
		scrollingMidTwo = 0.0f;
		scrollingFore = 0.0f;
	}

	Menu::~Menu()
	{
		delete playButton;
		delete playerVSButton;
		delete creditsButton;
		delete exitButton;

		UnloadTextures();
	}

	void Menu::Input(SceneManager* sceneManager, Scenes scenes[maxButtonsMenu])
	{
		playButton->ChangeSceneWhenButtonPressed(sceneManager, scenes[0]);
		playerVSButton->ChangeSceneWhenButtonPressed(sceneManager, scenes[1]);
		creditsButton->ChangeSceneWhenButtonPressed(sceneManager, scenes[2]);
		exitButton->ChangeSceneWhenButtonPressed(sceneManager, scenes[3]);
	}

	void Menu::Update()
	{
		BackgroundTexturesParallax();
	}

	void Menu::Draw()
	{
		BeginDrawing();

		ClearBackground(menuClearBackgroundColor);

		DrawBackgroundTextures();

		playButton->DrawButton();
		playerVSButton->DrawButton();
		creditsButton->DrawButton();
		exitButton->DrawButton();

		DrawText(version.c_str(), GetScreenWidth() - 100, GetScreenHeight() - 50, creditsFontSize, creditsColor);
		DrawText(tittle.c_str(), GetScreenWidth() - MeasureText(tittle.c_str(), tittleFontSize) - tittleFontSize/2, tittleFontSize, tittleFontSize, tittleColor);

		Rectangle tutRect = { GetScreenWidth() * 0.48f, GetScreenHeight() * 0.25f, GetScreenWidth() / 2, GetScreenHeight() * 0.7f };

		DrawTextRec(GetFontDefault(), tutorial.c_str(), tutRect, 16, 1, false, BLACK);

		EndDrawing();
	}
}