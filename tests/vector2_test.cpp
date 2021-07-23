#include <gtest/gtest.h>
#include "../core/vector2.h"

TEST(Vector2, Constructor_x)
{
  Vector2 *vector2 = new Vector2(10, 15);
  ASSERT_EQ(vector2->x, 10);
  delete vector2;
}

TEST(Vector2, Constructor_y)
{
  Vector2 *vector2 = new Vector2(10, 15);
  ASSERT_EQ(vector2->y, 15);
  delete vector2;
}