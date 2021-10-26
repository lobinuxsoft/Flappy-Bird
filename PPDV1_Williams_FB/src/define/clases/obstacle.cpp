#include "obstacle.h"

namespace FlappyBird 
{
	Obstacle::Obstacle() //Esta compuesto de dos rectangulos
	{
		x = GetScreenWidth() + width;
		y = GetScreenHeight()/2;

		topRec = Rectangle{ 0,0,0,0 };
		downRec = Rectangle{ 0,0,0,0 };

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
			RandomYPosition();
		}
	}
	void Obstacle::DrawObstacle() //Dibuja el obstaculo
	{
		DrawRectangleRec(topRec, color);
		DrawRectangleRec(downRec, color);
	}

	void Obstacle::ResetObstaclePosition() //Resetea la posicion del obstaculo
	{
		x = GetScreenWidth() + width;
	}

	bool Obstacle::IsObstacleOnTheLeft()
	{
		return (topRec.x + topRec.width <= 0 || downRec.x + downRec.width <= 0);
	}

	void Obstacle::RandomYPosition()
	{
		y = static_cast<float>(GetRandomValue(verticalOffset, GetScreenHeight() - verticalOffset));
	}

	void Obstacle::MoveObstacles(float velocity) //Mueve el obstaculo hacia la izquierda
	{
		x -= velocity * GetFrameTime();

		topRec = Rectangle
		{
			x,
			0,
			width,
			y - verticalOffset
		};


		downRec = Rectangle
		{
			x,
			y + verticalOffset,
			width,
			GetScreenHeight() - y
		};
	}
}