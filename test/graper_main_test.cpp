#include <gtest/gtest.h>

#include "src/graper.h"

using VectorString = std::vector<std::string>;

TEST(GraperMainTest, ShouldReturnSingleSignature) {
  VectorString expected = {"Apple"};
  VectorString actual = graper::ParseSignature("Apple");
  EXPECT_EQ(expected, actual);
}

TEST(GraperMainTest, ShouldReturnThreeSignature) {
  VectorString expected = {"Apple", "Banana", "Grape"};
  VectorString actual = graper::ParseSignature("Apple -> Banana -> Grape");
  EXPECT_EQ(expected, actual);
}

TEST(GraperMainTest, Should_Return_Two_Signature_But_Passing_Three_Signature) {
  VectorString expected = {"(Apple -> Banana)", "Grape"};
  VectorString actual = graper::ParseSignature("(Apple -> Banana) -> Grape");
  EXPECT_EQ(expected, actual);
}

TEST(GraperMainTest, Should_Return_Three_Signature_But_Passing_Four_Signature) {
  VectorString expected = {"Apple", "(Banana -> Grape)", "Cherry"};
  VectorString actual = graper::ParseSignature("Apple -> (Banana -> Grape) -> Cherry");
  EXPECT_EQ(expected, actual);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
