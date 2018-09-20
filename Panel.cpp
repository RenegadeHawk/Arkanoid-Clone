#include "Panel.h"



void Panel::Draw(sf::RenderWindow & t_window) const
{
	if(ifBG)
		t_window.draw(BackGroundPanel);
	
	for (auto const& item : HudTexts)
	{
		t_window.draw(item);
	}
	for (auto const& item : HUDElements)
	{
		
		t_window.draw(item.text);
	}
}

void Panel::Update()
{

	for (auto& item : HUDElements)
	{

		item.text.setString (item.valueName + " " + std::to_string(item.valueToWatch));
	}

	
	//text.setString(_text + " " + std::to_string(_valueToWatch));
	
}

void Panel::AddTextToPanel(std::string _text, sf::Vector2f _position)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setString(_text);
	text.setPosition(_position);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	
	HudTexts.push_back(text);
}

void Panel::AddHUDElement(std::string _text, sf::Vector2f _position,unsigned int & _valueToWatch)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setString(_text + " : " + std::to_string(_valueToWatch));
	text.setPosition(_position);
	text.setOrigin(0, 0);
	HUDElement el = HUDElement(text, _text, _valueToWatch);
	HUDElements.push_back(el);
}

void Panel::AddHintToPanel(std::string _text, sf::Vector2f _position, sf::Keyboard::Key _keyToListenFor)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(36);
	text.setFillColor(sf::Color::White);
	text.setString(_text);
	text.setPosition(_position);
	text.setOrigin(0, 0);
	Hint hint = Hint(text, _keyToListenFor);
	HintTexts.push_back(hint);
}

void Panel::HintEventListener(sf::Event & event)
{
	for (auto const& item : HintTexts)
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == item.keyToListenTo)
		{
			HintTexts.erase(HintTexts.begin());
		}
	}
}

void Panel::addBackground(sf::Vector2f t_size, sf::Color t_color)
{
	m_backgroundSprite.setPosition(1366 / 2, 768 / 2);
	m_backgroundSprite.setSize(t_size);
	m_backgroundSprite.setOrigin(t_size.x / 2, t_size.y / 2);
	m_backgroundSprite.setFillColor(t_color);
}

Panel::Panel()
{
}

Panel::Panel(sf::Font & _font):font(_font)
{
	BackGroundPanel.setSize({ 1366,768 });
	BackGroundPanel.setOrigin(1366 / 2, 768 / 2);
	BackGroundPanel.setPosition({ 1366 / 2,768 / 2 });
	BackGroundPanel.setFillColor(sf::Color(0, 0, 0, 255));
}


Panel::~Panel()
{
}
