#include "scene.h"

Scene::Scene(std::string name)
{
  this->name = name;
}

Scene::~Scene()
{
  for (int i = 0; i < this->objects.size(); i += 1)
  {
    delete this->objects[i];
  }
}

std::string Scene::get_name()
{
  return this->name;
}

void Scene::add_gameobject(GameObject *object)
{
  this->objects.push_back(object);
}

GameObject* Scene::find_gameobject_by_name(std::string name)
{
  for (int i = 0; i < this->objects.size(); i += 1)
  {
    if (this->objects[i]->get_name() == name)
    {
      return this->objects[i];
    }
  }

  return nullptr;
}

std::vector<GameObject *> Scene::get_objects()
{
  return this->objects;
}