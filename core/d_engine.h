#ifndef D_ENGINE_H
#define D_ENGINE_H

#include<iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "scene.h"
#include <vector>
#include "sprite.h"
#include "component.h"
#include "gameobject.h"

class DEngine
{
public:
  DEngine();
  ~DEngine();

  void run();
  void set_resolution(int x, int y);
  void add_scene(Scene* scene);

private:
  ALLEGRO_TIMER *timer;
  ALLEGRO_EVENT_QUEUE *queue;
  ALLEGRO_FONT *font;
  ALLEGRO_DISPLAY *disp;
  ALLEGRO_EVENT event;

  void must_init(bool test, const char *description);

  std::vector<Scene*> scenes;
};

#endif