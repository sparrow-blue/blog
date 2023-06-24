// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/blog/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVABLE_MEMBER_OBSERVABLEDIAGRAM_HPP_
#define DESIGN_PATTERN_OBSERVABLE_MEMBER_OBSERVABLEDIAGRAM_HPP_

#include "EventHandler.hpp"

namespace design_pattern::observable_member {

class ObservableDiagram {
 public:
  ObservableDiagram(int width, int height) : width_(width), height_(height) {}

#pragma region width

  EventHandler<int> WidthChanged;

  void width(int width) {
    auto event_args = EventArgs<int>(width, width_);
    this->width_ = width;
    WidthChanged.Invoke(this, event_args);
  }

  int width() { return this->width_; }

#pragma endregion

#pragma region height

  EventHandler<int> HeightChanged;

  void height(int height) {
    auto event_args = EventArgs<int>(height, height_);
    this->height_ = height;
    HeightChanged.Invoke(this, event_args);
  }

  int height() { return this->height_; }

#pragma endregion

 private:
  int width_;
  int height_;
};

}  // namespace design_pattern::observable_member

#endif  // DESIGN_PATTERN_OBSERVABLE_MEMBER_OBSERVABLEDIAGRAM_HPP_
