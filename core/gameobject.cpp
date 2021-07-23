#include "gameobject.h"

GameObject::GameObject()
{
  this->transform = new Transform();
  this->components.push_back(this->transform);
}

GameObject::GameObject(std::string name)
{
  this->name = name;
  this->transform = new Transform();
  this->components.push_back(this->transform);
}

GameObject::~GameObject()
{
}

void GameObject::add_component(Component *component)
{
  this->components.push_back(component);
}

std::string GameObject::get_name()
{
  return this->name;
}