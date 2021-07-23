#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
  Component();
  virtual ~Component();

  virtual void start();
  virtual void render();
};

#endif