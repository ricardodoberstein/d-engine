#include "transform.h"
#include <vector>
#include <string>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
  GameObject();
  GameObject(std::string name);
  ~GameObject();

  Transform *transform;

  template <class T>
  T *get_component()
  {
    for (int i = 0; i < this->components.size(); i += 1)
    {
      T *t = dynamic_cast<T *>(this->components[i]);
      if (t != nullptr)
        return t;
    }

    return nullptr;
  }

  template <class T>
  std::vector<T*> get_components()
  {
    std::vector<T*> components;

    for (int i = 0; i < this->components.size(); i += 1)
    {
      T *t = dynamic_cast<T *>(this->components[i]);
      if (t != nullptr)
        components.push_back(t);
    }

    return components;
  }

  void add_component(Component *component);
  std::string get_name();

private:
  std::string name = "";
  std::vector<Component *> components;
};

#endif