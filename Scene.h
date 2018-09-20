#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include "GameObject.h"
class GameObject;
class Scene
{
private:
	std::string m_name;
	 
public:
	
	Scene();
	~Scene();
	Scene(std::string name);
	std::vector<std::unique_ptr<GameObject>> SceneObjects;

	void AddObjectToScene(std::shared_ptr<GameObject> drawableObject);
	void RemoveObjectFromScene(std::shared_ptr<GameObject> removedObject);

};

