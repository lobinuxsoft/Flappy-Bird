#ifndef character_h
#define character_h

#include "variables.h"

class Character 
{
private:
	Vector2 position;
	Color color;
	Move_Status moveStatus;
	float radius;
	float velocity;
public:
	Character();

	void InputCharacter();
	void UpdateCharacter();
	void DrawCharacter();

	void Move();
	void MovementInputDetection();
};

#endif
