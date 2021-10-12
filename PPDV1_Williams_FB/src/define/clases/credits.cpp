#include "credits.h"

Credits::Credits()
{
	goMenuButton = new Button( {static_cast<float>(GetScreenWidth() / 2) - 150, static_cast<float>(GetScreenHeight() / 2), 300.0f, 40.0f }, buttonColor, "MENU");
}
Credits::~Credits()
{
	delete goMenuButton;
}

void Credits::Input(SceneManager* sceneManager)
{
	goMenuButton->ChangeSceneWhenButtonPressed(sceneManager, Scenes::menu);
}
void Credits::Update() 
{

}
void Credits::Draw() 
{
	BeginDrawing();

	ClearBackground(creditsClearBackgroundColor);

	goMenuButton->DrawButton();
	
	DrawText("GAME DEVELOPED BY WILLIAMS FACUNDO", GetScreenWidth() / 2 - 240, GetScreenHeight() / 2 - 50, creditsFontSize, creditsColor);
	DrawText("V0.1", GetScreenWidth() - 100, GetScreenHeight() - 50, creditsFontSize + 10, creditsColor);

	EndDrawing();
}