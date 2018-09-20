#pragma once
#include "PowerUp.h"
#include "PhysicsBody.h"
#include "Paddle.h"
class FirePower :
	public PowerUp
{
	Paddle* paddle;
public:
	FirePower();
	FirePower(sf::Vector2f t_position);
	~FirePower();

	virtual void Power(Paddle* paddle) override;

	// Inherited via PowerUp
	virtual void Draw(sf::RenderWindow & window) const override;
	virtual void Update() override;
	virtual bool IsDestroyed() override;
	virtual bool CollisionCheck(ICollidable & other) override;
	virtual void OnCollisionEnter(ICollidable & other) override;

	// Inherited via PowerUp
	virtual void ApplyPower() override;
};

