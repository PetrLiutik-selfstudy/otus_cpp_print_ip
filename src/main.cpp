#include <iostream>

#include "../inc/print_ip.h"
#include "../inc/ver.h"

int main()
{
  long long ip1{8875824491850138409};

  print_ip(std::cout, ip1);
  std::cout << std::endl;

  char ip2{-1};
  print_ip(std::cout, ip2);
  std::cout << std::endl;

  int8_t ip3{-1};
  print_ip(std::cout, ip3);
  std::cout << std::endl;

  uint8_t ip4{255};
  print_ip(std::cout, ip4);
  std::cout << std::endl;

  auto ip5{65535};
  print_ip(std::cout, ip5);
  std::cout << std::endl;


  int ip6{2130706433};
  print_ip(std::cout, ip6);
  std::cout << std::endl;

  short ip7{0};
  print_ip(std::cout, ip7);
  std::cout << std::endl;

  long long ip8{8875824491850138409};

  print_ip<long long, false>(std::cout, ip8);
  std::cout << std::endl;

  return 0;
}
