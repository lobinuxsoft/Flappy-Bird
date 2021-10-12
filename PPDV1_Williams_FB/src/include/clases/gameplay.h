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

	Texture2D backgroundSky;
	Texture2D backgroundClouds;
	Texture2D backgroundMountain;
	Texture2D midgroundCloudsTwo;
	Texture2D midgroundCloudsOne;	
	Texture2D foregroundLonelyCloud;
	
	float scrollingBack;
	float scrollingBackTwo;
	float scrollingMidOne;
	float scrollingMidTwo;	
	float scrollingFore;
public:
	Gameplay();
	~Gameplay();

	void Input();
	void Update(SceneManager* sceneManager);
	void Draw();

	bool CollisionCharacterObstacle(Character* character, Obstacle* obstacle);
	void EndGameCondition(SceneManager* sceneManager);
	
	void LoadTextures();
	void ResizeTextures();
	void UnloadTextures();
	void DrawBackgroundTextures();
	void BackgroundTexturesParallax();
};

#endif