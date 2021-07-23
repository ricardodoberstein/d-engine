#include <gtest/gtest.h>
#include "../core/scene.h"
#include "../core/gameobject.h"

TEST(Scene, scene_constructor)
{
  Scene *scene = new Scene("test");
  EXPECT_EQ(scene->get_name(), "test");
  delete scene;
}

TEST(Scene, scene_add_object)
{
  Scene *scene = new Scene("test");
  GameObject *go = new GameObject("object1");

  EXPECT_NO_THROW(scene->add_gameobject(go));

  delete scene;
}

TEST(Scene, scene_find_object_by_name)
{
  Scene *scene = new Scene("test");
  GameObject *go1 = new GameObject("object1");
  GameObject *go2 = new GameObject("object2");
  scene->add_gameobject(go1);
  scene->add_gameobject(go2);

  EXPECT_EQ(scene->find_gameobject_by_name("object1"), go1);
  EXPECT_EQ(scene->find_gameobject_by_name("object3"), nullptr);

  delete scene;
}
