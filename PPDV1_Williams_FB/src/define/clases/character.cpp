#include "character.h"

Character::Character()
{
	position = { 50.0f, static_cast<float>(GetScreenHeight() / 2.0f) };	
	color = characterColor;
	radius = 25.0f;
	moveStatus = Move_Status::still;	
	characterTexture = LoadTexture("assets/player/bluebird-midflap.png");
	characterTexture.width = radius * 2;
	characterTexture.height = radius * 2;
	velocity = baseVelocity;
	fallingSpeed = baseFallingSpeed;
	jumpingTime = 0.0f;	
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
			
		if (jumpingTime < maxTimeJumping) 
		{
			position.y -= GetFrameTime() * velocity;
			velocity -= GetFrameTime() * gravity;

			jumpingTime += GetFrameTime();
		}
		else 
		{
			fallingSpeed = baseFallingSpeed;
			moveStatus = Move_Status::falling;
		}

		break;
	case Move_Status::falling:

		fallingSpeed += GetFrameTime() * fallingMultipliyer;

		position.y += fallingSpeed * gravity * GetFrameTime();
			
		break;
	case Move_Status::still:

		position.y += 0;

		break;
	}	
}
void Character::MovementInputDetection() 
{
	if (IsKeyPressed(jumpKey))
	{
		moveStatus = Move_Status::jumping;
		jumpingTime = 0.0f;	
		velocity = baseVelocity;
	}
}
void Character::ResetCharacterPosition() 
{
	position.y = static_cast<float>(GetScreenHeight() / 2.0f);
}