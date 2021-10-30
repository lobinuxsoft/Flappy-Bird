#include "credits.h"

namespace FlappyBird 
{
	Credits::Credits()
	{
		backgroundParallax = new BackgroundParallax();
		goMenuButton = new Button({ static_cast<float>(GetScreenWidth() / 2) - 150, static_cast<float>(GetScreenHeight() / 2), 300.0f, 40.0f }, buttonColor, "MENU");
	}

	Credits::~Credits()
	{
		delete backgroundParallax;
		delete goMenuButton;
	}

	void Credits::Input(SceneManager* sceneManager)
	{
		goMenuButton->ChangeSceneWhenButtonPressed(sceneManager, Scenes::menu);
	}

	void Credits::Update()
	{
		backgroundParallax->Update();
	}

	void Credits::Draw()
	{
		BeginDrawing();

		ClearBackground(creditsClearBackgroundColor);

		backgroundParallax->Draw();

		goMenuButton->DrawButton();

		DrawText("GAME DEVELOPED BY WILLIAMS FACUNDO", GetScreenWidth() / 2 - 240, GetScreenHeight() / 2 - 100, creditsFontSize, creditsColor);
		DrawText("Assistant programmer MATIAS GALARZA", GetScreenWidth() / 2 - 240, GetScreenHeight() / 2 - 50, creditsFontSize, creditsColor);
		DrawText(version.c_str(), GetScreenWidth() - 100, GetScreenHeight() - 100, creditsFontSize + 10, creditsColor);

		EndDrawing();
	}
}