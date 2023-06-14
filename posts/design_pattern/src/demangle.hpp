#ifndef DEMANGLE_HPP_
#define DEMANGLE_HPP_

#include <cxxabi.h>

#include <string>

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
