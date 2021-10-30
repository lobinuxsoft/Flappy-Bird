#include "character.h"

namespace FlappyBird 
{
	Character::Character(string playerID ,Vector2 position)
	{
		this->playerID = playerID;
		this->position = position;//{ 50.0f, static_cast<float>(GetScreenHeight() / 2.0f) };
		color = characterColor;
		radius = 25.0f;
		moveStatus = Move_Status::still;
		textureShown = Texture_Shown::mid;
		characterTextureDown = LoadTexture("assets/player/bluebird-downflap.png");
		characterTextureDown.width = static_cast<int>(radius) * 2;
		characterTextureDown.height = static_cast<int>(radius) * 2;
		characterTextureMid = LoadTexture("assets/player/bluebird-midflap.png");
		characterTextureMid.width = static_cast<int>(radius) * 2;
		characterTextureMid.height = static_cast<int>(radius) * 2;
		characterTextureUp = LoadTexture("assets/player/bluebird-upflap.png");
		characterTextureUp.width = static_cast<int>(radius) * 2;
		characterTextureUp.height = static_cast<int>(radius) * 2;
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

	void Character::InputCharacter(bool isPress)
	{
		MovementInputDetection(isPress);
	}
	void Character::UpdateCharacter()
	{
		Move();
		AnimationManager();
	}
	void Character::DrawCharacter() //Switch con las tres texturas del pajaro
	{

#if _DEBUG
		DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), radius, BLACK);
#endif	

		DrawText(playerID.c_str(), static_cast<int>(position.x), static_cast<int>(position.y - (radius + 20)), 20, BLACK);

		switch (textureShown) //DrawTexturePro es medio dificil de entender como funciona no te recomiendo que lo toques mucho
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

	void Character::Move() //Esto ser�a una maquina de estados que depende el estado de lo que hace el pajaro (saltar, caer o estar est�tico)
	{
		switch (moveStatus)
		{
		case Move_Status::jumping:

			if (jumpingTime < maxTimeJumping) //Aplica una fuerza para arriba (es negativo por como funciona raylib) y disminuye un poco esa fuerza por cada frame
			{
				position.y -= GetFrameTime() * velocity;
				velocity -= GetFrameTime() * gravity;
				jumpingTime += GetFrameTime();
			}
			else //Cuando deja de subir cambia el estado para bajar
			{
				fallingSpeed = baseFallingSpeed;
				moveStatus = Move_Status::falling;
			}

			break;
		case Move_Status::falling:

			if (fallingSpeed < maxFallingSpeed) //Aumenta la velocidad de caida hasta cierto maximo
			{
				fallingSpeed += GetFrameTime() * fallingMultipliyer;
			}

			position.y += fallingSpeed * gravity * GetFrameTime(); //Esto es la gravedad

			if (rotation <= maxFallingRotation) //Cuando esta cayendo rota en el sentido de las agujas del reloj
			{
				rotation += GetFrameTime() * fallingRotationMultiplyer;
			}

			break;
		case Move_Status::still: //Cuando esta inmobil no hace nada

			break;
		}
	}
	void Character::MovementInputDetection(bool isPress) //Si se toca la tecla de salto prepara todo para saltar
	{
		if (isPress)
		{
			moveStatus = Move_Status::jumping;
			jumpingTime = 0.0f;
			velocity = baseVelocity;
			rotation = -35.0f;
		}
	}
	void Character::ResetCharacter() //Resetea los valores necesarios para reiniciar la partida
	{
		position.y = static_cast<float>(GetScreenHeight() / 2.0f);
		moveStatus = Move_Status::still;
		textureShown = Texture_Shown::mid;
		currentTextureTime = 0.0f;
		rotation = 0;
	}
	void Character::AnimationManager() //Cambia de animacion cada x cantidad de tiempo solo si no esta quieto
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
	void Character::NextTexture() //Pasa a la siguiente textura
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
	bool Character::PlayerToucheBorders() //Si el pajaro toca el borde inferior o superior
	{
		return position.y + radius >= GetScreenHeight() || position.y - radius <= 0;
	}
}