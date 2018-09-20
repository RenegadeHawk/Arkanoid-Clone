#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "ICollidable.h"
#include "PhysicsBody.h"
#include <thread>
class Paddle;
class Ball;
enum PowerupType
{
	PADDLE_POWER,
	BALL_POWER
};
class PowerUp :public GameObject, public ICollidable,protected PhysicsBody
{
	
protected:
	sf::Sprite Sprite;
	sf::Texture texture;
public:
	PowerupType type;
	PowerUp();

	PowerUp(sf::Vector2f _position, PowerupType _targetType,std::string _fileName) : type(_targetType)
	{
		Name = "Collectible";
		Velocity = { 0,5 };
		texture.loadFromFile(_fileName);
		Sprite.setTexture(texture);
		Sprite.setColor(sf::Color(255, 255, 255, 200));
		Sprite.setPosition(_position);
		
		sf::Vector2f scale = { 0.08f,0.08f };
		Sprite.setScale(scale);
		sf::Vector2f size = (sf::Vector2f)Sprite.getTexture()->getSize();
		Sprite.setOrigin({size.x/2,size.y/2});
		box = AABB(Sprite.getPosition(), { size.x*scale.x,size.y*scale.y });
	}



	Paddle * paddle = nullptr;
	virtual void Power(Paddle* paddle)
	{
		//
	}
	virtual void Power(Ball* paddle)
	{
		//
	}
	virtual void ApplyPower() = 0;
	virtual ~PowerUp();
};

