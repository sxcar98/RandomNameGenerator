#include "time.hpp"
#include <chrono>
#include <format>
#include <ostream>
#include <sstream>
#include <string>

std::ostream &operator<<(std::ostream &out, const Time &t) {
  return out << t.str();
}

bool dist_bigger_than_three_days(const Time &lhs, const Time &rhs) {
  std::chrono::sys_seconds s_l(floor<std::chrono::seconds>(lhs.time));
  std::chrono::sys_seconds s_r(floor<std::chrono::seconds>(rhs.time));
  auto diff = s_r - s_l;
  return diff > std::chrono::days(3);
}

const std::chrono::time_point<std::chrono::system_clock> &Time::unix_time() const {
  return time;
}
std::string Time::str() const { return std::format("{:%Y-%m-%d %H:%M:%S}", time); }

Time::Time(const std::string &tm) {
  std::istringstream is(tm);
  is >> std::chrono::parse("%Y-%m-%d %H:%M:%S", time);
}

Time::Time(std::chrono::time_point<std::chrono::system_clock> tm) : time(tm) {}
