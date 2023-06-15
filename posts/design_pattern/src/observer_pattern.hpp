#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_HPP_
#define DESIGN_PATTERN_OBSERVER_PATTERN_HPP_

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
};
Subject::~Subject() {}
}  // namespace observer_pattern
}  // namespace design_pattern

#endif
