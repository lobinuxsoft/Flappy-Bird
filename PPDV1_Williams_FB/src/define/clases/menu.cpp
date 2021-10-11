#include "menu.h"

Menu::Menu(Rectangle recs[maxButtonsMenu], const char* texts[maxButtonsMenu])
{
	playButton = new Button(recs[0], buttonColor, texts[0]);
	creditsButton = new Button(recs[1], buttonColor, texts[1]);
	exitButton = new Button(recs[2], buttonColor, texts[2]);
}
Menu::~Menu()
{
	delete playButton;
	delete creditsButton;
	delete exitButton;
}

void Menu::Input(SceneManager* sceneManager ,Scenes scenes[maxButtonsMenu]) 
{
	playButton->ChangeSceneWhenButtonPressed(sceneManager, scenes[0]);
	creditsButton->ChangeSceneWhenButtonPressed(sceneManager, scenes[1]);
	exitButton->ChangeSceneWhenButtonPressed(sceneManager, scenes[2]);
}
void Menu::Update() 
{

}
void Menu::Draw()
{
	BeginDrawing();

	ClearBackground(menuClearBackgroundColor);

	playButton->DrawButton();
	creditsButton->DrawButton();
	exitButton->DrawButton();

	EndDrawing();
}