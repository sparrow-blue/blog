// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/blog/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLEDIAGRAM_HPP_
#define DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLEDIAGRAM_HPP_

#include <memory>
#include <string>
#include <utility>

#include "../component/Diagram.hpp"
#include "Observable.hpp"

using design_pattern::component::Diagram;

namespace design_pattern::observer_pattern {

/**
 * 監視可能な図形を表現する．
*/
class ObservableDiagram : public Observable {
 public:
  virtual void Resize(int height, int width) {
    if (diagram()->height() == height && diagram()->width() == width) return;
    diagram()->Resize(height, width);
    this->Notify();
  }
  std::string ToString() { return diagram()->ToString(); }

 protected:
  explicit ObservableDiagram(std::unique_ptr<Diagram> diagram) : diagram_(std::move(diagram)) {}
  const std::unique_ptr<Diagram> &diagram() { return this->diagram_; }

 private:
  const std::unique_ptr<Diagram> diagram_;
};

}  // namespace design_pattern::observer_pattern

#endif  // DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLEDIAGRAM_HPP_
