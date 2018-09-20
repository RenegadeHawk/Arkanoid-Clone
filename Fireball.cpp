#include "Fireball.h"



Fireball::Fireball()
{
}

Fireball::Fireball(sf::Vector2f t_position)
	: PowerUp(t_position, PowerupType::BALL_POWER, "Fireball.png")
{

}


Fireball::~Fireball()
{
}

void Fireball::Power(Ball * t_ball)
{
	ball = t_ball;
	std::thread powerUpThread(&Fireball::ApplyPower, this);
	powerUpThread.detach();
}

void Fireball::Draw(sf::RenderWindow & window) const
{
	window.draw(Sprite);
}

void Fireball::Update()
{
	Sprite.move(Velocity*Timer::instance()->get_value());
	Sprite.setTexture(texture);
	box.updatePosition(Sprite.getPosition());
}

bool Fireball::IsDestroyed()
{
	return false;
}

bool Fireball::CollisionCheck(ICollidable & other)
{
	return false;
}

void Fireball::OnCollisionEnter(ICollidable & other)
{
}

void Fireball::ApplyPower()
{
	ball->setDamage(5);
	ball->changeTexture("Firedball.png");
	sf::Clock clk;
	while (clk.getElapsedTime() < sf::seconds(10))
	{

	}
	ball->setDamage(1);
	ball->changeTexture("Ball.png");
}
