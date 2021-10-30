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
		if (matchInProcess)
		{
			player1->InputCharacter(IsKeyPressed(jumpKey1));
			player2->InputCharacter(IsKeyPressed(jumpKey2));
		}
	}

	void GameplayVs::Update(SceneManager* sceneManager)
	{
		if (matchInProcess)
		{
			player1->UpdateCharacter();
			player2->UpdateCharacter();
			obstacle->UpdateObstacle(obstacleVelocity);
			BackgroundTexturesParallax();
		}

		EndGameCondition(sceneManager);

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
		DrawPlayerLives();

		EndDrawing();
	}

	bool GameplayVs::CollisionCharacterObstacle(Character* character, Obstacle* obstacle)
	{
		return (CheckCollisionCircleRec(character->GetPosition(), character->GetRadius(), obstacle->GetTopRec())
			|| CheckCollisionCircleRec(character->GetPosition(), character->GetRadius(), obstacle->GetDownRec()));
	}

	void GameplayVs::EndGameCondition(SceneManager* sceneManager) //Las dos condiciones de derrota son la colision de los objetos y cuando el pajaro toca el borde
	{
		if (matchInProcess)
		{
			if (CollisionCharacterObstacle(player1, obstacle) || player1->PlayerToucheBorders())
			{
				player1Lives--;
				ResetGame();
			}

			if (CollisionCharacterObstacle(player2, obstacle) || player2->PlayerToucheBorders())
			{
				player2Lives--;
				ResetGame();
			}

			if (player1Lives <= 0 || player2Lives <= 0) matchInProcess = false;
			
		}
		else
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				ResetGame();

				sceneManager->SetCurrentScene(Scenes::menu);

				player1Lives = maxLives;
				player2Lives = maxLives;
				matchInProcess = true;
			}
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
		if (matchInProcess)
		{
			DrawText("P1 press SPACE BAR to jump", 10, GetScreenHeight() - 45, 20, DARKBLUE);
			DrawText("P2 press ARROW KEY UP to jump", 10, GetScreenHeight() - 20, 20, RED);
		}
		else
		{
			DrawText("Go to Main menu press ENTER", GetScreenWidth()/2 - (MeasureText("Go to Main menu press ENTER", 20)/2), GetScreenHeight()/2, 20, BLACK);

			if (player1Lives > player2Lives)
			{
				DrawText("P1 Win the match", GetScreenWidth() / 2 - (MeasureText("P1 Win the match", 40)/2), (GetScreenHeight() / 2) - 40, 40, DARKBLUE);
			}
			else
			{
				DrawText("P2 Win the match", GetScreenWidth() / 2 - (MeasureText("P1 Win the match", 40)/2), (GetScreenHeight() / 2) - 40, 40, RED);
			}
		}
	}

	void GameplayVs::DrawPlayerLives()
	{
		DrawText(TextFormat("P1 lives: %02i", player1Lives), 10, 10, 20, DARKBLUE);
		DrawText(TextFormat("P2 lives: %02i", player2Lives), GetScreenWidth() - MeasureText(TextFormat("P2 lives: %02i", player2Lives), 20) - 10, 10, 20, RED);
	}
}