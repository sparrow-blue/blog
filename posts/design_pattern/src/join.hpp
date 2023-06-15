#ifndef JOIN_HPP_
#define JOIN_HPP_

#include <numeric>
#include <string>
#include <vector>

/**
 * @brief 文字列の配列を指定したデリミタで結合する．
 *
 * @param delimitor 文字列を連結する際の区切り文字
 * @param messages 連結する文字列の配列
 * @return std::string 連結された文字列
 *
 * @details
 * 指定したデリミタで文字列の配列を連結する．
 * デリミタに "," を指定し，文字列の配列として {"Hello", * "World"}
 * を指定した場合，"Hello,World"を返します．
 */
std::string Join(const std::string &delimitor,
                 const std::vector<std::string> &messages) {
  return std::accumulate(
      std::next(messages.begin()), messages.end(), messages[0],
      [delimitor](std::string a, std::string b) { return a + delimitor + b; });
}

#endif
