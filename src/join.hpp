/*
 Copyright (c) 2023 Kumazawa

 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 of the Software, and to permit persons to whom the Software is furnished to do
 so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

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

#endif  // JOIN_HPP_
