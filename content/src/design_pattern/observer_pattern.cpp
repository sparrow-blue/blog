// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#include "observer_pattern.hpp"

using design_pattern::observer_pattern::Display;
using design_pattern::observer_pattern::Line;

int main() {
  auto display = Display();
  auto line = std::make_shared<Line>();

  // この時点で購読開始
  display.Register(line);

  // line の状態を変化させるごとに自動的に dump される．
  line->Resize(100, 100);
  line->Resize(0, 0);
  line->Resize(101, 101);

  return 0;
}
