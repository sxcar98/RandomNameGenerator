#ifndef _TIME_
#define _TIME_

#include <chrono>
#include <ostream>
#include <string>

class Record;
class Time {
  friend std::ostream &operator<<(std::ostream &, const Time &);
  friend bool dist_bigger_than_three_days(const Time &, const Time &);

public:
  Time() = default;
  Time(std::chrono::time_point<std::chrono::system_clock>);
  Time(const std::string &);
  std::string str() const;
  const std::chrono::time_point<std::chrono::system_clock> &unix_time() const;

private:
  std::chrono::time_point<std::chrono::system_clock> time = std::chrono::system_clock::now();
};

std::ostream &operator<<(std::ostream &, const Time &);
bool dist_bigger_than_three_days(const Time &, const Time &);

#endif
