#pragma once
#include <SFML\Graphics.hpp>
#include "MButton.h"
#include "GameObject.h"
#include <functional>

class Menu : public GameObject
{
private:
#pragma region Private Variables
	int										selectedButtonIndex = -1;
	int										index = 0;
	bool									isActive = false;
	sf::Font								font;
	sf::Vector2f							anchorPosition;
#pragma endregion
#pragma region Private Methods
	void									CycleDown();
	void									CycleUp();
	void									PressButton();
	void									ReleaseButton();
#pragma endregion


public:
											Menu();
											Menu(float _dx, float _dy, sf::Font & _font);
											~Menu();
	std::vector<MButton>					Buttons;

	template<typename T>
	void									AddButton(std::string _name, void(T::*function)(), T* inst);
	void									AddButton(std::string _name, ButtonCallbackFunction& fnc);
	void									Draw(sf::RenderWindow & window) const;
	void									EventListener(sf::Event& _event);
	void									Update();
	void									SetActive(bool _val);
	bool									IsActive() const;

	template <class T>

	T* GetComponent()
	{
		if (T* d = dynamic_cast<T*>(this))
		{

			return d;
		}
	}
};

template<typename T>
inline void Menu::AddButton(std::string _name, void(T::* function)(), T * inst)
{
	ButtonCallbackFunction f = std::bind(function, inst);
	Buttons.push_back(MButton(_name, { anchorPosition.x,(anchorPosition.y + (float)index * 50) }, font, { 200,40 }, sf::Color::White,f));
	index++;
}

