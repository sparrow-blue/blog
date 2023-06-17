// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_HPP_
#define DESIGN_PATTERN_OBSERVER_PATTERN_HPP_

#include <algorithm>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "../join.hpp"
#include "command_pattern.hpp"

namespace design_pattern {
namespace observer_pattern {
class Observer {
 public:
  virtual ~Observer() = 0;
};
Observer::~Observer() {}

class Subject {
 public:
  virtual ~Subject() = 0;
  void Subscribe(std::function<void(void)> &&func) { subscribers_.push_back(func); }

 protected:
  void Notify() {
    std::for_each(this->subscribers_.begin(), this->subscribers_.end(), [](auto &func) { func(); });
  }

 private:
  std::vector<std::function<void(void)>> subscribers_;
};
Subject::~Subject() {}

class Line : public Subject, public command_pattern::Line {
 public:
  virtual void Resize(int height, int width) {
    if (command_pattern::Line::height() == height && command_pattern::Line::width() == width) return;
    command_pattern::Line::Resize(height, width);
    Notify();
  }
};

class Display : public Observer {
 public:
  void Register(std::shared_ptr<Line> subject) {
    subject->Subscribe([this]() { this->Dump(); });
    this->objects_.push_back(subject);
  }
  // void Unregister(std::shared_ptr<Subject> subject) {
  // 実現には工夫が必要だ．
  // }

 private:
  std::vector<std::shared_ptr<Line>> objects_;
  std::string ToString() {
    auto messages = std::vector<std::string>();
    std::transform(this->objects_.begin(), this->objects_.end(), std::back_inserter(messages),
                   [](std::shared_ptr<Line> &subject) { return subject->ToString(); });
    return Join("\n", messages);
  }
  void Dump() { std::cout << this->ToString() << std::endl; }
};

}  // namespace observer_pattern
}  // namespace design_pattern

#endif  // DESIGN_PATTERN_OBSERVER_PATTERN_HPP_
