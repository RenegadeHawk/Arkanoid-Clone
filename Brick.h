#pragma once
#include <SFML\Graphics.hpp>
#include "AABB.h"
#include "GameObject.h"
#include <iostream>
#include "ICollidable.h"
#include "GameParameters.h"
class Brick : public GameObject, public ICollidable
{
public:


	Brick();

	~Brick();
	
	Brick(float t_xPosition, float t_yPosition, sf::Color t_color, int t_hp, std::string t_name);

	sf::Vector2f getPosition();

	int getScore();

	virtual void recieveDamage(float damage);


#pragma region Inherited from GameObject interface
	void Draw(sf::RenderWindow & window) const;

	void Update();
#pragma endregion

#pragma region Inherited from ICollidable interface
	bool CollisionCheck(ICollidable& other) override;

	void OnCollisionEnter(ICollidable& other) override;

	virtual bool IsDestroyed() override;
#pragma endregion

	template <class T>
	T* GetComponent()
	{
		if (T* d = dynamic_cast<T*>(this))
		{

			return d;
		}
	}
	
protected :

	virtual void Destroy();

private:

	sf::RectangleShape m_sprite;

	sf::Vector2f m_position;
	
	sf::Vector2f m_size;
	
	sf::Color m_color;
	
	std::string m_name;
	
	float m_width = 50;

	float m_height = 15;

	float m_HP = 0;
	
	int m_score = 0;

	bool isDestroyed = false;

	void makeSpriteLighter();
};

