#include "gameplay.h"

Gameplay::Gameplay()
{
	character = new Character();
}
Gameplay::~Gameplay()
{
	delete character;
}

void Gameplay::Input()
{
	character->InputCharacter();
}
void Gameplay::Update()
{
	character->UpdateCharacter();
}
void Gameplay::Draw()
{
	BeginDrawing();
	ClearBackground(gameClearBackgroundColor);

	character->DrawCharacter();

	EndDrawing();
}