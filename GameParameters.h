#pragma once
#include <SFML\Graphics.hpp>
#include "SoundPlayer.h"
#include <vector>
class State;
enum States
{
	MAINMENU,
	GAME
};
class GameParameters
{

private:
	static GameParameters *_instance;
	sf::RenderWindow* window;
	sf::Font* font;
	sf::Event* event;
	SoundPlayer* p_soundPlayer;
	std::vector<State*> myGameStates;
	GameParameters(float v = 0)
	{
		window = nullptr;
		font = nullptr;
		event = nullptr;
		p_soundPlayer = new SoundPlayer();
	}
	
public:

	sf::RenderWindow& getWindow()
	{
		return *window;
	}
	void setWindow(sf::RenderWindow& _window)
	{
		window = &_window;
	}

	sf::Font& getFont()
	{
		return *font;
	}

	void setFont(sf::Font& _font)
	{
		font = &_font;
	}
	sf::Event& getEvent()
	{
		return *event;
	}
	SoundPlayer& getSoundPlayer()
	{
		return *p_soundPlayer;
	}
	void setEvent(sf::Event& _event)
	{
		event = &_event;
	}
	static GameParameters* instance()
	{
		if (!_instance)
			_instance = new GameParameters;
		return _instance;
	}
};

