#include "button.h"

namespace FlappyBird 
{
	Button::Button(Rectangle rec, Color color, const char* text)
	{
		this->rec = rec;
		this->color = color;
		this->text = text;
	}

	bool Button::IsMouseOnButton()
	{
		return CheckCollisionPointRec(GetMousePosition(), rec);
	}
	bool Button::IsButtonPressed()
	{
		return IsMouseButtonPressed(pressButtonKey) && IsMouseOnButton();
	}
	void Button::DrawButton()
	{
		DrawRectangleRec(rec, color);
		DrawText(text, static_cast<int>(rec.x + rec.width / 2), static_cast<int>(rec.y + rec.height / 2), buttonFontSize, textColor);
	}
	void Button::ChangeSceneWhenButtonPressed(SceneManager* sceneManager, Scenes nextScene)
	{
		if (IsButtonPressed())
		{
			sceneManager->SetCurrentScene(nextScene);
		}
	}
}