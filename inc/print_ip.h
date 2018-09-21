#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <array>

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





