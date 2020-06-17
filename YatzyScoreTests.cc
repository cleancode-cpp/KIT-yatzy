#include <gtest/gtest.h>

#include "YatzyScore.h"

TEST(YatzyScore, ones) {
  EXPECT_EQ(0, YatzyScore::ones({2, 3, 4, 5, 6})); //
}
