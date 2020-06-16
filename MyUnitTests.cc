#include <gtest/gtest.h>

#include "MyClass.h"

TEST(MyUnit, Foo) {
  MyClass myClass;
  EXPECT_EQ(false, myClass.isAlwaysTrue()); // FIXME
}
