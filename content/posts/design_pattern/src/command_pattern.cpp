#include "command_pattern.hpp"

using namespace design_pattern::command_pattern;

int main() {
  auto canvas = std::make_shared<Canvas>();
  auto execution_queue = std::queue<std::shared_ptr<Command>>();
  auto execution_history = std::list<std::shared_ptr<Command>>();
  auto executer = Executer();

  auto dumper =
      [&canvas, &executer]() {
        std::cout << "# state" << std::endl;
        std::cout << "## canvas" << std::endl;
        canvas->Dump();

        std::cout << "## executer" << std::endl;
        executer.DumpExecutionHistory();
      };

  dumper();

  std::cout<< "# execution phase"<< std::endl;

  executer += std::make_shared<CreateLineDiagramCommand>(canvas);
  executer += std::make_shared<CreateTriangleDiagramCommand>(canvas);

  dumper();
}
