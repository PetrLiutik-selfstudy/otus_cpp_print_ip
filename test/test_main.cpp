#include "gtest/gtest.h"
#include "../inc/print_ip.h"
#include "../inc/ver.h"

#include <sstream>

TEST(ver_test_case, ver_major_test) {
  EXPECT_GE(ver_major(), 1);
}

TEST(ver_test_case, ver_minor_test) {
  EXPECT_GE(ver_minor(), 1);
}

TEST(ver_test_case, ver_patch_test) {
  EXPECT_GE(ver_patch(), 1);
}

TEST(print_ip_test_case, print_ip_bool_test) {
  std::stringstream ss;
  
  bool ip{true};
  print_ip(ss, ip);
  EXPECT_EQ(ss.str(), "1");
  
  bool ip{false};
  print_ip(ss, ip);
  EXPECT_EQ(ss.str(), "0");
}

TEST(print_ip_test_case, print_ip_char_test) {
  std::stringstream ss;

  char ip{-1};
  print_ip(ss, ip);
  EXPECT_EQ(ss.str(), "255");
}

TEST(print_ip_test_case, print_ip_uint8_t_test) {
  std::stringstream ss;
  
  uint8_t ip{23};
  print_ip(ss, ip);
  EXPECT_EQ(ss.str(), "23");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
