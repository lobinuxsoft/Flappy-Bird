#include "character.h"

Character::Character()
{
	//position = { 50.0f, static_cast<float>(GetScreenHeight() / 2.0f) };
	position = { 50.0f, 30};
	color = characterColor;
	radius = 25.0f;
	moveStatus = Move_Status::falling;
	velocity = 200;
	characterTexture = LoadTexture("assets/player/bluebird-midflap.png");
	characterTexture.width = radius * 2;
	characterTexture.height = radius * 2;
	fallingSpeed = 0.0f;
}
Character::~Character()
{
	UnloadTexture(characterTexture);
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
	DrawTexture(characterTexture, static_cast<int>(position.x) - radius, static_cast<int>(position.y) - radius, color);	
}

void Character::Move()
{
	switch (moveStatus)
	{
	case Move_Status::jumping:		

		fallingSpeed = 0;

		break;	
		case Move_Status::falling:

			if (fallingSpeed < maxFallingSpeed)
			{
				fallingSpeed += GetFrameTime() * (maxFallingSpeed / 1.5f);
			}
			
			position.y += fallingSpeed * gravity * GetFrameTime();

		break;
	}
}
void Character::MovementInputDetection() 
{
	if (IsKeyPressed(jumpKey))
	{
		moveStatus = Move_Status::jumping;
	}	
	else
	{
		moveStatus = Move_Status::falling;
	}
}
void Character::ResetCharacterPosition() 
{
	position.y = static_cast<float>(GetScreenHeight() / 2.0f);
}