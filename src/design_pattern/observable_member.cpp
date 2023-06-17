// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#include "observable_member/observable_member.hpp"

#include <iostream>

using design_pattern::observable_member::EventHandler;
using design_pattern::observable_member::EventArgs;
using design_pattern::observable_member::ObservableLine;

int main() {
  auto observable_line = ObservableLine(10, 10);
  observable_line.HeightChanged += [](void* sender, EventArgs<int> e) {
    std::cout << "Height Changed: " << e.old_value << " -> " << e.new_value << std::endl;
  };
  observable_line.WidthChanged += [](void* sender, EventArgs<int> e) {
    std::cout << "Width Changed: " << e.old_value << " -> " << e.new_value << std::endl;
  };

  // 値の変更をトリガにイベントを発火する．
  observable_line.height(9);
  observable_line.width(0);
  return 0;
}
