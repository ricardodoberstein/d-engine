#include <iostream>
#include <string>
#include <vector>
#include "gameobject.h"

#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
  Scene(std::string name);
  ~Scene();

  std::string get_name();
  void add_gameobject(GameObject *object);
  GameObject* find_gameobject_by_name(std::string name);
  std::vector<GameObject *> get_objects();

private:
  std::string name;
  std::vector<GameObject *> objects;
};

#endif