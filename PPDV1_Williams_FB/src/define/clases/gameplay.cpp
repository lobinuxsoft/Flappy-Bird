#include "gameplay.h"

namespace FlappyBird 
{
	Gameplay::Gameplay()
	{
		character = new Character( "P1", {50.0f, static_cast<float>(GetScreenHeight() / 2.0f)});
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

	Gameplay::~Gameplay()
	{
		delete character;
		delete obstacle;

		UnloadTextures();
	}

	void Gameplay::Input()
	{
		character->InputCharacter(IsKeyPressed(jumpKey1));
	}

	void Gameplay::Update(SceneManager* sceneManager)
	{
		character->UpdateCharacter();
		obstacle->UpdateObstacle(obstacleVelocity);

		if (PassThroughObstacle(character, obstacle)) AddScore();

		EndGameCondition(sceneManager);

		BackgroundTexturesParallax();
	}

	void Gameplay::Draw()
	{
		BeginDrawing();
		ClearBackground(gameClearBackgroundColor);

		DrawBackgroundTextures();

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

		EndDrawing();
	}

	bool Gameplay::PassThroughObstacle(Character* character, Obstacle* obstacle)
	{
		if(!obstacle->GetPassThroughObstacle())
		{
			if (CheckCollisionCircleRec(character->GetPosition(), character->GetRadius(), obstacle->GetMidRec()))
			{
				obstacle->SetPassThroughObstacle(true);
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}

	bool Gameplay::CollisionCharacterObstacle(Character* character, Obstacle* obstacle)
	{
		return (CheckCollisionCircleRec(character->GetPosition(), character->GetRadius(), obstacle->GetTopRec())
			|| CheckCollisionCircleRec(character->GetPosition(), character->GetRadius(), obstacle->GetDownRec()));
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

	void Gameplay::LoadTextures()
	{
		backgroundSky = LoadTexture("assets/background/sky.png");
		backgroundMountain = LoadTexture("assets/background/glacial_mountains.png");
		midgroundCloudsTwo = LoadTexture("assets/background/clouds_mg_2.png");
		midgroundCloudsOne = LoadTexture("assets/background/clouds_mg_1.png");
		backgroundClouds = LoadTexture("assets/background/clouds_bg.png");
		foregroundLonelyCloud = LoadTexture("assets/background/cloud_lonely.png");
	}

	void Gameplay::ResizeTextures() //El fondo azul lo iguala a la pantalla
	{
		backgroundSky.width = GetScreenWidth();
		backgroundSky.height = GetScreenHeight();
	}

	void Gameplay::UnloadTextures()
	{
		UnloadTexture(backgroundSky);
		UnloadTexture(backgroundMountain);
		UnloadTexture(midgroundCloudsTwo);
		UnloadTexture(midgroundCloudsOne);
		UnloadTexture(backgroundClouds);
		UnloadTexture(foregroundLonelyCloud);
	}

	void Gameplay::DrawBackgroundTextures()
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

	void Gameplay::BackgroundTexturesParallax()
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

	void Gameplay::AddScore()
	{
		gameScore++;

		gameHighscore = gameScore > gameHighscore ? gameScore : gameHighscore;
	}
}