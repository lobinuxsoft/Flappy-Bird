#include "character.h"

Character::Character()
{
	position = { 50.0f, static_cast<float>(GetScreenHeight() / 2.0f) };
	color = characterColor;
	radius = 25.0f;
	moveStatus = Move_Status::still;
	velocity = 200;
}

Vector2 Character::GetPosition()
{
	return position;
}
float Character::GetRadius()
{
	return radius;
}

void Character::InputCharacter() 
{
	MovementInputDetection();
}
void Character::UpdateCharacter() 
{
	Move();
}
void Character::DrawCharacter()
{	
	DrawCircleV(position, radius, color);
}

void Character::Move()
{
	switch (moveStatus)
	{
	case Move_Status::movingUp:

		position.y -= velocity * GetFrameTime();

		break;
	case Move_Status::movingDown:

		position.y += velocity * GetFrameTime();

		break;
	case Move_Status::still:

		position.y += 0;

		break;
	}
}
void Character::MovementInputDetection() 
{
	if (IsKeyDown(moveUpKey))
	{
		moveStatus = Move_Status::movingUp;
	}
	else if (IsKeyDown(moveDownKey))
	{
		moveStatus = Move_Status::movingDown;
	}
	else
	{
		moveStatus = Move_Status::still;
	}
}
void Character::ResetCharacterPosition() 
{
	position.y = static_cast<float>(GetScreenHeight() / 2.0f);
}