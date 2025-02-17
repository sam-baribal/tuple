#include <gtest/gtest.h>
#include <iostream>
#include <cstring>

#include "Tuple.h"

/*
  for testing we can use :
    - decltype
    - std::is_same
  
  remember to extensively test the return values of get function
*/

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(ExampleTest, Addition){
  tpl::Tuple<int, double, std::string> t(42, 3.14, "The cake is ");
  EXPECT_EQ(t.get<0>(), 42);
  EXPECT_FLOAT_EQ(t.get<1>(), 3.14);
  EXPECT_TRUE(strcmp(t.get<2>(), "The cake is ") == 0);

  tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
  EXPECT_EQ(t2.get<0>(), -42);
  EXPECT_FLOAT_EQ(t2.get<1>(), -3.14);
  EXPECT_TRUE(strcmp(t2.get<2>(), "a lie") == 0);

  t += t2;

  EXPECT_EQ(t.get<0>(), 0);
  EXPECT_FLOAT_EQ(t.get<1>(), 0.0);
  EXPECT_TRUE(strcmp(t.get<2>(), "The cake is a lie") == 0);
}

TEST(ExampleTest, Multiplication){
  auto t3 = tpl::makeTuple(10, 10.0f);
  EXPECT_EQ(t3.get<0>(), 10);
  EXPECT_FLOAT_EQ(t3.get<1>(), 10.0f);

  tpl::Tuple<std::size_t, double> t4(2lu, 2.0);
  EXPECT_EQ(t4.get<0>(), 2lu);
  EXPECT_FLOAT_EQ(t4.get<1>(), 2.0);

  auto t5 = t3 * t4;
  EXPECT_EQ(t5.get<0>(), 20);
  EXPECT_FLOAT_EQ(t5.get<1>(), 20.0);
}

TEST(ExampleTest, Concatenate){
  tpl::Tuple<int, double, std::string> t(42, 3.14, "The cake is ");
  tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
  t += t2;
  auto t3 = tpl::makeTuple(10, 10.0f);
  tpl::Tuple<std::size_t, double> t4(2lu, 2.0);
  auto t5 = t3 * t4;

  auto t6 = std::move(t) | std::move(t5);
  EXPECT_EQ(t6.get<0>(), 0);
  EXPECT_FLOAT_EQ(t6.get<1>(), 0.0);
  EXPECT_TRUE(strcmp(t6.get<2>(), "The cake is a lie") == 0);
  EXPECT_EQ(t6.get<3>(), 20);
  EXPECT_FLOAT_EQ(t6.get<4>(), 20.0);

}