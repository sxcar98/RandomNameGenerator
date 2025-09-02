#include "history.hpp"
#include "record.hpp"
#include <fstream>
#include <set>
#include <string>

History::History() {
  std::ifstream fopen(fnm);
  std::string name, time;
  while (fopen) {
    fopen >> name;
    std::getline(fopen, time);
    st.insert(Record(name, time));
  }
  fopen.close();
}
bool History::picked(const std::string &nm) const {
  for (const auto r : st)
    if (nm == r.name())
      return true;
  return false;
}
void History::insert(const Record &r) & { st.insert(r); }
void History::insert(Record &&r) && { st.insert(std::move(r)); }
void History::erase(const Record &r) { st.erase(r); }
void History::clear() { st.clear(); }
bool History::check(const std::string &name) {
  for (const auto &r : st) {
    if (!dist_bigger_than_three_days(r.time(), Time()) && r.name() == name)
      return false;
  }
  return true;
}
