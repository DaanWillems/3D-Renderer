//
// Created by solaw on 13/01/2019.
//
#include <gtest/gtest.h>
#include <math/mat4.h>

// Tests vec.
TEST(vectorTest, NormalizeVector) {
  math::vec4 v{0, 0, 2};
  v = v.normalize();
  EXPECT_EQ(v.length(), 1);
  EXPECT_EQ(v.x(), 0);
  EXPECT_EQ(v.y(), 0);
  EXPECT_EQ(v.z(), 1);
}


