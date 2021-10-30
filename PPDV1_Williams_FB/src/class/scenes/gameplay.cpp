#include "gameplay.h"

namespace FlappyBird 
{
	Gameplay::Gameplay()
	{
		backgroundParallax = new BackgroundParallax();
		character = new Character( "P1", {50.0f, static_cast<float>(GetScreenHeight() / 2.0f)});
		obstacle = new Obstacle();

		obstacleVelocity = baseObstacleVelocity;
	}

	Gameplay::~Gameplay()
	{
		delete backgroundParallax;
		delete character;
		delete obstacle;
	}

	void Gameplay::Input()
	{
		character->InputCharacter(IsKeyPressed(jumpKey1));
	}

	void Gameplay::Update(SceneManager* sceneManager)
	{
		if (!gameOver)
		{
			character->UpdateCharacter();
			obstacle->UpdateObstacle(obstacleVelocity);

			if (PassThroughObstacle(character, obstacle)) AddScore();

			backgroundParallax->Update();
		}

		EndGameCondition(sceneManager);
	}

	void Gameplay::Draw()
	{
		BeginDrawing();
		ClearBackground(gameClearBackgroundColor);

		backgroundParallax->Draw();

		character->DrawCharacter();
		obstacle->DrawObstacle();

		DrawText(TextFormat("Score: %02i   HighScore: %02i", gameScore, gameHighscore), 10, 10, 20, BLACK);

		if(gameOver)
		{
			int centerX = GetScreenWidth() / 2;
			int centerY = GetScreenHeight() / 2;

			DrawText("GAME OVER", centerX - MeasureText("GAME OVER", 60) / 2, centerY - 30, 60, BLACK);
			DrawText("'ENTER' to retry", centerX - MeasureText("'ENTER' to retry", 20) / 2, centerY + 80, 20, BLACK);
			DrawText("'Q' to main menu", centerX - MeasureText("'Q' to main menu", 20) / 2, centerY + 130, 20, BLACK);
		}
		else
		{
			DrawText("P1 press SPACE BAR to jump", 10, GetScreenHeight() - 20, 20, BLACK);
		}

		EndDrawing();
	}

	bool Gameplay::PassThroughObstacle(Character* chara, Obstacle* obs)
	{
		if(!obs->GetPassThroughObstacle())
		{
			if (CheckCollisionCircleRec(chara->GetPosition(), chara->GetRadius(), obs->GetMidRec()))
			{
				obs->SetPassThroughObstacle(true);
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}

	bool Gameplay::CollisionCharacterObstacle(Character* chara, Obstacle* obs)
	{
		return (CheckCollisionCircleRec(chara->GetPosition(), chara->GetRadius(), obs->GetTopRec())
			|| CheckCollisionCircleRec(chara->GetPosition(), chara->GetRadius(), obs->GetDownRec()));
	}

	void Gameplay::EndGameCondition(SceneManager* sceneManager) //Las dos condiciones de derrota son la colision de los objetos y cuando el pajaro toca el borde
	{
		if (gameOver)
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				ResetGame();
			}

			if (IsKeyPressed(KEY_Q))
			{
				ResetGame();
				sceneManager->SetCurrentScene(Scenes::menu);
			}
		}
		else
		{
			gameOver = CollisionCharacterObstacle(character, obstacle) || character->PlayerToucheBorders();
		}
	}

	void Gameplay::ResetGame() //Resetea las variables del pajaro y el obstaculo
	{
		gameOver = false;
		gameScore = 0;

		obstacle->ResetObstaclePosition();
		character->ResetCharacter();
	}

	void Gameplay::AddScore()
	{
		gameScore++;

		gameHighscore = gameScore > gameHighscore ? gameScore : gameHighscore;
	}
}