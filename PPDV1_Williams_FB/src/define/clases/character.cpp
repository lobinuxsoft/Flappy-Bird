#include "character.h"

namespace FlappyBird 
{
	Character::Character()
	{
		position = { 50.0f, static_cast<float>(GetScreenHeight() / 2.0f) };
		color = characterColor;
		radius = 25.0f;
		moveStatus = Move_Status::still;
		textureShown = Texture_Shown::mid;
		characterTextureDown = LoadTexture("assets/player/bluebird-downflap.png");
		characterTextureDown.width = radius * 2;
		characterTextureDown.height = radius * 2;
		characterTextureMid = LoadTexture("assets/player/bluebird-midflap.png");
		characterTextureMid.width = radius * 2;
		characterTextureMid.height = radius * 2;
		characterTextureUp = LoadTexture("assets/player/bluebird-upflap.png");
		characterTextureUp.width = radius * 2;
		characterTextureUp.height = radius * 2;
		velocity = baseVelocity;
		fallingSpeed = baseFallingSpeed;
		jumpingTime = 0.0f;
		currentTextureTime = 0.0f;
		rotation = 0.0f;
	}
	Character::~Character()
	{
		UnloadTexture(characterTextureDown);
		UnloadTexture(characterTextureMid);
		UnloadTexture(characterTextureUp);
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
		AnimationManager();
	}
	void Character::DrawCharacter()
	{

#if _DEBUG
		DrawCircle(position.x, position.y, radius, BLACK);
#endif	

		switch (textureShown)
		{
		case Texture_Shown::down:

			DrawTexturePro(characterTextureDown, { 0, 0, static_cast<float>(characterTextureDown.width), static_cast<float>(characterTextureDown.height) },
				{ position.x, position.y, static_cast<float>(characterTextureDown.width), static_cast<float>(characterTextureDown.height) },
				{ radius, radius }, rotation, color);
			break;
		case Texture_Shown::mid:

			DrawTexturePro(characterTextureMid, { 0, 0, static_cast<float>(characterTextureDown.width), static_cast<float>(characterTextureDown.height) },
				{ position.x, position.y, static_cast<float>(characterTextureDown.width), static_cast<float>(characterTextureDown.height) },
				{ radius, radius }, rotation, color);
			break;
		case Texture_Shown::up:

			DrawTexturePro(characterTextureUp, { 0, 0, static_cast<float>(characterTextureDown.width), static_cast<float>(characterTextureDown.height) },
				{ position.x, position.y, static_cast<float>(characterTextureDown.width), static_cast<float>(characterTextureDown.height) },
				{ radius, radius }, rotation, color);
			break;
		}
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

			if (fallingSpeed < maxFallingSpeed)
			{
				fallingSpeed += GetFrameTime() * fallingMultipliyer;
			}

			position.y += fallingSpeed * gravity * GetFrameTime();

			if (rotation <= maxFallingRotation)
			{
				rotation += GetFrameTime() * fallingRotationMultiplyer;
			}

			break;
		case Move_Status::still:

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
			rotation = -35.0f;
		}
	}
	void Character::ResetCharacter()
	{
		position.y = static_cast<float>(GetScreenHeight() / 2.0f);
		moveStatus = Move_Status::still;
		textureShown = Texture_Shown::mid;
		currentTextureTime = 0.0f;
		rotation = 0;
	}
	void Character::AnimationManager()
	{
		if (moveStatus != Move_Status::still)
		{
			currentTextureTime += GetFrameTime();

			if (currentTextureTime >= changeAnimationTime)
			{
				NextTexture();

				currentTextureTime = 0.0f;
			}
		}
	}
	void Character::NextTexture()
	{
		switch (textureShown)
		{
		case Texture_Shown::down:

			textureShown = Texture_Shown::mid;
			break;
		case Texture_Shown::mid:

			textureShown = Texture_Shown::up;
			break;
		case Texture_Shown::up:

			textureShown = Texture_Shown::down;
			break;
		}
	}
	bool Character::PlayerTouchesDownBorder()
	{
		return position.y + radius >= GetScreenHeight();
	}
}