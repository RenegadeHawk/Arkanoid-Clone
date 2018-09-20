#pragma once
#include <SFML/Graphics.hpp>
class PhysicsBody
{
public:
	PhysicsBody();
	~PhysicsBody();
	sf::Vector2f Velocity = { 0,0 };


};

