#include "transform.h"
#include <vector>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
  GameObject();
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

  void add_component(Component *component);

private:
  std::vector<Component *> components;
};

#endif