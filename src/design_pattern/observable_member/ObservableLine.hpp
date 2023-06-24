// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/blog/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVABLE_MEMBER_OBSERVABLELINE_HPP_
#define DESIGN_PATTERN_OBSERVABLE_MEMBER_OBSERVABLELINE_HPP_

#include "ObservableDiagram.hpp"

namespace design_pattern::observable_member {

class ObservableLine : public ObservableDiagram {
 public:
  ObservableLine(int width, int height) : ObservableDiagram(width, height) {}
};

}  // namespace design_pattern::observable_member

#endif  // DESIGN_PATTERN_OBSERVABLE_MEMBER_OBSERVABLELINE_HPP_
