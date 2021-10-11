#ifndef menu_h
#define menu_h

#include "button.h"

class Menu 
{
private:
	Button* playButton;
	Button* creditsButton;
	Button* exitButton;
public:
	Menu();
	~Menu();
};

#endif
