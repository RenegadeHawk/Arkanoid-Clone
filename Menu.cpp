#include "Menu.h"
#include<iostream>


Menu::Menu()
{
}

Menu::Menu(float _dx, float _dy, sf::Font & _font):font(_font),anchorPosition({_dx,_dy})
{
	index = 0;
	selectedButtonIndex = -1;
}


Menu::~Menu()
{
	isActive = false;
}


void Menu::CycleDown()
{
	int previousButtonIndex = selectedButtonIndex;
	selectedButtonIndex = (selectedButtonIndex + 1) % Buttons.size();
	std::cout << std::to_string(previousButtonIndex);
	Buttons[selectedButtonIndex].OnHover();
	if (previousButtonIndex >= 0)
	{
		Buttons[previousButtonIndex].OnExit();
	}
}

void Menu::CycleUp()
{
	if (selectedButtonIndex < 0)
	{
		selectedButtonIndex = 0;
	}
	int previousButtonIndex = selectedButtonIndex;
	selectedButtonIndex = (selectedButtonIndex + Buttons.size() - 1) % Buttons.size();
	Buttons[selectedButtonIndex].OnHover();
	Buttons[previousButtonIndex].OnExit();
	

}

void Menu::PressButton()
{
	if (selectedButtonIndex >= 0)
	{
		Buttons[selectedButtonIndex].OnPressed();
	}
	
}
void Menu::ReleaseButton()
{
	Buttons[selectedButtonIndex].OnRelease();
}


void Menu::AddButton(std::string _name, ButtonCallbackFunction & fnc)
{
	Buttons.push_back(MButton(_name, { anchorPosition.x,(anchorPosition.y + (float)index * 50) }, font, { 200,40 }, sf::Color::White, fnc));
	index++;
}

void Menu::Draw(sf::RenderWindow & t_window) const
{
	for (auto const& item : Buttons)
	{
		t_window.draw(item.buttonShape);
		t_window.draw(item.buttonText);
	}
}
	

void Menu::EventListener(sf::Event & event)
{
	if (isActive)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			CycleDown();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			CycleUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			
		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)
		{
			PressButton();
		}
	}
	}

void Menu::Update()
{

}

void Menu::SetActive(bool val)
{
	isActive = val;
}

bool Menu::IsActive() const
{
	return isActive;
}
