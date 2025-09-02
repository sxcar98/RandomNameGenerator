#ifndef _HISTORY_
#define _HISTORY_

#include "record.hpp"
#include <set>
#include <string>

class History {
public:
  History();
  bool picked(const std::string &) const;
  void insert(const Record &) &;
  void insert(Record &&) &&;
  void erase(const Record &);
  void clear();
  bool check(const std::string &);

private:
  std::string fnm = "history.txt";
  std::set<Record> st;
};

#endif
