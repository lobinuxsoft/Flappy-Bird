#ifndef character_h
#define character_h

#include "variables.h"

class Character 
{
private:
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
public:
	Character();
	~Character();

	Vector2 GetPosition();
	float GetRadius();

	void InputCharacter();
	void UpdateCharacter();
	void DrawCharacter();

	void Move();
	void MovementInputDetection();
	void ResetCharacterPosition();
	void AnimationManager();
	void NextTexture();
};

#endif
