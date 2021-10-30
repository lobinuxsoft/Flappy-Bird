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
		bool passThroughObstacles = false;
		float x;
		float y;
		Rectangle topRec;
		Rectangle downRec;
		Rectangle midRec;
		Color color;

	public:
		Obstacle();

		Rectangle GetTopRec();
		Rectangle GetDownRec();
		Rectangle GetMidRec();

		void UpdateObstacle(float velocity);
		void DrawObstacle();

		void ResetObstaclePosition();
		void RandomYPosition();
		bool IsObstacleOnTheLeft();
		void MoveObstacles(float velocity);
		
		bool GetPassThroughObstacle();
		void SetPassThroughObstacle(bool value);
	};
}

#endif
