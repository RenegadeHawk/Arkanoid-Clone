#pragma once
#include <SFML\Graphics.hpp>
#include "AABB.h"
#include "ICollidable.h"
#include "GameObject.h"
#include <iostream>
#include "Timer.h"
#include "PhysicsBody.h"
#include "Brick.h"
class Ball : public GameObject,ICollidable,PhysicsBody
{

public:
	Ball();

	Ball(sf::Vector2f t_position);

	~Ball();
	void move(float t_deltaX);

	void launchBall();

	void changeTexture(const std::string t_path);

	sf::Vector2f getPosition() const;

	sf::Vector2f getSize() const;

	void setPosition(const sf::Vector2f& t_position);

	void setVelocity(const sf::Vector2f t_velocity);

	void setDamage(const float t_damage);


#pragma region Inherited from GameObject interface
	//Inherited from GameObject interface
	void Update() override;

	void Draw(sf::RenderWindow & window) const override;
#pragma endregion

#pragma region Inherited from ICollidable interface
	//inherited from ICollidable interface
	bool CollisionCheck(ICollidable& other) override;

	void OnCollisionEnter(ICollidable& other) override;

	virtual bool IsDestroyed() override;
#pragma endregion


	//Template method to get reference to any of the implemented interfaces or the classes it inherits from
	template <class T>
	T* GetComponent()
	{
		if (T* d = dynamic_cast<T*>(this))
		{
			return d;
		}
	}



private:

	sf::Sprite m_sprite;

	sf::Texture	m_texture;
	
	sf::Texture	m_firedTexture;
	
	//Initial postion of the sprite : provided via constructor
	sf::Vector2f m_position;

	sf::Vector2f m_size;

	//Damage dealt to the brick
	float m_damage = 1.0f;

	//Default Velocity of the ball : set via setVelocity method
	float m_ballVelocity = 4;

	//Private clock and time to use to smoothen out movement
	sf::Clock m_timer;

	sf::Time m_tickRate;

	


};
