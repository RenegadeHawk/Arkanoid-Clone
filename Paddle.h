#pragma once
#include "Ball.h"
#include <SFML\Graphics.hpp>
#include "AABB.h"
#include "ICollidable.h"
#include "GameObject.h"
#include <iostream>
#include "Timer.h"
#include "PhysicsBody.h"
#include "GameParameters.h"
#include "Expand.h"
#include "Bullet.h"
#include <thread>
class Ball;
class Paddle : public GameObject, ICollidable,PhysicsBody
{
private:
	
	Ball* p_ball;

	sf::Texture m_texture;

	sf::Vector2f m_size = { 0,0 };

	std::vector<std::unique_ptr<Bullet>>* m_bulletList;

	float m_paddleVelocity = 8;

	void move(float t_deltaX);

	void startBulletFiringRoutine();

public:
	void initializeFiring();
	sf::Sprite Sprite;
	bool isBallAttached = true;
	bool isInputLocked = false;
	Paddle();
	~Paddle();

	sf::Vector2f velocity;

	Paddle(sf::Vector2f t_position, Ball * t_ball, std::vector<std::unique_ptr<Bullet>>* t_instance);


	

	void SetSize(float t_percent);

	sf::Vector2f getSize() const;


	void Update() override;
	
	void Draw(sf::RenderWindow & window) const override;



	template <class T>
	T* GetComponent()
	{
		if (T* d = dynamic_cast<T*>(this))
		{

			return d;
		}
	}

	bool CollisionCheck(ICollidable& other) override;
	
	void OnCollisionEnter(ICollidable& other) override;

	
	// Inherited via ICollidable
	virtual bool IsDestroyed() override;
};

