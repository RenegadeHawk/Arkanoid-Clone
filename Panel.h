#pragma once
#include "GameObject.h"
#include <map>
class Panel : public GameObject
{
	struct Hint 
	{
		sf::Keyboard::Key	keyToListenTo;
		sf::Text			text;
		Hint(sf::Text _text, sf::Keyboard::Key	_keyToListenTo) :
		text(_text),
		keyToListenTo(_keyToListenTo)
		{

		}
	};
	struct HUDElement
	{
		sf::Text text;
		std::string valueName;
		unsigned int& valueToWatch;
		HUDElement(sf::Text _text, std::string _valueName, unsigned int & _valueToWatch) : 
		text(_text),
		valueToWatch(_valueToWatch),
		valueName(_valueName)
		{

		}
	};


private:
	int index = 0;
	sf::Font font;
	sf::RectangleShape m_backgroundSprite;
public:
	void									Draw(sf::RenderWindow & window) const override;
	void									Update();

	bool									ifBG = false;
	sf::RectangleShape						BackGroundPanel;

	std::vector<sf::Text>					HudTexts;
	void									AddTextToPanel(std::string _text, sf::Vector2f _position);
	void									AddHUDElement(std::string _text, sf::Vector2f _position,unsigned int& valueToWatch);
	std::vector<HUDElement>					HUDElements;

	
	std::vector<Hint>						HintTexts;
	void									AddHintToPanel(std::string _text, sf::Vector2f _position,sf::Keyboard::Key keyToListenFor);
	void									HintEventListener(sf::Event& event);
	void addBackground(sf::Vector2f t_size, sf::Color t_color);



	Panel();
	Panel(sf::Font& _font);
	~Panel();
	
};

