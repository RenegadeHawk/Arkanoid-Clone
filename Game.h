#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "StateManager.h"
#include "RenderManager.h"
enum Statef {
	STATE_MENU,
	STATE_GAME,
	STATE_EXIT,
	STATE_FINISHED
};

class StateManager;
class Game
{
public:

	Game(sf::RenderWindow& _window);
	void Update();
	void HandleEvents(sf::Event& event);

	~Game();
	RenderManager* getRenderManager();
private: 
	
	StateManager*  m_stateManager = nullptr;
	RenderManager* m_renderManager = nullptr;
	bool										ifHintShown = false;

	//Font variable to hold the font file
	sf::Font									font;

	//window to draw objects on
	sf::RenderWindow&							window;


	//start
	void										Start();
	//Load the font from file
	void										LoadFont();
	//





};

