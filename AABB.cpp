#include "AABB.h"
#include <iostream>
#include "GameParameters.h"

AABB::AABB()
{

}

AABB::AABB(sf::Vector2f t_position, sf::Vector2f t_size) :m_size(t_size)
{
	m_lowerLeft = { t_position.x - t_size.x / 2, t_position.y + t_size.y / 2 };
	m_upperRight = { t_position.x + t_size.x / 2, t_position.y - t_size.y / 2 };
}

void AABB::updatePosition(const sf::Vector2f& t_position)
{
	m_lowerLeft = { t_position.x - m_size.x / 2,t_position.y + m_size.y / 2 };
	m_upperRight = { t_position.x + m_size.x / 2,t_position.y - m_size.y / 2 };

	//sf::RectangleShape sp;
	//sp.setPosition(t_position);
	//sp.setSize(m_size);
	//sp.setOrigin({ m_size.x/2,m_size.y/2 });
	//sp.setFillColor(sf::Color(0, 255, 0, 100));
	//GameParameters::instance()->getWindow().draw(sp);
}

sf::Vector2f AABB::getLowerLeft() const
{
	return m_lowerLeft;
}

sf::Vector2f AABB::getUpperRight() const 
{
	return m_upperRight;
}

AABB::~AABB()
{
	std::cout << "AABB instance deleted" << std::endl;
}