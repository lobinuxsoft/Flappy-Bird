#ifndef obstacle_h
#define obstacle_h

#include "variables.h"

namespace FlappyBird 
{
	class Obstacle
	{
	private:
		const float verticalOffset = 110;
		const float width = 50;
		float x;
		float y;
		Rectangle topRec;
		Rectangle downRec;
		Color color;

	public:
		Obstacle();

		Rectangle GetTopRec();
		Rectangle GetDownRec();

		void UpdateObstacle(float velocity);
		void DrawObstacle();

		void ResetObstaclePosition();
		void RandomYPosition();
		bool IsObstacleOnTheLeft();
		void MoveObstacles(float velocity);
	};
}

#endif
