#ifndef gameplay_h
#define gameplay_h

#include "character.h"
#include "obstacle.h"
#include "scene_manager.h"

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
	void Update(SceneManager* sceneManager);
	void Draw();

	bool CollisionCharacterObstacle(Character* character, Obstacle* obstacle);
	void EndGameCondition(SceneManager* sceneManager);
};

#endif