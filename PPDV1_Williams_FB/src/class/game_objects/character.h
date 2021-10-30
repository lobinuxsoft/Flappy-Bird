#ifndef character_h
#define character_h

#include "class/variables.h"

namespace FlappyBird 
{
	class Character
	{
	private:
		string playerID;
		Vector2 position;
		Color color;
		Move_Status moveStatus;
		Texture_Shown textureShown;
		Texture2D characterTextureDown;
		Texture2D characterTextureMid;
		Texture2D characterTextureUp;

		float radius;
		float velocity;
		float fallingSpeed;
		float jumpingTime;
		float currentTextureTime;
		float rotation;
	public:
		Character(string playerID,Vector2 position);
		~Character();

		Vector2 GetPosition();
		float GetRadius();

		void InputCharacter(bool isPress);
		void UpdateCharacter();
		void DrawCharacter();

		void Move();
		void MovementInputDetection(bool isPress);
		void ResetCharacter();
		void AnimationManager();
		void NextTexture();
		bool PlayerToucheBorders();
	};
}

#endif
