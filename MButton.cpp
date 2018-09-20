#include "MButton.h"

#include <iostream>

void MButton::ConstructButton()
{
	buttonShape.setSize({ buttonSize });
	buttonShape.setPosition(buttonPosition);
	buttonShape.setOrigin(buttonSize.x/2, buttonSize.y/2);
	sf::Color col = sf::Color(180, 180, 180, 255);
	buttonShape.setFillColor(col);

	buttonText.setFont(*font);
	buttonText.setFillColor(sf::Color::Black);
	buttonText.setCharacterSize(24);
	buttonText.setString(buttonString);
	buttonText.setPosition(buttonPosition.x, buttonPosition.y);
	sf::FloatRect textRect = buttonText.getLocalBounds();
	buttonText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

}


void MButton::OnPressed()
{
	CallbackFunction();
	Pressed = true;
	sf::Color col = sf::Color(30, 30, 30, 255);
	buttonShape.setFillColor(col);
}

void MButton::OnRelease()
{
	Pressed = false;
}


void MButton::OnHover()
{
	buttonShape.setFillColor(sf::Color::White);
}

void MButton::OnExit()
{
	Pressed = false;
	sf::Color col = sf::Color(180, 180, 180, 255);
	buttonShape.setFillColor(col);
}

void MButton::Clear()
{
	sf::Color col = sf::Color(180, 180, 180, 255);
	buttonShape.setFillColor(col);
}

MButton::MButton()
{

}



MButton::MButton(std::string _text, sf::Vector2f _position, sf::Font & _font, sf::Vector2f _size, sf::Color _color, ButtonCallbackFunction _function):
	buttonString( _text), buttonPosition(_position), font( &_font),buttonSize(_size), buttonColor(_color), CallbackFunction(_function)
{
	ConstructButton();
}






MButton::MButton(const MButton & obj)
{
	this->buttonString = obj.buttonString;
	this->buttonShape = obj.buttonShape;
	this->buttonText = obj.buttonText;
	this->CallbackFunction = obj.CallbackFunction;
}

MButton::~MButton()
{
}
