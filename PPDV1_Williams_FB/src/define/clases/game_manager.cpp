#include "game_manager.h"

GameManager::GameManager() 
{
	InitWindow(screenWidth, screenHeight, tittle);

	SetTargetFPS(fps);
}
GameManager::~GameManager() 
{
	CloseWindow();
}

void GameManager::Init()
{
    sceneManager = new SceneManager();
}
void GameManager::Deinit()
{
    delete sceneManager;
}
void GameManager::Run() 
{
    Init();

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        switch (sceneManager->GetCurrentScene()) 
        {
        case Scenes::menu:
            BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            EndDrawing();
            break;
        case Scenes::credits:
            break;
        case Scenes::gameplay:
            break;
        }        
    }

    Deinit();
}