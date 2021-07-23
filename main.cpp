#include <iostream>
#include "core/d_engine.h"
#include "core/gameobject.h"
#include "core/sprite.h"
#include "core/scene.h"
#include "core/asset_loader.h"

int main()
{
  // Basic setup, constructing engine. Setting resolution of screen.
  DEngine *engine = new DEngine();
  engine->set_resolution(1024, 768);

  // Loading basic assets by name.
  AssetLoader::load_asset("plane.png");

  // Creating a Scene, necessary to add objects to the screen.
  Scene *scene = new Scene("test_scene");

  // Creating a basic object, attaching a sprite to it and setting position to x: 100, y: 100 on the screen.
  GameObject *go = new GameObject("obj");
  Sprite *sprite = new Sprite("plane.png");
  go->add_component(sprite);
  go->transform->position->x = 100;
  go->transform->position->y = 100;

  // Attaching the created object above to the scene for rendering.
  scene->add_gameobject(go);

  // Attaching the Scene to the engine for rendering.
  engine->add_scene(scene);

  // Happy Stuff.
  engine->run();
  delete engine;
}