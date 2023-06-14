#ifndef JOIN_HPP_
#define JOIN_HPP_

#include <numeric>
#include <string>
#include <vector>

std::string Join(const std::string &delimitor,
                 const std::vector<std::string> &messages) {
  return std::accumulate(
      std::next(messages.begin()), messages.end(), messages[0],
      [delimitor](std::string a, std::string b) { return a + delimitor + b; });
}

#endif
