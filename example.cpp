#include "sugar.hpp"
#include <iostream>

int main() {
  // case-insensitive string map
  sugar::imap<std::string> map;
  map["hello"] = "world!";
  std::cout << map["HELLO"] << std::endl;

  // chrono::time_point to string format HH:MM:SS.fff
  auto now = std::chrono::system_clock::now();
  std::cout << sugar::to_hhmmssfff(now) <<  std::endl; 

  return 0;
}
