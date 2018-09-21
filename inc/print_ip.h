#pragma once

#include <array>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <vector>

/**
 * @brief Определение порядка байт (считаем, что порядок PDP-11 не используется).
 * @return true - для Little Endian, false - для Big Endian.
 */
constexpr bool isLittleEndian() {
  return ((size_t{std::numeric_limits<size_t>::max()} & 1) == 1);
}

/**
 * @brief Вывод ip-адреса представленного в интегральном типе.
 * @tparam T - любой интегральный тип.
 * @param os - поток для вывода.
 * @param value - значение ip-адреса представленное в интегральном типе.
 */
template<typename T, bool endianness = isLittleEndian()>
typename std::enable_if<std::is_integral<T>::value, void>::type
print_ip(std::ostream& os, const T& value) {
  union {
    T val;
    std::array<uint8_t, sizeof(T)> arr;
  } int2arr{value};

  if(endianness) {
    for(auto it = int2arr.arr.crbegin(); it != int2arr.arr.crend() - 1; ++it)
      os << +(*it) << ".";
    os << +(*int2arr.arr.cbegin());
  } else {
    for(auto it = int2arr.arr.cbegin(); it != int2arr.arr.cend() - 1; ++it)
      os << +(*it) << ".";
    os << +(*int2arr.arr.crbegin());
  }
};

/**
 * @brief Вывод ip-адреса представленного в виде строки std::string.
 * @tparam T - тип std::string.
 * @param os - поток для вывода.
 * @param value - значение ip-адреса в виде строки.
 */
template<typename T>
typename std::enable_if_t<std::is_same<T, std::string>::value, void>
print_ip(std::ostream &os, const T &value) {
  os << value;
}

/**
 * @brief Вывод ip-адреса представленного в виде std::vector или std::list.
 * @tparam T - тип std::vector или std::list.
 * @param os - поток для вывода.
 * @param value - значение ip-адреса в виде строки.
 */
template<typename T>
typename std::enable_if_t<std::is_same<T, std::vector<typename T::value_type>>::value ||
  std::is_same<T, std::list<typename T::value_type>>::value, void>
print_ip(std::ostream &os, const T &value) {
  for(auto it = value.begin(); it != value.end();) {
    print_ip(os, *it);
    if(++it != value.end())
      os << ".";
  }
}

