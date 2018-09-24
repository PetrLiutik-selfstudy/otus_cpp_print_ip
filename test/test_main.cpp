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
  EXPECT_EQ(get_ip_string(ip1), ip1_str);

  bool ip2{false};
  std::string ip2_str{"0"};
  EXPECT_EQ(get_ip_string(ip2), ip2_str);

  char ip3{-1};
  std::string ip3_str{"255"};
  EXPECT_EQ(get_ip_string(ip3), ip3_str);

  uint8_t ip4{11};
  std::string ip4_str{"11"};
  EXPECT_EQ(get_ip_string(ip4), ip4_str);

  int16_t ip5{-1111};
  std::string ip5_str{"251.169"};
  EXPECT_EQ(get_ip_string(ip5), ip5_str);

  int32_t ip6{-111111111};
  std::string ip6_str{"249.96.148.57"};
  EXPECT_EQ(get_ip_string(ip6), ip6_str);

  uint64_t ip7{1111111111111111111};
  std::string ip7_str{"15.107.117.171.43.196.113.199"};
  EXPECT_EQ(get_ip_string(ip7), ip7_str);
}

TEST(print_ip_test_case, print_ip_vector_test) {
  std::vector<uint8_t> ip1{1, 2, 3, 4};
  std::string ip1_str{"1.2.3.4"};
  EXPECT_EQ(get_ip_string(ip1), ip1_str);

  std::vector<uint32_t> ip2{11111111, 22222222, 33333333, 44444444};
  std::string ip2_str{"0.169.138.199.1.83.21.142.1.252.160.85.2.166.43.28"};
  EXPECT_EQ(get_ip_string(ip2), ip2_str);
}

TEST(print_ip_test_case, print_ip_list_test) {
  std::list<uint8_t> ip1{1, 2, 3, 4};
  std::string ip1_str{"1.2.3.4"};
  EXPECT_EQ(get_ip_string(ip1), ip1_str);

  std::list<uint32_t> ip2{11111111, 22222222, 33333333, 44444444};
  std::string ip2_str{"0.169.138.199.1.83.21.142.1.252.160.85.2.166.43.28"};
  EXPECT_EQ(get_ip_string(ip2), ip2_str);
}

TEST(print_ip_test_case, print_ip_tuple_test) {
  std::tuple<uint32_t, uint32_t, uint32_t, uint32_t> ip{1, 2, 3, 4};
  std::string ip_str{"0.0.0.1.0.0.0.2.0.0.0.3.0.0.0.4"};
  EXPECT_EQ(get_ip_string(ip), ip_str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
