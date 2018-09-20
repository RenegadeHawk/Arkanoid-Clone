#pragma once
#include "PowerUp.h"
#include "GameObject.h"
#include "PhysicsBody.h"
#include "ICollidable.h"
#include "Paddle.h"
#include <thread>
class Expand :public PowerUp
{
public:

	bool isDestroyed = false;



	Expand(sf::Vector2f t_position);

	~Expand();

	// Inherited via GameObject
	virtual void Draw(sf::RenderWindow & window) const override;
	virtual void Update() override;

	// Inherited via PowerUp
	virtual void Power(Paddle* paddle) override;


	// Inherited via ICollidable
	virtual bool CollisionCheck(ICollidable & other) override;
	virtual void OnCollisionEnter(ICollidable & other) override;
	virtual bool IsDestroyed() override;

	template <class T>
	T* GetComponent()
	{
		if (T* d = dynamic_cast<T*>(this))
		{

			return d;
		}
	}
private:

	Paddle* p_paddle = nullptr;
	void ApplyPower() override;

	

};

