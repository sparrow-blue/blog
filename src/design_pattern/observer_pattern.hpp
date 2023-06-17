// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_HPP_
#define DESIGN_PATTERN_OBSERVER_PATTERN_HPP_

#include <algorithm>
#include <functional>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "../join.hpp"
#include "command_pattern.hpp"
#include "component/Canvas.hpp"
#include "component/Diagram.hpp"
#include "component/Line.hpp"
#include "component/Triangle.hpp"

namespace design_pattern::observer_pattern {
class Observer {
 public:
  virtual ~Observer() = 0;
};
Observer::~Observer() {}

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

class ObservableLine : public ObservableDiagram {
 public:
  ObservableLine() : ObservableDiagram(std::make_unique<Line>()) {}
};

class ObservableTriangle : public ObservableDiagram {
 public:
  ObservableTriangle() : ObservableDiagram(std::make_unique<Triangle>()) {}
};

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

#endif  // DESIGN_PATTERN_OBSERVER_PATTERN_HPP_
