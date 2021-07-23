#include "vector2.h"
#include "component.h"

#ifndef TRANSFORM_H
#define TRANSFORM_H

class Transform : public Component
{
public:
  Transform();
  ~Transform();

  void render() override;
  void start() override;
  Vector2 *position;
};

#endif