#pragma once
#include "Brick.h"
#include "PowerUp.h"
#include "Expand.h"
#include "FirePower.h"
enum Powers
{
	EXPANDPOWER,
	FIREPOWER,
	FIREBALL
};
class SpecialBrick :
	public Brick
{
	
public:
	Powers powerType;
	SpecialBrick()
	{

	}

	SpecialBrick(float dx, float dy, sf::Color col, int _hp, Powers targetType) : Brick(dx, dy, col, _hp,"SP"),powerType(targetType)
	{
		
	}

	bool IsDestroyed() override;
	void Destroy() override;
	~SpecialBrick();
};

