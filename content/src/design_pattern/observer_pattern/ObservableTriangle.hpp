// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLETRIANGLE_HPP_
#define DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLETRIANGLE_HPP_

#include <memory>

#include "../component/Triangle.hpp"
#include "ObservableDiagram.hpp"

using design_pattern::component::Triangle;

namespace design_pattern::observer_pattern {

class ObservableTriangle : public ObservableDiagram {
 public:
  ObservableTriangle() : ObservableDiagram(std::make_unique<Triangle>()) {}
};

}  // namespace design_pattern::observer_pattern

#endif  // DESIGN_PATTERN_OBSERVER_PATTERN_OBSERVABLETRIANGLE_HPP_
