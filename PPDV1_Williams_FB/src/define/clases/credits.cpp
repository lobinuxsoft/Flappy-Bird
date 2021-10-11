#include "credits.h"

Credits::Credits()
{
	goMenuButton = new Button( {static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2), 300.0f, 40.0f }, buttonColor, "MENU");
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

	EndDrawing();
}