#include <gtest/gtest.h>
#include "../core/gameobject.h"
#include "../core/transform.h"
#include "../core/sprite.h"

TEST(GameObject, gameobject_has_transform)
{
  GameObject *go = new GameObject();
  ASSERT_EQ(go->transform->position->x, 0);
  ASSERT_EQ(go->transform->position->y, 0);
  delete go;
}

TEST(GameObject, gameobject_has_a_component_transform)
{
  GameObject *go = new GameObject();
  ASSERT_TRUE(go->get_component<Transform>() != nullptr);
  delete go;
}

TEST(GameObject, gameobject_add_sprite_component)
{
  GameObject *go = new GameObject();
  Sprite *sprite = new Sprite();
  go->add_component(sprite);
  ASSERT_EQ(go->get_component<Sprite>(), sprite);
}