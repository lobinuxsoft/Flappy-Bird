#ifndef gameplay_vs_h
#define gameplay_vs_h

#include "class/game_objects/background_parallax.h"
#include "class/game_objects/character.h"
#include "class/game_objects/obstacle.h"
#include "scene_manager.h"

namespace FlappyBird
{
	class GameplayVs
	{
	private:
		const int maxLives = 3;

		bool matchInProcess = true;
		int player1Lives = maxLives;
		int player2Lives = maxLives;

		BackgroundParallax* backgroundParallax;
		Character* player1;
		Character* player2;
		Obstacle* obstacle;

		float obstacleVelocity;

	public:
		GameplayVs();
		~GameplayVs();

		void Input();
		void Update(SceneManager* sceneManager);
		void Draw();

		bool CollisionCharacterObstacle(Character* character, Obstacle* obstacle);
		void EndGameCondition(SceneManager* sceneManager);
		void ResetGame();

		void DrawInputText();
		void DrawPlayerLives();
	};
}

#endif