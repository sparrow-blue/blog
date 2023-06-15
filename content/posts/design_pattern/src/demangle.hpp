#ifndef DEMANGLE_HPP_
#define DEMANGLE_HPP_

#include <cxxabi.h>

#include <string>

/**
 * @brief 型名をデマングル化する．
 *
 * @param id デマングル化する型のtype_infoオブジェクト
 * @return std::string デマングル化された型名を表す文字列
 * @throws std::exception デマングル化が失敗した場合に投げられます
 *
 * @details
 * gcc および clang コンパイラでマングル化された型名をデマングル化します．
 */
std::string demangle(const std::type_info& id) {
  int status;
  char* demangled_name = abi::__cxa_demangle(id.name(), 0, 0, &status);

  if (status == 0) {
    auto result = std::string(demangled_name);
    free(demangled_name);
    return result;
  }

  throw std::exception();
}

#endif
