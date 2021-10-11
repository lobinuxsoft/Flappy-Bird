#include "game_manager.h"

GameManager::GameManager() 
{
	InitWindow(screenWidth, screenHeight, tittle);

	SetTargetFPS(fps);

    Init();
}
GameManager::~GameManager() 
{
	CloseWindow();

    Deinit();
}

void GameManager::Init()
{
    sceneManager = new SceneManager();
 
    Rectangle recs[maxButtonsMenu];
    recs[0] = { 50, 50, 300, 40 };
    recs[1] = { 50, 120, 300, 40 };
    recs[2] = { 50, 190, 300, 40 };
    
    const char* texts[maxButtonsMenu];
    texts[0] = "PLAY";
    texts[1] = "CREDITS";
    texts[2] = "EXIT";

    menu = new Menu(recs, texts);
    
    menuInputScenes[0] = Scenes::gameplay;
    menuInputScenes[1] = Scenes::credits;
    menuInputScenes[2] = Scenes::exit;
}
void GameManager::Deinit()
{
    delete sceneManager;
    delete menu;
}
void GameManager::Run() 
{
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        switch (sceneManager->GetCurrentScene()) 
        {
        case Scenes::menu:
            
            menu->Input(sceneManager, menuInputScenes);
            menu->Update();
            menu->Draw();

            break;
        case Scenes::credits:
            break;
        case Scenes::gameplay:
            break;
        case Scenes::exit:
            break;
        }        
    }    
}