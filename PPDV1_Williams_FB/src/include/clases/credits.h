#ifndef credits_h
#define credits_h

#include "button.h"

class Credits
{
private:
	Button* goMenuButton;
public:
	Credits();
	~Credits();

	void Input(SceneManager* sceneManager);
	void Update();
	void Draw();
};

#endif