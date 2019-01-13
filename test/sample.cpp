#include "gtest/gtest.h"
#include <string>

//TEST(Sample, Test) {
//  ASSERT_TRUE(true);
//}

int factorial(int n) {
  if (n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}


// Tests factorial of 0.
TEST(factorialTest, HandlesZeroInput) {
  EXPECT_EQ(factorial(0), 1);
}

// Tests factorial of positive numbers.
TEST(factorialTest, HandlesPositiveInput) {
  EXPECT_EQ(factorial(1), 1);
  EXPECT_EQ(factorial(2), 2);
  EXPECT_EQ(factorial(3), 6);
  EXPECT_EQ(factorial(8), 40320);
}