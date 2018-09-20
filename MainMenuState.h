#pragma once
#include <SFML/Audio.hpp>
#include "State.h"
#include "Menu.h"
#include "Ball.h"
#include "ICollidable.h"
#include <iostream>
#include "GameParameters.h"

class MainMenuState : public State
{
private:
	sf::Sprite m_titleSprite;
	sf::Texture m_titelTexture;
	sf::Music music;
	Ball ball;
	std::vector<std::shared_ptr<GameObject>>    uniqGameObjectContainer;
	Menu* currentMenu;
	Menu* mainMenu;
	Menu* exitMenu;
	Menu* optionsMenu;
	Menu* TestMenu;
	void HandleWindowCollisions();
	void ConstructMainMenu();
	void ConstructExitMenu();
	void StartGame();
	void DummyExec()
	{
		std::cout <<"Dummy Callback";
	}

public:
	MainMenuState();


	~MainMenuState();
	// Inherited via State
	virtual void UpdateEvents() override;

	void QuitGame();

	virtual void Initialize() override;
	virtual void UpdateDisplay() override;
	virtual void HandleEvents() override;

	
};

