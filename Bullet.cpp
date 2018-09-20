#include "Bullet.h"



Bullet::Bullet(sf::Vector2f t_position)
{
	Name = "Bullet";
	m_bulletSpsrite.setFillColor(sf::Color(0, 255, 200, 255));
	m_bulletSpsrite.setPosition(t_position);
	m_bulletSpsrite.setSize({ 5,10 });
	m_bulletSpsrite.setOrigin({ 2.5f,5 });
	box = AABB(m_bulletSpsrite.getPosition(), { 5,10 });
}


Bullet::~Bullet()
{
}

void Bullet::Draw(sf::RenderWindow & window) const
{
	window.draw(m_bulletSpsrite);
	
}

void Bullet::Update()
{
	m_bulletSpsrite.move({ 0,-8 });
	sf::Vector2f size = { 5,10 };
	sf::Vector2f pos = m_bulletSpsrite.getPosition();
	box.updatePosition(pos);
	if (m_bulletSpsrite.getPosition().y < 0)
	{
		IfDestroyed = true;
	}
}

bool Bullet::IsDestroyed()
{
	return false;
}

bool Bullet::CollisionCheck(ICollidable & other)
{
	return false;
}

void Bullet::OnCollisionEnter(ICollidable & other)
{
	std::cout << "Bullet Destroyed";
	IfDestroyed = true;
}
