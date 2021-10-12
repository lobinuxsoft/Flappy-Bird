#include "obstacle.h"

Obstacle::Obstacle()
{
	topRec = {static_cast<float>(GetScreenWidth() - 100), 0, 50, 150};
	downRec = { static_cast<float>(GetScreenWidth() - 100), 220, 50, 230 };
	color = obstacleColor;
}

void Obstacle::UpdateObstacle(float velocity)
{
	MoveObstacles(velocity);

	if (IsObstacleOnTheLeft()) 
	{
		ResetObstaclePosition();
	}
}
void Obstacle::DrawObstacle()
{
	DrawRectangleRec(topRec, color);
	DrawRectangleRec(downRec, color);
}

void Obstacle::ResetObstaclePosition() 
{
	topRec.x = static_cast<float>(GetScreenWidth() - 100);
	downRec.x = static_cast<float>(GetScreenWidth() - 100);
}
bool Obstacle::IsObstacleOnTheLeft() 
{
	return (topRec.x <= 0 || downRec.x <= 0);	
}
void Obstacle::MoveObstacles(float velocity)
{
	topRec.x -= velocity * GetFrameTime();
	downRec.x -= velocity * GetFrameTime();
}