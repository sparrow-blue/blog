// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#include "command_pattern.hpp"

using design_pattern::command_pattern::Canvas;
using design_pattern::command_pattern::Command;
using design_pattern::command_pattern::CreateLineDiagramCommand;
using design_pattern::command_pattern::CreateTriangleDiagramCommand;
using design_pattern::command_pattern::Executor;
using design_pattern::command_pattern::MoveDiagramCommand;
using design_pattern::command_pattern::ResizeDiagramCommand;

int main() {
  auto canvas = std::make_shared<Canvas>();
  auto execution_queue = std::queue<std::shared_ptr<Command>>();
  auto execution_history = std::list<std::shared_ptr<Command>>();
  auto executor = Executor();

  auto dumper = [&canvas, &executor]() {
    std::cout << "# state" << std::endl;
    std::cout << "## canvas" << std::endl;
    canvas->Dump();

    std::cout << "## executor" << std::endl;
    executor.DumpExecutionHistory();
  };

  // 初期状態の出力
  dumper();

  {  // 図形をキャンバスに追加する
    std::cout << "# add diagrams" << std::endl;
    executor += std::make_shared<CreateLineDiagramCommand>(canvas);
    executor += std::make_shared<CreateTriangleDiagramCommand>(canvas);
  }
  dumper();

  {  // 諸図形に対して操作する
    std::cout << "# operate diagrams" << std::endl;

    executor += std::make_shared<ResizeDiagramCommand>(canvas, 0, 100, 200);
    executor += std::make_shared<MoveDiagramCommand>(canvas, 1, 250, 50);
    executor += std::make_shared<MoveDiagramCommand>(canvas, 0, 100, 500);
  }
  dumper();
}
