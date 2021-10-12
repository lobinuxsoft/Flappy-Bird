#include "gameplay.h"

Gameplay::Gameplay()
{
	character = new Character();
	obstacle = new Obstacle();

	obstacleVelocity = baseObstacleVelocity;
}
Gameplay::~Gameplay()
{
	delete character;
	delete obstacle;
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
}
void Gameplay::Draw()
{
	BeginDrawing();
	ClearBackground(gameClearBackgroundColor);

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
		obstacle->ResetObstaclePosition();
		character->ResetCharacterPosition();

		sceneManager->SetCurrentScene(Scenes::menu);
	}
}