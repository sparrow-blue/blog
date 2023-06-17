// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLELINE_HPP_
#define DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLELINE_HPP_

#include <memory>

#include "../component/Line.hpp"
#include "observer_pattern/ObservableDiagram.hpp"

using design_pattern::component::Line;

namespace design_pattern::observer_pattern {

class ObservableLine : public ObservableDiagram {
 public:
  ObservableLine() : ObservableDiagram(std::make_unique<Line>()) {}
};

}  // namespace design_pattern::observer_pattern

#endif  // DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLELINE_HPP_
