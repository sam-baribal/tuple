#include <gtest/gtest.h>

#include "Tuple.h"

TEST(TupleTest, Empty) {
    tpl::Tuple<> t();
}

TEST(TupleTest, Cake) {
    tpl::Tuple<int, double, std::string> t(42, 3.14, "The cake is ");
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
