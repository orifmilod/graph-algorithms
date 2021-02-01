#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(RootFolder, SomethingNew) { EXPECT_EQ(18.0, 18.0); }

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
