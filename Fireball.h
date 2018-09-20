#pragma once
#include "PowerUp.h"
#include "Ball.h"
class Fireball: public PowerUp
{
public:
	Ball * ball;
	Fireball();
	Fireball(sf::Vector2f t_position);
	~Fireball();
	void Power(Ball* t_ball) override;
	// Inherited via PowerUp

	virtual void Draw(sf::RenderWindow & window) const override;
	virtual void Update() override;

	virtual bool IsDestroyed() override;
	virtual bool CollisionCheck(ICollidable & other) override;
	virtual void OnCollisionEnter(ICollidable & other) override;
	virtual void ApplyPower() override;
};

