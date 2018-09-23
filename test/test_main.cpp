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

template<typename T>
std::string get_ip_string(const T &value) {
  std::stringstream ss;
  std::string str;
  print_ip(ss, value);
  ss >> str;
  return str;
}

TEST(print_ip_test_case, print_ip_bool_test) {
  bool ip{true};
  std::string ip_str{"1"};

  EXPECT_EQ(get_ip_string(ip), ip_str);
}


int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
