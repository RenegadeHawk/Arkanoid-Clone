#include "Expand.h"


//
//Expand::Expand()
//{
//}





void Expand::ApplyPower()
{
	std::cout << "Powered Up routine";
	//sf::Vector2f initialSize = paddle->Sprite.getSize();
	//sf::Color initialColor = paddle->sprite.getFillColor();
	//paddle->sprite.setFillColor(sf::Color(12, 255, 60, 255));
	paddle->SetSize(0.2f);
	sf::Clock clk;
	while (clk.getElapsedTime() < sf::seconds(10))
	{

	}
	paddle->SetSize(-0.2f);
	//paddle->sprite.setFillColor(initialColor);
	//paddle->SetSize(initialSize);
}

Expand::Expand(sf::Vector2f t_position) : PowerUp(t_position, PowerupType::PADDLE_POWER, "Expand.png")
{

}
Expand::~Expand()
{
	std::cout << "destroyed powerup";
}

void Expand::Draw(sf::RenderWindow & window) const
{
	window.draw(Sprite);
}

void Expand::Update()
{
	Sprite.move(Velocity*Timer::instance()->get_value());
	Sprite.setTexture(texture);
	box.updatePosition(Sprite.getPosition());
}

void Expand::Power(Paddle* t_paddle)
{
	p_paddle = t_paddle;
	std::thread powerUpThread(&Expand::ApplyPower, this);
	powerUpThread.detach();
}

bool Expand::CollisionCheck(ICollidable & other)
{
	return false;
}

void Expand::OnCollisionEnter(ICollidable & other)
{
	isDestroyed = true;
	

	
}

bool Expand::IsDestroyed()
{
	return false;
}
