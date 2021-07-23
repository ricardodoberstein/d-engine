#include <string>
#include <map>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#ifndef ASSET_LOADER_H
#define ASSET_LOADER_H

class AssetLoader
{
public:
  static std::map<char*, ALLEGRO_BITMAP*> assets;
  static void load_asset(char* name);
  static ALLEGRO_BITMAP* get_asset(char* name);
};

#endif