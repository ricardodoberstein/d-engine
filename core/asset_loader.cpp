#include "asset_loader.h"

std::map<char*, ALLEGRO_BITMAP*> AssetLoader::assets;

void AssetLoader::load_asset(char* name)
{
  assets.insert(std::pair<char*, ALLEGRO_BITMAP*>(name, al_load_bitmap(name)));
}

ALLEGRO_BITMAP* AssetLoader::get_asset(char* name)
{
  return assets.at(name);
}