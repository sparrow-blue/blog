// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLE_HPP_
#define DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLE_HPP_

#include <functional>
#include <memory>
#include <vector>

namespace design_pattern::observer_pattern {

/**
 * 監視可能なオブジェクトを表現する
 */
class Observable : public std::enable_shared_from_this<Observable> {
 public:
  void Subscribe(std::function<void(std::shared_ptr<Observable>)> &&func) { subscribers_.push_back(func); }

 protected:
  void Notify() {
    std::for_each(this->subscribers_.begin(), this->subscribers_.end(),
                  [this](auto &func) { func(shared_from_this()); });
  }

 private:
  std::vector<std::function<void(std::shared_ptr<Observable>)>> subscribers_;
};

}  // namespace design_pattern::observer_pattern

#endif  // DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLE_HPP_
