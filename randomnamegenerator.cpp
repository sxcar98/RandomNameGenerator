#include "history.hpp"
#include "randomnamegenerator.hpp"
#include "record.hpp"
#include "time.hpp"
#include <chrono>
#include <cstddef>
#include <fstream>
#include <ios>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

RandomNameGenerator::RandomNameGenerator() : hstry() {
  for (const auto &nm : lst)
    if (hstry.check(nm))
      st.push_back(nm);
}
const std::string &RandomNameGenerator::gen() const {
  return lst[rdm(lst.size())];
}

std::string RandomNameGenerator::gen_no_recent() {
  if (st.empty())
    throw std::runtime_error("");
  int rnd = rdm(st.size());
  Record r(st[rnd], Time());
  std::ofstream fopen("history.txt", std::ios::app);
  fopen << r << std::endl;
  fopen.close();
  hstry.insert(r);
  st.erase(st.begin() + rnd);
  return r.name();
}
int RandomNameGenerator::rdm(std::vector<std::string>::size_type sz) const {
  unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
  std::mt19937 rng(seed);
  std::uniform_int_distribution<int> dist(0, sz - 1);
  return dist(rng);
}
