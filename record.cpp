#include "record.hpp"
#include "time.hpp"
#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &out, const Record &r) {
  out << r.name() << "\t" << r.time();
  return out;
}
bool operator<(const Record &lhs, const Record &rhs) {
  return lhs.time().str() < rhs.time().str();
}

Record::Record(const std::string &nm) : str_name(nm) {}
Record::Record(const std::string &nm, const std::string &tm) : str_name(nm), cls_time(tm) {}
Record::Record(const std::string &nm, const Time &tm) : str_name(nm), cls_time(tm) {}
const std::string &Record::name() const { return str_name; }
const Time &Record::time() const { return cls_time; }
