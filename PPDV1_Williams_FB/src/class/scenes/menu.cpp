#include "menu.h"

namespace FlappyBird 
{
	Menu::Menu(Rectangle recs[maxButtonsMenu], const char* texts[maxButtonsMenu])
	{
		backgroundParallax = new BackgroundParallax();
		playButton = new Button(recs[0], buttonColor, texts[0]);
		playerVSButton = new Button(recs[1], buttonColor, texts[1]);
		creditsButton = new Button(recs[2], buttonColor, texts[2]);
		exitButton = new Button(recs[3], buttonColor, texts[3]);
	}

	Menu::~Menu()
	{
		delete backgroundParallax;
		delete playButton;
		delete playerVSButton;
		delete creditsButton;
		delete exitButton;
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
		backgroundParallax->Update();
	}

	void Menu::Draw()
	{
		BeginDrawing();

		ClearBackground(menuClearBackgroundColor);

		backgroundParallax->Draw();

		playButton->DrawButton();
		playerVSButton->DrawButton();
		creditsButton->DrawButton();
		exitButton->DrawButton();

		DrawText(version.c_str(), GetScreenWidth() - 100, GetScreenHeight() - 50, creditsFontSize, creditsColor);
		DrawText(tittle.c_str(), GetScreenWidth() - MeasureText(tittle.c_str(), tittleFontSize) - tittleFontSize/2, tittleFontSize, tittleFontSize, tittleColor);

		Rectangle tutRect = { GetScreenWidth() * 0.48f, GetScreenHeight() * 0.25f, GetScreenWidth() * 0.5f, GetScreenHeight() * 0.7f };

		DrawTextRec(GetFontDefault(), tutorial.c_str(), tutRect, 16, 1, false, BLACK);

		EndDrawing();
	}
}