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
void Gameplay::Update()
{
	character->UpdateCharacter();
	obstacle->UpdateObstacle(obstacleVelocity);
}
void Gameplay::Draw()
{
	BeginDrawing();
	ClearBackground(gameClearBackgroundColor);

	character->DrawCharacter();
	obstacle->DrawObstacle();

	EndDrawing();
}