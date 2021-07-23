#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
  Component();
  virtual ~Component();

  virtual void start() = 0;
  virtual void render() = 0;
};

#endif