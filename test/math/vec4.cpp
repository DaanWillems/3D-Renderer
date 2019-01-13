//
// Created by solaw on 13/01/2019.
//
#include <gtest/gtest.h>
#include <math/mat4.h>

TEST(Vector4, Add_Operator_Positive) {
  math::vec4 v1{5, 10, 15};
  math::vec4 v2{1, 2, 3};
  auto result{v1 + v2};
  EXPECT_EQ(result.x(), 6);
  EXPECT_EQ(result.y(), 12);
  EXPECT_EQ(result.z(), 18);
}

TEST(Vector4, Add_Operator_Negative) {
  math::vec4 v1{5, 10, 15};
  math::vec4 v2{-1, -2, -3};
  auto result{v1 + v2};
  EXPECT_EQ(result.x(), 4);
  EXPECT_EQ(result.y(), 8);
  EXPECT_EQ(result.z(), 12);
}

TEST(Vector4, Subtract_Operator_Positive) {
  math::vec4 v1{5, 10, 15};
  math::vec4 v2{1, 2, 3};
  auto result{v1 - v2};
  EXPECT_EQ(result.x(), 4);
  EXPECT_EQ(result.y(), 8);
  EXPECT_EQ(result.z(), 12);
}

TEST(Vector4, Subtract_Operator_Negative) {
  math::vec4 v1{5, 10, 15};
  math::vec4 v2{-1, -2, -3};
  auto result{v1 - v2};
  EXPECT_EQ(result.x(), 6);
  EXPECT_EQ(result.y(), 12);
  EXPECT_EQ(result.z(), 18);
}

TEST(Vector4, Add_Positive) {
  math::vec4 v1{5, 10, 15};
  math::vec4 v2{1, 2, 3};
  v1.add(v2);
  EXPECT_EQ(v1.x(), 6);
  EXPECT_EQ(v1.y(), 12);
  EXPECT_EQ(v1.z(), 18);
}

TEST(Vector4, Add_Negative) {
  math::vec4 v1{5, 10, 15};
  math::vec4 v2{-1, -2, -3};
  v1.add(v2);
  EXPECT_EQ(v1.x(), 4);
  EXPECT_EQ(v1.y(), 8);
  EXPECT_EQ(v1.z(), 12);
}

TEST(Vector4, Subtract_Positive) {
  math::vec4 v1{5, 10, 15};
  math::vec4 v2{1, 2, 3};
  v1.substract(v2);
  EXPECT_EQ(v1.x(), 4);
  EXPECT_EQ(v1.y(), 8);
  EXPECT_EQ(v1.z(), 12);
}

TEST(Vector4, Subtract_Negative) {
  math::vec4 v1{5, 10, 15};
  math::vec4 v2{-1, -2, -3};
  v1.substract(v2);
  EXPECT_EQ(v1.x(), 6);
  EXPECT_EQ(v1.y(), 12);
  EXPECT_EQ(v1.z(), 18);
}

TEST(Vector4, DISABLED_Multiply_Matrix) {
}

TEST(Vector4, Multiply_Positive_Float) {
  math::vec4 v{5, 10, 15};
  float scalar{7};
  auto result{v * scalar};
  EXPECT_EQ(result.x(), 35);
  EXPECT_EQ(result.y(), 70);
  EXPECT_EQ(result.z(), 105);
}

TEST(Vector4, Multiply_Negative_Float) {
  math::vec4 v{5, 10, 15};
  float scalar{-7};
  auto result{v * scalar};
  EXPECT_EQ(result.x(), -35);
  EXPECT_EQ(result.y(), -70);
  EXPECT_EQ(result.z(), -105);
}

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


TEST(Vector4, Length) {
  math::vec4 v1{1, 1, 1, 1};

  EXPECT_EQ(v1.length(), 1.73205078f);

  math::vec4 v2{1, -1, -1, 1};

  EXPECT_EQ(v2.length(), 1.73205078f);
}


TEST(Vector4, Truncate) {
  math::vec4 v1{1, 1, 1, 1};

  EXPECT_EQ(v1.length(), 1.73205078f);

  math::vec4 v2{1, -1, -1, 1};

  EXPECT_EQ(v2.length(), 1.73205078f);
}


TEST(Vector4, Dist) {
  math::vec4 v1{5, 10, 15};
  math::vec4 v2{-1, -2, -3};

  float result{math::dist(v1, v2)};
  EXPECT_EQ(result, 22.4499435f);
}


