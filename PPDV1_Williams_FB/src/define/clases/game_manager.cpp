#include "game_manager.h"

GameManager::GameManager() 
{
	InitWindow(screenWidth, screenHeight, "Flappy Bird");

	SetTargetFPS(60);
}
GameManager::~GameManager() 
{
	CloseWindow();
}

void GameManager::Run() 
{
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}