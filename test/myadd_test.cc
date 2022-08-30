#include <gtest/gtest.h>
#include <myadd.hpp>

TEST(MyAddTest, Base) {
  EXPECT_EQ(myadd(3, 2), 5);
  EXPECT_EQ(myadd(-2, 10), 8);
}