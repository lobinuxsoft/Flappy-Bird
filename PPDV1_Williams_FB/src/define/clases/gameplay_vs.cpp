#include "gameplay_vs.h"

namespace FlappyBird
{
	GameplayVs::GameplayVs()
	{
		player1 = new Character("P1", { 50.0f, static_cast<float>(GetScreenHeight() / 2.0f) });
		player2 = new Character( "P2", { 100.0f, static_cast<float>(GetScreenHeight() / 2.0f) });
		obstacle = new Obstacle();

		obstacleVelocity = baseObstacleVelocity;

		LoadTextures();
		ResizeTextures();

		scrollingBack = 0.0f;
		scrollingBackTwo = 0.0f;
		scrollingMidOne = 0.0f;
		scrollingMidTwo = 0.0f;
		scrollingFore = 0.0f;
	}
	GameplayVs::~GameplayVs()
	{
		delete player1;
		delete player2;
		delete obstacle;

		UnloadTextures();
	}

	void GameplayVs::Input()
	{
		player1->InputCharacter(IsKeyPressed(jumpKey1));
		player2->InputCharacter(IsKeyPressed(jumpKey2));
	}
	void GameplayVs::Update(SceneManager* sceneManager)
	{
		player1->UpdateCharacter();
		player2->UpdateCharacter();
		obstacle->UpdateObstacle(obstacleVelocity);

		EndGameCondition(sceneManager);

		BackgroundTexturesParallax();
	}
	void GameplayVs::Draw()
	{
		BeginDrawing();
		ClearBackground(gameClearBackgroundColor);

		DrawBackgroundTextures();

		player1->DrawCharacter();
		player2->DrawCharacter();
		obstacle->DrawObstacle();

		DrawInputText();

		EndDrawing();
	}

	bool GameplayVs::CollisionCharacterObstacle(Character* character, Obstacle* obstacle)
	{
		return (CheckCollisionCircleRec(character->GetPosition(), character->GetRadius(), obstacle->GetTopRec())
			|| CheckCollisionCircleRec(character->GetPosition(), character->GetRadius(), obstacle->GetDownRec()));
	}
	void GameplayVs::EndGameCondition(SceneManager* sceneManager) //Las dos condiciones de derrota son la colision de los objetos y cuando el pajaro toca el borde
	{
		if (CollisionCharacterObstacle(player1, obstacle))
		{
			ResetGame();

			sceneManager->SetCurrentScene(Scenes::menu);
		}

		if (player1->PlayerTouchesDownBorder())
		{
			ResetGame();
		}

		if (CollisionCharacterObstacle(player2, obstacle))
		{
			ResetGame();

			sceneManager->SetCurrentScene(Scenes::menu);
		}

		if (player2->PlayerTouchesDownBorder())
		{
			ResetGame();
		}
	}
	void GameplayVs::ResetGame() //Resetea las variables del pajaro y el obstaculo
	{
		obstacle->ResetObstaclePosition();
		player1->ResetCharacter();
		player2->ResetCharacter();
	}

	void GameplayVs::LoadTextures()
	{
		backgroundSky = LoadTexture("assets/background/sky.png");
		backgroundMountain = LoadTexture("assets/background/glacial_mountains.png");
		midgroundCloudsTwo = LoadTexture("assets/background/clouds_mg_2.png");
		midgroundCloudsOne = LoadTexture("assets/background/clouds_mg_1.png");
		backgroundClouds = LoadTexture("assets/background/clouds_bg.png");
		foregroundLonelyCloud = LoadTexture("assets/background/cloud_lonely.png");
	}
	void GameplayVs::ResizeTextures() //El fondo azul lo iguala a la pantalla
	{
		backgroundSky.width = GetScreenWidth();
		backgroundSky.height = GetScreenHeight();
	}
	void GameplayVs::UnloadTextures()
	{
		UnloadTexture(backgroundSky);
		UnloadTexture(backgroundMountain);
		UnloadTexture(midgroundCloudsTwo);
		UnloadTexture(midgroundCloudsOne);
		UnloadTexture(backgroundClouds);
		UnloadTexture(foregroundLonelyCloud);
	}
	void GameplayVs::DrawBackgroundTextures()
	{
		DrawTexture(backgroundSky, 0, 0, texturesColor);

		DrawTextureEx(backgroundClouds, { scrollingBack, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
		DrawTextureEx(backgroundClouds, { backgroundClouds.width * 2.0f + scrollingBack, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

		DrawTextureEx(backgroundMountain, { scrollingBackTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
		DrawTextureEx(backgroundMountain, { backgroundMountain.width * 2.0f + scrollingBackTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

		DrawTextureEx(midgroundCloudsTwo, { scrollingMidOne, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
		DrawTextureEx(midgroundCloudsTwo, { midgroundCloudsTwo.width * 2.0f + scrollingMidOne, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

		DrawTextureEx(midgroundCloudsOne, { scrollingMidTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
		DrawTextureEx(midgroundCloudsOne, { midgroundCloudsOne.width * 2.0f + scrollingMidTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

		DrawTextureEx(foregroundLonelyCloud, { scrollingFore, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
		DrawTextureEx(foregroundLonelyCloud, { foregroundLonelyCloud.width * 2.0f + scrollingFore, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
	}
	void GameplayVs::BackgroundTexturesParallax()
	{
		scrollingBack -= 0.1f;
		scrollingBackTwo -= 0.25f;
		scrollingMidOne -= 0.5f;
		scrollingMidTwo -= 0.75f;
		scrollingFore -= 1.25f;

		if (scrollingBack <= -backgroundClouds.width * 2) { scrollingBack = 0; }
		if (scrollingBackTwo <= -backgroundMountain.width * 2) { scrollingBackTwo = 0; }
		if (scrollingMidOne <= -midgroundCloudsTwo.width * 2) { scrollingMidOne = 0; }
		if (scrollingMidTwo <= -midgroundCloudsOne.width * 2) { scrollingMidTwo = 0; }
		if (scrollingFore <= -foregroundLonelyCloud.width * 2) { scrollingFore = 0; }
	}
	void GameplayVs::DrawInputText()
	{
		DrawText("P1 press SPACE BAR to jump", 10, GetScreenHeight() - 45, 20, BLUE);
		DrawText("P2 press ARROW KEY UP to jump", 10, GetScreenHeight() - 20, 20, RED);
	}
}