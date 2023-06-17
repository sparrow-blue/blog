// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVER_HPP_
#define DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVER_HPP_

namespace design_pattern::observer_pattern {

class Observer {
 public:
  virtual ~Observer() = 0;
};
Observer::~Observer() {}

}  // namespace design_pattern::observer_pattern

#endif  // DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVER_HPP_
