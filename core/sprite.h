#include "component.h"
#include "asset_loader.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#ifndef SPRITE_H
#define SPRITE_H

class Sprite : public Component
{
public:
  Sprite();
  Sprite(char *asset_name);
  ~Sprite();

  virtual void render();

private:
  ALLEGRO_BITMAP *bitmap;
};

#endif