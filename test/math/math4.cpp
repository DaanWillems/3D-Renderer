#include <random>
#include <gtest/gtest.h>
#include <math/mat4.h>


TEST(Matrix4, Equality_Operator) {
  math::mat4 m1{1.f};
  math::mat4 m2{1.f};
  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::uniform_real_distribution<> dist(0, 10);
  for(int x = 0; x < m1.data.size(); ++x) {
    for(int y = 0; y < m1.data[x].size(); ++y) {
      m1.data[x][y] = m2.data[x][y] = dist(gen);
    }
  }

  EXPECT_TRUE(m1 == m2);
}

TEST(Matrix4, Non_Equality_Operator) {
  math::mat4 m1{1.f};
  math::mat4 m2{1.f};
  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::uniform_real_distribution<> dist(0, 10);
  for(int x = 0; x < m1.data.size(); ++x) {
    for(int y = 0; y < m1.data[x].size(); ++y) {
      m1.data[x][y] = m2.data[x][y] = dist(gen);
    }
  }
  ++m1.data[2][1];

  EXPECT_TRUE(m1 != m2);
}