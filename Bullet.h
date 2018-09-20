#pragma once
#include "GameObject.h"
#include "ICollidable.h"
class Bullet :
	public GameObject,public ICollidable
{
public:
	Bullet(sf::Vector2f t_position);
	~Bullet();

	// Inherited via GameObject
	virtual void Draw(sf::RenderWindow & window) const override;
	virtual void Update() override;

	// Inherited via ICollidable
	virtual bool IsDestroyed() override;
	virtual bool CollisionCheck(ICollidable & other) override;
	virtual void OnCollisionEnter(ICollidable & other) override;

private:
	sf::RectangleShape m_bulletSpsrite;


};

