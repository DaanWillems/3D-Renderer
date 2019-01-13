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

TEST(Matrix4, Translate) {
  math::mat4 matrix{1.f};
  matrix.data[0][3] = 1.f;
  matrix.data[1][3] = 2.f;
  matrix.data[2][3] = 3.f;
  matrix.data[3][3] = 4.f;
  math::vec4 translation{1.f, 2.f, 3.f, 4.f};

  matrix.translate(translation);

  math::mat4 expected{1.f};
  expected.data[0][3] = 2.f;
  expected.data[1][3] = 4.f;
  expected.data[2][3] = 6.f;
  expected.data[3][3] = 8.f;
  EXPECT_EQ(true, matrix == expected);
}

TEST(Matrix4, Invert) {
  math::mat4 matrix{1.f};

  matrix.invert();

  math::mat4 expected{1.f};
  matrix.data[0][0] *= -1.f;
  matrix.data[1][1] *= -1.f;
  matrix.data[2][2] *= -1.f;
  matrix.data[3][3] *= -1.f;
  EXPECT_EQ(true, matrix == expected);
}