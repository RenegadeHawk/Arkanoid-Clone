#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

Scene::Scene(std::string name)
	: m_name(name) {}

void Scene::AddObjectToScene(std::shared_ptr<GameObject> drawableObject)
{
	//SceneObjects.push_back(drawableObject);
}

void Scene::RemoveObjectFromScene(std::shared_ptr<GameObject> removedObject)
{
	//SceneObjects.erase(std::remove(SceneObjects.begin(), SceneObjects.end(), removedObject), SceneObjects.end());
}


