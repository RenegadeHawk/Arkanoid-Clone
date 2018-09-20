#pragma once
#include <SFML\Graphics.hpp>
#include <functional>

typedef std::function<void(void)> ButtonCallbackFunction;
class MButton
{

private:
	sf::Font*									font;
	
	std::string									buttonString = "null";
	
	sf::Vector2f								buttonPosition;
	sf::Vector2f								buttonSize;
	sf::Color									buttonColor;

	void										ConstructButton();
	


	ButtonCallbackFunction						CallbackFunction;

public:


	//Callback function








	
	bool										Pressed = false;
	sf::Text									buttonText;
	sf::RectangleShape							buttonShape;

												MButton();
												MButton(std::string _text, sf::Vector2f _postion, sf::Font &_font,
													sf::Vector2f _size,sf::Color _color,ButtonCallbackFunction _function);

												MButton(const MButton &_obj);
												~MButton();
	void										Clear();
	
	void										OnPressed();

	void										OnRelease();

	void										OnHover();

	void										OnExit();
};

