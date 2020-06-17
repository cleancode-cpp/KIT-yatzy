#include <gtest/gtest.h>

#include "YatzyScore.h"

TEST(YatzyScore, ones) {
  EXPECT_EQ(3, YatzyScore::onlyOnes({1, 3, 1, 5, 1})); //
}

TEST(YatzyScore, pair_example) {
  EXPECT_EQ(8, YatzyScore::bestPair({2, 2, 4, 4, 6})); //
}

TEST(YatzyScore, pair_nopair) {
  EXPECT_EQ(0, YatzyScore::bestPair({2, 3, 4, 5, 6})); //
}
