//test cases created by Professor John Stratton (Whitman College)

#include <string>
#include <gtest/gtest.h>
#include "myString.h"
using namespace CS270;
//using namespace std;

TEST(StringTest, constructor) {
  //Common case
  string hello("hello");
  //Boundary case
  string empty("");
}

TEST(StringTest, length) {
  //Common case
  EXPECT_EQ(5, string("hello").length());
  //Boundary case
  EXPECT_EQ(0, string("").length());
}

TEST(StringTest, read) {
  //Common case
  string hello("hello");
  EXPECT_EQ('h', hello[0]);
  EXPECT_EQ('e', hello[1]);
  EXPECT_EQ('l', hello[2]);
  EXPECT_EQ('l', hello[3]);
  EXPECT_EQ('o', hello[4]);

  //Boundary cases
  EXPECT_EQ('A', string("A")[0]);
}

TEST(StringTest, write) {
  //Common case
  string write("!!!!!");
  write[1] = 'r';
  write[2] = 'i';
  write[3] = 't';
  EXPECT_EQ('r', write[1]);
  EXPECT_EQ('i', write[2]);
  EXPECT_EQ('t', write[3]);
  EXPECT_EQ(5, write.length());

  //Boundary cases
  write[0] = 'w';
  write[4] = 'e';
  EXPECT_EQ('w', write[0]);
  EXPECT_EQ('e', write[4]);

  //Edge case
  string A("!");
  A[0] = 'A';
  EXPECT_EQ('A', A[0]);
}

TEST(StringTest, copy) {
  //Common case
  string original("hello");
  string hello(original);
  EXPECT_EQ(5, hello.length());
  EXPECT_EQ(5, original.length());
  EXPECT_EQ('h', hello[0]);
  EXPECT_EQ('e', hello[1]);
  EXPECT_EQ('l', hello[2]);
  EXPECT_EQ('l', hello[3]);
  EXPECT_EQ('o', hello[4]);
  EXPECT_EQ('h', original[0]);
  EXPECT_EQ('e', original[1]);
  EXPECT_EQ('l', original[2]);
  EXPECT_EQ('l', original[3]);
  EXPECT_EQ('o', original[4]);

  //Boundary case
  string empty("");
  string empty_string_copy(empty);
  EXPECT_EQ(0, empty_string_copy.length());
}

TEST(StringTest, copy_alias) {
  //Common case
  string hi("hi");
  string hi_caps(hi);
  hi_caps[0] = 'H';
  hi_caps[1] = 'I';

  EXPECT_EQ('H', hi_caps[0]);
  EXPECT_EQ('I', hi_caps[1]);
  EXPECT_EQ('h', hi[0]);
  EXPECT_EQ('i', hi[1]);

  EXPECT_EQ(2, hi.length());
  EXPECT_EQ(2, hi_caps.length());
}

TEST(StringTest, concatenate) {
  //Common case
  string hi("hi");
  string ya("ya");
  string hiya = hi + ya;
  ASSERT_EQ(4, hiya.length());
  EXPECT_EQ('h', hiya[0]);
  EXPECT_EQ('i', hiya[1]);
  EXPECT_EQ('y', hiya[2]);
  EXPECT_EQ('a', hiya[3]);

  //Boundary and edge cases
  string empty("");
  string hi_plus_empty = hi + empty;
  string empty_plus_hi = empty + hi;
  string hihi = hi + hi;
  ASSERT_EQ(2, hi_plus_empty.length());
  EXPECT_EQ('h', hi_plus_empty[0]);
  EXPECT_EQ('i', hi_plus_empty[1]);
  ASSERT_EQ(2, empty_plus_hi.length());
  EXPECT_EQ('h', empty_plus_hi[0]);
  EXPECT_EQ('i', empty_plus_hi[1]);
  ASSERT_EQ(4, hihi.length());
  EXPECT_EQ('h', hihi[0]);
  EXPECT_EQ('i', hihi[1]);
  EXPECT_EQ('h', hihi[2]);
  EXPECT_EQ('i', hihi[3]);
  EXPECT_EQ(0, (empty + empty).length());

  //Check for aliasing
  ASSERT_EQ(2, hi.length());
  ASSERT_EQ(2, ya.length());
  hiya[0] = '!';
  EXPECT_EQ('h', hi[0]);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
