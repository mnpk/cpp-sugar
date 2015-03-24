#include <map>
#include <algorithm>
#include <cctype>
#include <string>
#include <chrono>
#include <sstream>

namespace sugar {

// case-insensitive string map
struct case_insensitive {
  bool operator()(const std::string& a, const std::string& b) const {
    return std::lexicographical_compare(
        a.begin(), a.end(),
        b.begin(), b.end(),
        [](char c1, char c2) {
          return std::tolower(c1) < std::tolower(c2);
        });
  }
};
template <class T>
using imap = std::map<std::string, T, case_insensitive>;

// chrono::time_point to string format HH:MM:SS.fff
std::string to_hhmmssfff(std::chrono::time_point<std::chrono::system_clock>& tp) {
  std::stringstream ss;
  char str[30];
  auto t = std::chrono::system_clock::to_time_t(tp);
  std::strftime(str, sizeof(str), "%T", std::localtime(&t));
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
  ss << str << "." << ms.count() % 1000;
  return ss.str();
}

}  // namespace sugar
