#include "FirePower.h"



FirePower::FirePower()
{
}

FirePower::FirePower(sf::Vector2f t_position)
	: PowerUp(t_position, PowerupType::PADDLE_POWER, "Fire.png")
{

}

FirePower::~FirePower()
{
}

void FirePower::Power(Paddle * _paddle)
{
	paddle = _paddle;
	std::thread powerUpThread(&FirePower::ApplyPower, this);
	powerUpThread.detach();
}

void FirePower::Draw(sf::RenderWindow & window) const
{
	window.draw(Sprite);
}

void FirePower::Update()
{
	Sprite.move(Velocity*Timer::instance()->get_value());
	Sprite.setTexture(texture);
	box.updatePosition(Sprite.getPosition());
}

bool FirePower::IsDestroyed()
{
	return false;
}

bool FirePower::CollisionCheck(ICollidable & other)
{
	return false;
}

void FirePower::OnCollisionEnter(ICollidable & other)
{
}

void FirePower::ApplyPower()
{
	paddle->initializeFiring();
}
