#pragma once

#include <array>
#include <iostream>
#include <limits>
#include <list>
#include <string>
#include <tuple>
#include <vector>

namespace {

/**
 * @brief Хелпер для определения порядка байт (считаем, что порядок PDP-11 не используется).
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
}

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
 * @brief Хелпер для определения того, что тип T является контейнером std::vector.
 * @tparam T - тип std::vector.
 */
template <typename T>
using is_vector = std::is_same<T, std::vector<typename T::value_type,
                                              typename T::allocator_type>>;

/**
 * @brief Хелпер для определения того, что тип T является контейнером std::list.
 * @tparam T - тип std::list.
 */
template <typename T>
using is_list = std::is_same<T, std::list<typename T::value_type,
                                          typename T::allocator_type>>;

/**
 * @brief Вывод ip-адреса представленного в виде std::vector или std::list.
 * @tparam T - тип std::vector или std::list.
 * @param os - поток для вывода.
 * @param value - значение ip-адреса в виде строки.
 */
template<typename T>
typename std::enable_if_t<is_vector<T>::value || is_list<T>::value, void>
print_ip(std::ostream &os, const T &value) {
  for(auto it = value.begin(); it != value.end();) {
    print_ip(os, *it);
    if(++it != value.end())
      os << ".";
  }
}

/**
 * @brief Хелпер для разворачивания ip-адреса в формате std::tuple и печати его элемента.
 */
template<int ind, typename... Args>
struct print_ip_elem {
  void operator()(std::ostream &os, const std::tuple<Args...>& tuple) {
    print_ip_elem<ind - 1, Args...>{}(os, tuple);
    os << ".";
    print_ip(os, std::get<ind>(tuple));
  }
};

/**
 * @brief Хелпер для разворачивания ip-адреса в формате std::tuple и печати его последнего элемента.
 */
template<typename... Args>
struct print_ip_elem<0, Args...> {
  void operator()(std::ostream &os, const std::tuple<Args...>& tuple) {
    print_ip(os, std::get<0>(tuple));
  }
};

/**
 * @brief Вывод ip-адреса представленного в виде std::tuple.
 * @tparam Args - элементы кортежа.
 * @param os - поток для вывода.
 * @param tuple - кортеж.
 */
template<typename... Args>
void print_ip(std::ostream &os, const std::tuple<Args...>& tuple) {
  const auto len = std::tuple_size<std::tuple<Args...>>::value;
  print_ip_elem<len - 1, Args...>{}(os, tuple);
}

}
