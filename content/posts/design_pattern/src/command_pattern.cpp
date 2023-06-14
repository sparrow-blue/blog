#include "command_pattern.hpp"

using namespace design_pattern::command_pattern;

int main() {
  auto canvas = std::make_shared<Canvas>();
  auto execution_queue = std::queue<std::shared_ptr<Command>>();
  auto execution_history = std::list<std::shared_ptr<Command>>();

  std::cout << "# initial state" << std::endl;
  canvas->dump();

  execution_queue.push(std::make_shared<CreateLineDiagramCommand>(canvas));
  execution_queue.push(std::make_shared<CreateTriangleDiagramCommand>(canvas));

  while (execution_queue.size()) {
    auto command = execution_queue.front();
    command->Execute();
    execution_history.push_back(command);
    execution_queue.pop();
  }

  std::cout << "# final state" << std::endl;
  canvas->dump();

  std::cout << "# history" << std::endl;
  std::for_each(execution_history.begin(), execution_history.end(),
                [idx = 0](auto& command) mutable {
                  std::cout << idx++ << ": " << command->to_string()
                            << std::endl;
                });
}
