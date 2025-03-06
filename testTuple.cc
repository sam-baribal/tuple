#include <gtest/gtest.h>

#include "Tuple.h"

TEST(TupleTest, Empty) {
    tpl::Tuple<> ();
}

TEST(TupleTest, Cake) {
    tpl::Tuple<int, double, std::string> t(42, 3.14, "The cake is ");
    int e0 = t.get<0> ();
    float e1 = t.get<1> ();
    std::string e2 = t.get<2> ();
    EXPECT_TRUE (e0 == 42 && e1 > 3.135 && e1 < 3.145 && e2 == "The cake is ");
    EXPECT_TRUE (e0 == 42);
    EXPECT_TRUE (e2 == "The cake is ");
}

TEST(TupleTest, Comparaison) {
    tpl::Tuple<int, double, std::string> t1(42, 3.14, "The cake is ");
    tpl::Tuple<int, double, std::string> t2(42, 3.14, "The cake");
    tpl::Tuple<int, double, std::string> t3(42, 3.14, "The cake is ");
    EXPECT_TRUE (t1 == t3);
    EXPECT_TRUE (t1 != t2);
    EXPECT_FALSE (t1 < t3);
    EXPECT_TRUE (t1 <= t3);
    EXPECT_FALSE (t1 > t3);
    EXPECT_TRUE (t1 >= t3);
    EXPECT_TRUE (t1 > t2);
    EXPECT_TRUE (t1 >= t2);
    EXPECT_FALSE (t1 < t2);
    EXPECT_FALSE (t1 <= t2);
}

TEST(TupleTest, Operation_int_in_place) {
    tpl::Tuple<int> t1(42);
    tpl::Tuple<int> t2(-42);
    t1 += t2;
    EXPECT_TRUE (t1.get<0> () == 0);
    t1 -= t2;
    EXPECT_TRUE (t1.get<0> () == 42);
    t1 /= t2;
    EXPECT_TRUE (t1.get<0> () == -1);
    t1 *= t2;
    EXPECT_TRUE (t1.get<0> () == 42);
}

TEST(TupleTest, Operation_double_in_place) {
    tpl::Tuple<double> t1(42.0);
    tpl::Tuple<double> t2(-42.0);
    t1 += t2;
    EXPECT_NEAR (t1.get<0> (), 0.0, 0.00001);
    t1 -= t2;
    EXPECT_NEAR (t1.get<0> (), 42.0, 0.00001);
    t1 /= t2;
    EXPECT_NEAR (t1.get<0> (), -1.0, 0.00001);
    t1 *= t2;
    EXPECT_NEAR (t1.get<0> (), 42.0, 0.00001);
}

TEST(TupleTest, Operation_multi_add_in_place) {
    tpl::Tuple<int, double, std::string> t1(42, 3.14, "The cake is ");
    tpl::Tuple<int, double, std::string> t2(-42, -3.14, "a lie");
    t1 += t2;
    EXPECT_TRUE (t1.get<0> () == 0 && t1.get<1> () == 0 && t1.get<2> () == "The cake is a lie");
}

TEST(TupleTest, Operation_int) {
    tpl::Tuple<int> t1(42);
    tpl::Tuple<int> t2(-42);
    tpl::Tuple<int> t3 = t1 + t2;
    EXPECT_TRUE (t3.get<0> () == 0);
    t3 = t1 - t2;
    EXPECT_TRUE (t3.get<0> () == 84);
    t3 = t1 * t2;
    EXPECT_TRUE (t3.get<0> () == -1764);
    t3 = t1 / t2;
    EXPECT_TRUE (t3.get<0> () == -1);
    
    EXPECT_TRUE ((t1 + t2).get<0> () == 0);
    EXPECT_TRUE ((t1 - t2).get<0> () == 84);
    EXPECT_TRUE ((t1 * t2).get<0> () == -1764);
    EXPECT_TRUE ((t1 / t2).get<0> () == -1);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
