#ifndef _RECORD_
#define _RECORD_

#include "time.hpp"
#include <iostream>
#include <string>

class Record {
  friend std::ostream &operator<<(std::ostream &, const Record &);
  friend bool operator<(const Record &, const Record &);

public:
  Record() = default;
  Record(const std::string &);
  Record(const std::string &, const std::string &);
  Record(const std::string &, const Time &);
  const std::string &name() const;
  const Time &time() const;

private:
  std::string str_name;
  Time cls_time;
};

std::ostream &operator<<(std::ostream &, const Record &);
bool operator<(const Record &, const Record &);

#endif
