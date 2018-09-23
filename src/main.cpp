#include <iostream>

#include "../inc/print_ip.h"
#include "../inc/ver.h"

int main()
{
  std::cout << "print_ip version: "
            << ver_major() << "."
            << ver_minor() << "."
            << ver_patch() << std::endl;

  char ip1{-1};
  print_ip(std::cout, ip1);
  std::cout << std::endl;

  short ip2{0};
  print_ip(std::cout, ip2);
  std::cout << std::endl;

  int ip3{2130706433};
  print_ip(std::cout, ip3);
  std::cout << std::endl;

  long long ip4{8875824491850138409};
  print_ip(std::cout, ip4);
  std::cout << std::endl;

  std::string ip5{"192.168.1.1"};
  print_ip(std::cout, ip5);
  std::cout << std::endl;

  std::vector<uint8_t> ip6{173, 194, 44, 7};
  print_ip(std::cout, ip6);
  std::cout << std::endl;

  std::list<int> ip7{2130706433, 2130706433, 2130706433};
  print_ip(std::cout, ip7);
  std::cout << std::endl;

  std::tuple<uint8_t, std::string, std::vector<uint8_t>> ip8{213, "180", {204, 1}};
  print_ip(std::cout, ip8);
  std::cout << std::endl;

  return 0;
}
