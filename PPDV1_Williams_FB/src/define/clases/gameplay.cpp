#include "gameplay.h"

namespace FlappyBird 
{
	Gameplay::Gameplay()
	{
		character = new Character();
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
		character->InputCharacter();
	}
	void Gameplay::Update(SceneManager* sceneManager)
	{
		character->UpdateCharacter();
		obstacle->UpdateObstacle(obstacleVelocity);

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

		EndDrawing();
	}

	bool Gameplay::CollisionCharacterObstacle(Character* character, Obstacle* obstacle)
	{
		return (CheckCollisionCircleRec(character->GetPosition(), character->GetRadius(), obstacle->GetTopRec())
			|| CheckCollisionCircleRec(character->GetPosition(), character->GetRadius(), obstacle->GetDownRec()));
	}
	void Gameplay::EndGameCondition(SceneManager* sceneManager)
	{
		if (CollisionCharacterObstacle(character, obstacle))
		{
			ResetGame();

			sceneManager->SetCurrentScene(Scenes::menu);
		}

		if (character->PlayerTouchesDownBorder())
		{
			ResetGame();
		}
	}
	void Gameplay::ResetGame()
	{
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
	void Gameplay::ResizeTextures()
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
}