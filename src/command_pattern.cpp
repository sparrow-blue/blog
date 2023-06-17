#include "command_pattern.hpp"

using namespace design_pattern::command_pattern;

int main() {
  auto canvas = std::make_shared<Canvas>();
  auto execution_queue = std::queue<std::shared_ptr<Command>>();
  auto execution_history = std::list<std::shared_ptr<Command>>();
  auto executer = Executer();

  auto dumper = [&canvas, &executer]() {
    std::cout << "# state" << std::endl;
    std::cout << "## canvas" << std::endl;
    canvas->Dump();

    std::cout << "## executer" << std::endl;
    executer.DumpExecutionHistory();
  };
  
  // 初期状態の出力
  dumper();

  { // 図形をキャンバスに追加する
    std::cout << "# add diagrams" << std::endl;
    executer += std::make_shared<CreateLineDiagramCommand>(canvas);
    executer += std::make_shared<CreateTriangleDiagramCommand>(canvas);
  }
  dumper();

  { // 諸図形に対して操作する
    std::cout << "# operate diagrams" << std::endl;

    executer += std::make_shared<ResizeDiagramCommand>(canvas, 0, 100, 200);
    executer += std::make_shared<MoveDiagramCommand>(canvas, 1, 250, 50);
    executer += std::make_shared<MoveDiagramCommand>(canvas, 0, 100, 500);
  }
  dumper();
}
