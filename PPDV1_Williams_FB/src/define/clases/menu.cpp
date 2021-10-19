#include "menu.h"

namespace FlappyBird 
{
	Menu::Menu(Rectangle recs[maxButtonsMenu], const char* texts[maxButtonsMenu])
	{
		playButton = new Button(recs[0], buttonColor, texts[0]);
		playerVSButton = new Button(recs[1], buttonColor, texts[1]);
		creditsButton = new Button(recs[2], buttonColor, texts[2]);
		exitButton = new Button(recs[3], buttonColor, texts[3]);
	}
	Menu::~Menu()
	{
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

	}
	void Menu::Draw()
	{
		BeginDrawing();

		ClearBackground(menuClearBackgroundColor);

		playButton->DrawButton();
		playerVSButton->DrawButton();
		creditsButton->DrawButton();
		exitButton->DrawButton();

		DrawText(version, GetScreenWidth() - 100, GetScreenHeight() - 50, creditsFontSize + 10, creditsColor);

		EndDrawing();
	}
}