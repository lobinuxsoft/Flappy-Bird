#ifndef gameplay_h
#define gameplay_h

#include "class/game_objects/background_parallax.h"
#include "class/game_objects/character.h"
#include "class/game_objects/obstacle.h"
#include "scene_manager.h"

namespace FlappyBird 
{
	class Gameplay
	{
	private:
		unsigned int gameScore = 0;
		unsigned gameHighscore = 0;
		bool gameOver = false;

		BackgroundParallax* backgroundParallax;
		Character* character;
		Obstacle* obstacle;

		float obstacleVelocity;

	public:
		Gameplay();
		~Gameplay();

		void Input();
		void Update(SceneManager* sceneManager);
		void Draw();

		bool PassThroughObstacle(Character* character, Obstacle* obstacle);
		bool CollisionCharacterObstacle(Character* character, Obstacle* obstacle);
		void EndGameCondition(SceneManager* sceneManager);
		void ResetGame();

		void AddScore();
	};
}

#endif