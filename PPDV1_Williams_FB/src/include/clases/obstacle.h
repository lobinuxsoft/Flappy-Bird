#ifndef obstacle_h
#define obstacle_h

#include "variables.h"

class Obstacle 
{
private:
	Rectangle topRec;
	Rectangle downRec;
	Color color;
public:
	Obstacle();

	void UpdateObstacle(float velocity);
	void DrawObstacle();

	void ResetObstaclePosition();
};

#endif
