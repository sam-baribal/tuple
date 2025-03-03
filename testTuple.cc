#include <gtest/gtest.h>

#include "Tuple.h"

TEST(TupleTest, Empty) {
    tpl::Tuple<> ();
}

TEST(TupleTest, Cake) {
    tpl::Tuple<int, double, std::string> t(42, 3.14, "The cake is ");
    int e0 = t.get<0> ();
    //float e1 = t.get<1> ();
    //std::string e2 = t.get<2> ();
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
