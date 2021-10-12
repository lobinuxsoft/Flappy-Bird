#ifndef gameplay_h
#define gameplay_h

#include "character.h"
#include "obstacle.h"

class Gameplay 
{
private:
	Character* character;
	Obstacle* obstacle;

	float obstacleVelocity;
public:
	Gameplay();
	~Gameplay();

	void Input();
	void Update();
	void Draw();
};

#endif