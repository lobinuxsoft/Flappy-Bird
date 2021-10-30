#include "gameplay_vs.h"

namespace FlappyBird
{
	GameplayVs::GameplayVs()
	{
		backgroundParallax = new BackgroundParallax();
		player1 = new Character("P1", { 50.0f, static_cast<float>(GetScreenHeight() / 2.0f) });
		player2 = new Character( "P2", { 100.0f, static_cast<float>(GetScreenHeight() / 2.0f) });
		obstacle = new Obstacle();
		obstacleVelocity = baseObstacleVelocity;
	}

	GameplayVs::~GameplayVs()
	{
		delete backgroundParallax;
		delete player1;
		delete player2;
		delete obstacle;
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
			backgroundParallax->Update();
		}

		EndGameCondition(sceneManager);

	}

	void GameplayVs::Draw()
	{
		BeginDrawing();
		ClearBackground(gameClearBackgroundColor);

		backgroundParallax->Draw();

		player1->DrawCharacter();
		player2->DrawCharacter();
		obstacle->DrawObstacle();

		DrawInputText();
		DrawPlayerLives();

		EndDrawing();
	}

	bool GameplayVs::CollisionCharacterObstacle(Character* chara, Obstacle* obs)
	{
		return (CheckCollisionCircleRec(chara->GetPosition(), chara->GetRadius(), obs->GetTopRec())
			|| CheckCollisionCircleRec(chara->GetPosition(), chara->GetRadius(), obs->GetDownRec()));
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