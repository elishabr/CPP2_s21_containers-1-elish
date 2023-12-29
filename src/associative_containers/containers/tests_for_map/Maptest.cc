#include <gtest/gtest.h>

#include "../S21Map.h"

TEST(Map, TestConstructors1) {
  // Arrange
  s21::map<int, int> nik;
  // Act
  std::pair<int, int> n(1,1);
  nik.insert(n);
  // Assert
  EXPECT_EQ(nik.empty(), false);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}