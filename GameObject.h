#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Timer.h"

class GameObject
{

public:
	bool IfDestroyed = false;
	virtual void Draw(sf::RenderWindow & t_window) const = 0;
	virtual void Update() = 0;
};

