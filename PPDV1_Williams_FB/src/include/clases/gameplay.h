#ifndef gameplay_h
#define gameplay_h

#include "character.h"

class Gameplay 
{
private:
	Character* character;
public:
	Gameplay();
	~Gameplay();

	void Input();
	void Update();
	void Draw();
};

#endif