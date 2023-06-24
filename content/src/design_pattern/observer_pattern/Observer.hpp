// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/blog/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVER_HPP_
#define DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVER_HPP_

#include <memory>
#include <vector>

namespace design_pattern::observer_pattern {

/**
 * 監視する責務を負う抽象クラスである．
 * テンプレートの型は Observable を継承したクラスでなければならない．
*/
template <typename T>
class Observer {
  static_assert(std::is_base_of<Observable, T>::value, "T must inherit from Observable");

 public:
  // NOLINTNEXTLINE(readability/inheritance)
  virtual void Register(std::shared_ptr<T> subject) final {
    subject->Subscribe([this](std::shared_ptr<Observable> sender) { this->OnPublished(sender); });
    this->objects_.push_back(subject);
  }

  virtual void OnPublished(std::shared_ptr<Observable> sender) = 0;

  virtual ~Observer() {}

 protected:
  std::vector<std::weak_ptr<T>> objects_;  // Weak pointers to avoid circular references
};

}  // namespace design_pattern::observer_pattern

#endif  // DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVER_HPP_
