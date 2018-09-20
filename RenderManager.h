#pragma once
#include <SFML/Graphics.hpp>
#include "GameParameters.h"
#include "GameObject.h"
#include <vector>
#include <memory>
class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	void render();

private:
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
};

