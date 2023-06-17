#include "observer_pattern.hpp"

using namespace design_pattern::observer_pattern;

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
