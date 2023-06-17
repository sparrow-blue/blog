// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_DISPLAY_HPP_
#define DESIGN_PATTERN_OBSERVER_PATTERN_DISPLAY_HPP_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

#include "../../join.hpp"
#include "Observable.hpp"
#include "ObservableDiagram.hpp"
#include "Observer.hpp"

namespace design_pattern::observer_pattern {

class Display : public Observer {
 public:
  void Register(std::shared_ptr<ObservableDiagram> subject) {
    subject->Subscribe([this, subject](std::shared_ptr<Observable> sender) {
      std::cout << std::static_pointer_cast<ObservableDiagram>(sender)->ToString() << std::endl;
    });
    this->objects_.push_back(subject);
  }

 private:
  std::vector<std::shared_ptr<ObservableDiagram>> objects_;
  std::string ToString() {
    auto messages = std::vector<std::string>();
    std::transform(this->objects_.begin(), this->objects_.end(), std::back_inserter(messages),
                   [](std::shared_ptr<ObservableDiagram> &subject) { return subject->ToString(); });
    return Join("\n", messages);
  }
  void Dump() { std::cout << this->ToString() << std::endl; }
};

}  // namespace design_pattern::observer_pattern

#endif  // DESIGN_PATTERN_OBSERVER_PATTERN_DISPLAY_HPP_
