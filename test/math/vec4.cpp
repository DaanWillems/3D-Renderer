//
// Created by solaw on 13/01/2019.
//
#include <gtest/gtest.h>
#include <math/mat4.h>

// Tests vec.
TEST(Vector4, NormalizeVector) {
  math::vec4 v{0, 0, 2};
  v = v.normalize();
  EXPECT_EQ(v.x(), 0);
  EXPECT_EQ(v.y(), 0);
  EXPECT_EQ(v.z(), 1);
}


TEST(Vector4, CrossProduct) {
  math::vec4 v1{0, 0, 2};
  math::vec4 v2{0, 0, 2};

  auto result {v1.cross(v2)};

  EXPECT_EQ(result.x(), 0);
  EXPECT_EQ(result.y(), 0);
  EXPECT_EQ(result.z(), 0);

  v1 = {1, 0, 2};
  v2 = {0, 2, 0};

  result = v1.cross(v2);

  EXPECT_EQ(result.x(), -4);
  EXPECT_EQ(result.y(), 0);
  EXPECT_EQ(result.z(), 2);
}


TEST(Vector4, DotProduct2D) {
  math::vec4 v1{1, 0};
  math::vec4 v2{1, 0};
  auto result{v1.dot(v2)};

  EXPECT_EQ(result, 1);

  v1 = {1, 0};
  v2 = {0, 1};
  result = v1.dot(v2);

  EXPECT_EQ(result, 0);

  v1 = {0, 1};
  v2 = {0, 1};
  result = v1.dot(v2);

  EXPECT_EQ(result, 1);
}


