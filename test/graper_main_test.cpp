#include <gtest/gtest.h>

#include "src/graper.h"

TEST(GraperMainTest, ShouldReturnSingleSignature) {
  graper::VectorString expected = {"Apple"};
  graper::VectorString actual = graper::ParseSignature("Apple");
  EXPECT_EQ(expected, actual);
}

TEST(GraperMainTest, ShouldReturnThreeSignature) {
  graper::VectorString expected = {"Apple", "Banana", "Grape"};
  graper::VectorString actual = graper::ParseSignature("Apple -> Banana -> Grape");
  EXPECT_EQ(expected, actual);
}

TEST(GraperMainTest, Should_Return_Two_Signature_But_Passing_Three_Signature) {
  graper::VectorString expected = {"(Apple -> Banana)", "Grape"};
  graper::VectorString actual = graper::ParseSignature("(Apple -> Banana) -> Grape");
  EXPECT_EQ(expected, actual);
}

TEST(GraperMainTest, Should_Return_Three_Signature_But_Passing_Four_Signature) {
  graper::VectorString expected = {"Apple", "(Banana -> Grape)", "Cherry"};
  graper::VectorString actual = graper::ParseSignature("Apple -> (Banana -> Grape) -> Cherry");
  EXPECT_EQ(expected, actual);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
