#include <gtest/gtest.h>
#include <iostream>
#include <cstring>
#include <any>

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
  EXPECT_DOUBLE_EQ(t.get<1>(), 3.14);
  EXPECT_TRUE(t.get<2>().compare(std::string("The cake is ")) == 0);

  tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
  EXPECT_EQ(t2.get<0>(), -42);
  EXPECT_DOUBLE_EQ(t2.get<1>(), -3.14);
  EXPECT_TRUE(t2.get<2>().compare(std::string("a lie")) == 0);

  tpl::Tuple<int, double, int> t3(1, 2.0, 1);
  t += t2;

  EXPECT_EQ(t.get<0>(), 0);
  EXPECT_DOUBLE_EQ(t.get<1>(), 0.0);
  EXPECT_TRUE(strcmp(t.get<2>(), "The cake is a lie") == 0);
}

TEST(ExampleTest, Multiplication){
  auto t3 = tpl::makeTuple(10, 10.0d);
  EXPECT_EQ(t3.get<0>(), 10.0);
  EXPECT_DOUBLE_EQ(t3.get<1>(), 10.0);

  tpl::Tuple<std::size_t, double> t4(2lu, 2.0);
  EXPECT_EQ(t4.get<0>(), 2lu);
  EXPECT_DOUBLE_EQ(t4.get<1>(), 2.0);
  auto t5 = t3 * t4;
  EXPECT_EQ(t5.get<0>(), 20.0);
  EXPECT_DOUBLE_EQ(t5.get<1>(), 20.0);
}

TEST(ExampleTest, Concatenate){
  tpl::Tuple<int, double, std::string> t(42, 3.14, "The cake is ");
  tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
  t += t2;
  auto t3 = tpl::makeTuple(10, 10.0f);
  tpl::Tuple<std::size_t, double> t4(2lu, 2.0);
  auto t5 = t3 * t4;

  auto t6 = std::move(t) | std::move(t5);
  EXPECT_EQ(t6.get<0>(), 0.0);
  EXPECT_DOUBLE_EQ(t6.get<1>(), 0.0);
  EXPECT_TRUE(strcmp(t6.get<2>(), "The cake is a lie") == 0);
  EXPECT_EQ(t6.get<3>(), 20.0);
  EXPECT_DOUBLE_EQ(t6.get<4>(), 20.0);
}

TEST(ComparisonTest, EmptyTuples){
  auto t1 = tpl::makeTuple<>();
  auto t2 = tpl::makeTuple<>();
  EXPECT_TRUE(t1 == t2);
  EXPECT_TRUE(t1 != t2);
  EXPECT_TRUE(t1 <= t2);
  EXPECT_TRUE(t1 < t2);
  EXPECT_TRUE(t1 >= t2);
  EXPECT_TRUE(t1 > t2);
}

TEST(ComparisonTest, Equal){
  tpl::Tuple<int, double, std::string, bool> t1(42, 3.14, "The cake is ", false);
  tpl::Tuple<int, double, std::string, bool> t2(42, 3.14, "The cake is ", false);
  EXPECT_TRUE(t1 == t2);
}

TEST(ComparisonTest, NotEqual){
  tpl::Tuple<int, double, std::string> t1(42, 3.14, "The cake is ");
  tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
  EXPECT_TRUE(t1 != t2);
}

TEST(ComparisonTest, LessOrEqual){
  tpl::Tuple<int, double, std::string> t1(42, 3.14, "The cake is ");
  tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
  tpl::Tuple<int, double, std::string> t3(42, 3.14, "The cake is ");
  EXPECT_TRUE(t1 <= t2);
  EXPECT_TRUE(t1 <= t3);
}

TEST(ComparisonTest, LessThan){
  tpl::Tuple<int, double, std::string> t1(42, 3.14, "The cake is ");
  tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
  EXPECT_TRUE(t1 < t2);
}

TEST(ComparisonTest, GreaterOrEqual){
  tpl::Tuple<int, double, std::string> t1(42, 3.14, "The cake is ");
  tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
  tpl::Tuple<int, double, std::string> t3(42, 3.14, "The cake is ");
  EXPECT_TRUE(t1 >= t2);
  EXPECT_TRUE(t1 >= t3);
}

TEST(ComparisonTest, GreaterThan){
  tpl::Tuple<int, double, std::string> t1(42, 3.14, "The cake is ");
  tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
  EXPECT_TRUE(t1 > t2);
}

TEST(ArithmeticTest, Addition){
  tpl::Tuple<int, double, std::string> t1(42, 3.14, "The cake is ");
  tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
  auto t3 = t1 + t2;
  EXPECT_EQ(t3.get<0>(), 0);
  EXPECT_DOUBLE_EQ(t3.get<1>(), 0.0);
  EXPECT_TRUE(t3.get<2>().compare(std::string("The cake is a lie")) == 0);
}

TEST(ArithmeticTest, InPlaceAddition){
  tpl::Tuple<int, double, std::string> t1(42, 3.14, "The cake is ");
  tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
  t1 += t2;
  EXPECT_EQ(t1.get<0>(), 0);
  EXPECT_DOUBLE_EQ(t1.get<1>(), 0.0);
  EXPECT_TRUE(t1.get<2>().compare(std::string("The cake is a lie")) == 0);
}

TEST(ArithmeticTest, Substraction){
  tpl::Tuple<std::size_t, double, int> t1(7lu, 2.0, 12);
  tpl::Tuple<std::size_t, double, int> t2(3lu, 7.3, -9);
  auto t3 = t1 - t2;
  EXPECT_EQ(t3.get<0>(), 4lu);
  EXPECT_DOUBLE_EQ(t3.get<1>(), -5.3);
  EXPECT_EQ(t3.get<2>(), 21);
}

TEST(ArithmeticTest, InPlaceSubstraction){
  tpl::Tuple<std::size_t, double, int> t1(7lu, 2.0, 12);
  tpl::Tuple<std::size_t, double, int> t2(3lu, 7.3, -9);
  t1 -= t2;
  EXPECT_EQ(t1.get<0>(), 4lu);
  EXPECT_DOUBLE_EQ(t1.get<1>(), -5.3);
  EXPECT_EQ(t1.get<2>(), 21);
}

TEST(ArithmeticTest, Multiplication){
  tpl::Tuple<std::size_t, double, int> t1(7lu, 2.0, 12);
  tpl::Tuple<std::size_t, double, int> t2(3lu, 7.3, -9);
  auto t3 = t1*t2;
  EXPECT_EQ(t3.get<0>(), 21lu);
  EXPECT_DOUBLE_EQ(t3.get<1>(), 14.6);
  EXPECT_EQ(t3.get<2>(), -108);
}

TEST(ArithmeticTest, InPlaceMultiplication){
  tpl::Tuple<std::size_t, double, int> t1(7lu, 2.0, 12);
  tpl::Tuple<std::size_t, double, int> t2(3lu, 7.3, -9);
  t1 *= t2;
  EXPECT_EQ(t1.get<0>(), 21lu);
  EXPECT_DOUBLE_EQ(t1.get<1>(), 14.6);
  EXPECT_EQ(t1.get<2>(), -108);
}

TEST(ArithmeticTest, Division){
  tpl::Tuple<std::size_t, double, int> t1(7lu, 2.0, 12);
  tpl::Tuple<std::size_t, double, int> t2(3lu, 7.3, -9);
  auto t3 = t1/t2;
  EXPECT_EQ(t3.get<0>(), 2lu);
  EXPECT_DOUBLE_EQ(t3.get<1>(), 0.273972603);
  EXPECT_EQ(t3.get<2>(), -1);
}

TEST(ArithmeticTest, InPlaceDivision){
  tpl::Tuple<std::size_t, double, int> t1(7lu, 2.0, 12);
  tpl::Tuple<std::size_t, double, int> t2(3lu, 7.3, -9);
  t1 /= t2;
  EXPECT_EQ(t1.get<0>(), 2lu);
  EXPECT_DOUBLE_EQ(t1.get<1>(), 0.273972603);
  EXPECT_EQ(t1.get<2>(), -1);
}