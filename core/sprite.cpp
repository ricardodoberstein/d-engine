#include "sprite.h"

Sprite::Sprite()
{
}

Sprite::Sprite(char *asset_name)
{
  this->bitmap = AssetLoader::get_asset(asset_name);
}

Sprite::~Sprite() {}

void Sprite::render()
{
  al_draw_bitmap(bitmap, 100, 100, 0);
}