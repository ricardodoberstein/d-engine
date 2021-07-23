#include "gameobject.h"

GameObject::GameObject()
{
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