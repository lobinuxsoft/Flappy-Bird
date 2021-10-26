#include "obstacle.h"

namespace FlappyBird 
{
	Obstacle::Obstacle() //Esta compuesto de dos rectangulos
	{
		topRec = { static_cast<float>(GetScreenWidth() - 50), 0, 50, 120 };
		downRec = { static_cast<float>(GetScreenWidth() - 50), 340, 50, 230 };
		color = obstacleColor;
	}

	Rectangle Obstacle::GetTopRec()
	{
		return topRec;
	}
	Rectangle Obstacle::GetDownRec()
	{
		return downRec;
	}

	void Obstacle::UpdateObstacle(float velocity)
	{
		MoveObstacles(velocity);

		if (IsObstacleOnTheLeft()) //Resetea la posicion del obstaculo cuando toca el borde
		{
			ResetObstaclePosition();
		}
	}
	void Obstacle::DrawObstacle() //Dibuja el obstaculo
	{
		DrawRectangleRec(topRec, color);
		DrawRectangleRec(downRec, color);
	}

	void Obstacle::ResetObstaclePosition() //Resetea la posicion del obstaculo
	{
		topRec.x = static_cast<float>(GetScreenWidth() + topRec.width);
		downRec.x = static_cast<float>(GetScreenWidth() + downRec.width);
	}
	bool Obstacle::IsObstacleOnTheLeft()
	{
		return (topRec.x + topRec.width <= 0 || downRec.x + downRec.width <= 0);
	}
	void Obstacle::MoveObstacles(float velocity) //Mueve el obstaculo hacia la izquierda
	{
		topRec.x -= velocity * GetFrameTime();
		downRec.x -= velocity * GetFrameTime();
	}
}