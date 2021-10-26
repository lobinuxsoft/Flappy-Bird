#include "game_manager.h"

namespace FlappyBird 
{
    GameManager::GameManager()
    {
        InitWindow(screenWidth, screenHeight, tittle.c_str());

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
        recs[3] = { 50, 260, 300, 40 };

        const char* texts[maxButtonsMenu];
        texts[0] = "PLAY";
        texts[1] = "P1 VS P2";
        texts[2] = "CREDITS";
        texts[3] = "EXIT";

        menu = new Menu(recs, texts);

        menuInputScenes[0] = Scenes::gameplay;
        menuInputScenes[1] = Scenes::gameplayVS;
        menuInputScenes[2] = Scenes::credits;
        menuInputScenes[3] = Scenes::exit;

        credits = new Credits();
        gameplay = new Gameplay();
        gameplayVs = new GameplayVs();
        exit = false;
    }
    void GameManager::Deinit()
    {
        delete sceneManager;
        delete menu;
        delete credits;
        delete gameplay;
        delete gameplayVs;
    }
    void GameManager::Run()
    {
        while (!WindowShouldClose() && !exit)    // Detect window close button or ESC key
        {
            switch (sceneManager->GetCurrentScene())
            {
            case Scenes::menu:

                menu->Input(sceneManager, menuInputScenes);
                menu->Update();
                menu->Draw();

                break;
            case Scenes::credits:

                credits->Input(sceneManager);
                credits->Update();
                credits->Draw();

                break;
            case Scenes::gameplay:

                gameplay->Input();
                gameplay->Update(sceneManager);
                gameplay->Draw();

                break;
            case Scenes::gameplayVS:

                gameplayVs->Input();
                gameplayVs->Update(sceneManager);
                gameplayVs->Draw();

                break;
            case Scenes::exit:

                exit = true;

                break;
            }
        }
    }
}