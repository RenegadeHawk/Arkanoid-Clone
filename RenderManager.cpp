#include "RenderManager.h"



RenderManager::RenderManager() 
{

}


RenderManager::~RenderManager()
{
}

void RenderManager::render()
{
	std::vector<std::unique_ptr<GameObject>>::iterator it;
	for (it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
	{
		it->get()->Draw(GameParameters::instance()->getWindow());
	}
}
