#pragma once
#include <SFML/Graphics.hpp>

class AABB
{

public:
	AABB();

	~AABB();

	AABB(sf::Vector2f t_pos, sf::Vector2f t_size);

	//getters
	sf::Vector2f getLowerLeft() const;

	sf::Vector2f getUpperRight() const;

	//should update position of the bounding box whichever class is using it
	void updatePosition(const sf::Vector2f& t_position);


private:

	//Size of the bounding box (width,height)
	sf::Vector2f m_size = { 0,0 };

	//Lowerleft point of the bounding box
	sf::Vector2f m_lowerLeft = { 0,0 };

	//Upperright point of the bounding box
	sf::Vector2f m_upperRight = { 0,0 };


};
inline bool ifColliding(const AABB& box0,const AABB& box1)
{
	return box0.getUpperRight().x >= box1.getLowerLeft().x && box0.getLowerLeft().x <= box1.getUpperRight().x && box0.getUpperRight().y <= box1.getLowerLeft().y && box0.getLowerLeft().y >= box1.getUpperRight().y;
}

