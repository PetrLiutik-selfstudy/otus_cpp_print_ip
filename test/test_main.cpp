#include "gtest/gtest.h"
#include "../inc/print_ip.h"
#include "../inc/ver.h"

#include <sstream>

/**
 * @brief Хелпер для формирования ip-адреса в виде строки.
 * @tparam T - тип которым задан ip-адрес.
 * @param value - значение ip-адреса.
 * @return - ip-адрес в виде строки.
 */
template<typename T>
std::string get_ip_string(const T &value) {
  std::stringstream ss;
  std::string str;
  print_ip(ss, value);
  ss >> str;
  return str;
}

TEST(ver_test_case, ver_major_test) {
  EXPECT_GE(ver_major(), 1);
}

TEST(ver_test_case, ver_minor_test) {
  EXPECT_GE(ver_minor(), 1);
}

TEST(ver_test_case, ver_patch_test) {
  EXPECT_GE(ver_patch(), 1);
}

TEST(print_ip_test_case, print_ip_int_test) {
  bool ip1{true};
  std::string ip1_str{"1"};
  bool ip2{false};
  std::string ip2_str{"0"};
  char ip3{-1};
  std::string ip3_str{"255"};
  uint8_t ip4{11};
  std::string ip4_str{"11"};
  int8_t ip5{-11};
  std::string ip5_str{"245"};
  uint16_t ip6{1111};
  std::string ip6_str{"4.57"};
  int16_t ip7{-1111};
  std::string ip7_str{"251.169"};
  uint32_t ip8{111111111};
  std::string ip8_str{"6.159.107.199"};
  int32_t ip9{-111111111};
  std::string ip9_str{"249.96.148.57"};
  uint64_t ip10{1111111111111111111};
  std::string ip10_str{"15.107.117.171.43.196.113.199"};
  int64_t ip11{-1111111111111111111};
  std::string ip11_str{"240.148.138.84.212.59.142.57"};
  
  EXPECT_EQ(get_ip_string(ip1), ip1_str);
  EXPECT_EQ(get_ip_string(ip2), ip2_str);
  EXPECT_EQ(get_ip_string(ip3), ip3_str);
  EXPECT_EQ(get_ip_string(ip4), ip4_str);
  EXPECT_EQ(get_ip_string(ip5), ip5_str);
  EXPECT_EQ(get_ip_string(ip6), ip6_str);
  EXPECT_EQ(get_ip_string(ip7), ip7_str);
  EXPECT_EQ(get_ip_string(ip8), ip8_str);
  EXPECT_EQ(get_ip_string(ip9), ip9_str);
  EXPECT_EQ(get_ip_string(ip10), ip10_str);
  EXPECT_EQ(get_ip_string(ip11), ip11_str);
}


int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
