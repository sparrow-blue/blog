// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/blog/blob/main/LICENSE for details.

#include "observer_pattern/observer_pattern.hpp"

using design_pattern::observer_pattern::Display;
using design_pattern::observer_pattern::ObservableLine;
using design_pattern::observer_pattern::ObservableTriangle;

/**
 * 画面上に図形を配置するようなケースを考える．
 * ObservableDiagram がモデル，Display はモデルを利用するプレゼンテーションのイメージである．
 * モデルの状態が変化すると Display に通知され，モデルが自動的に操作 (画面更新，ここでは標準出力) される．
 */
int main() {
  // モデルを利用するオブジェクト (Observer)
  auto display = Display();

  // 描画するモデルを生成する．
  auto line = std::make_shared<ObservableLine>();
  auto triangle = std::make_shared<ObservableTriangle>();

  // 画面に図形を配置する．実態は Observer が Obsavable なオブジェクトの購読を始める．
  display.Register(line);
  display.Register(triangle);

  // diagram の状態を変化させるごとに自動的に dump される．
  // モデルは自身がどう扱われるか気にしないが Observer が状態を監視しており，状態が変化した後になされる操作が
  // 自動的に実行される．プログラマもモデルの状態を変化させるだけでよく，そのあと行われる処理は別の文脈で考えればよい．
  line->Resize(100, 100);
  line->Resize(0, 0);
  line->Resize(101, 101);
  triangle->Resize(100, 100);
  triangle->Resize(0, 0);
  triangle->Resize(101, 101);

  return 0;
}
