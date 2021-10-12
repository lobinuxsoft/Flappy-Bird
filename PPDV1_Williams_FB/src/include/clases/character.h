#ifndef character_h
#define character_h

#include "variables.h"

class Character 
{
private:
	Vector2 position;
	Color color;
	Move_Status moveStatus;
	Texture2D characterTexture;
	float radius;
	float velocity;
	float fallingSpeed;
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
};

#endif
