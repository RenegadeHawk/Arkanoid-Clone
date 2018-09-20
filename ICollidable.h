#pragma once
#include <iostream>
#include "AABB.h"
#include "Scene.h"
class ICollidable
{
private:

public:
	std::string Name = "";
	bool isDestroyed = false;
	virtual bool IsDestroyed() = 0;
	virtual bool CollisionCheck(ICollidable& other) = 0;
	virtual void OnCollisionEnter(ICollidable& other) = 0;
	AABB box;
	virtual	~ICollidable()
	{

	}
};

