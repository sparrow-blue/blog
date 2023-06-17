// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#include "observer_pattern/observer_pattern.hpp"

using design_pattern::observer_pattern::Display;
using design_pattern::observer_pattern::ObservableLine;
using design_pattern::observer_pattern::ObservableTriangle;

int main() {
  auto display = Display();
  auto line = std::make_shared<ObservableLine>();
  auto triangle = std::make_shared<ObservableTriangle>();

  // この時点で購読開始
  display.Register(line);
  display.Register(triangle);

  // line の状態を変化させるごとに自動的に dump される．
  line->Resize(100, 100);
  line->Resize(0, 0);
  line->Resize(101, 101);
  triangle->Resize(100, 100);
  triangle->Resize(0, 0);
  triangle->Resize(101, 101);

  return 0;
}
