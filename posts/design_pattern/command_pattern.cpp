#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include <queue>
#include <sstream>

namespace DesignPattern {
namespace CommandPattern {
/**
 * 描画される図形の抽象クラス
 */
class Diagram {
 public:
  Diagram() : height(0), width(0) {}
  virtual ~Diagram() = 0;
  int height;
  int width;
  std::string to_string() {
    std::stringstream ss;
    ss << typeid(this).name() << ": "
       << "(" << this->height << "," << this->width << ")";
    return ss.str();
  }
};
Diagram::~Diagram() {}

/**
 * 図形が描画されるキャンバス
 */
class Canvas {
 public:
  void AddDiagram(std::shared_ptr<Diagram> diagram) {
    this->diagrams.push_back(diagram);
  }
  void dump() {
    std::for_each(
        this->diagrams.begin(), this->diagrams.end(),
        [](auto diagram) { std::cout << diagram->to_string() << std::endl; });
  }

 private:
  std::vector<std::shared_ptr<Diagram>> diagrams;
};

/**
 * 線分を表現するクラス
 */
class Line : public Diagram {
 public:
  Line() { this->width = 10; }
};

/**
 * 三角形を表現するクラス
 */
class Triangle : public Diagram {
 public:
  Triangle() {
    this->width = 10;
    this->height = 5;
  }
};

/**
 * コマンドの抽象クラス
 */
class Command {
 public:
  Command(std::shared_ptr<DesignPattern::CommandPattern::Canvas> canvas_)
      : canvas(canvas_) {}
  virtual void Execute() = 0;

 protected:
  std::shared_ptr<Canvas> canvas;
};

/*
 * 線分の生成を担うコマンド
 */
class CreateLineDiagramCommand : public Command {
 public:
  CreateLineDiagramCommand(
      std::shared_ptr<DesignPattern::CommandPattern::Canvas> canvas_)
      : Command(canvas_) {}
  virtual void Execute() {
    auto new_diagram = std::make_shared<Line>();
    this->canvas->AddDiagram(new_diagram);
  }
};

/*
 * 三角形の生成を担うコマンド
 */
class CreateTriangleDiagramCommand : public Command {
 public:
  CreateTriangleDiagramCommand(
      std::shared_ptr<DesignPattern::CommandPattern::Canvas> canvas_)
      : Command(canvas_) {
    auto new_diagram = std::make_shared<Triangle>();
    this->canvas->AddDiagram(new_diagram);
  }
  virtual void Execute() {}
};

/*
 * 図形の移動を担うコマンド
 */
class MoveDiagramCommand : public Command {
 public:
  virtual void Execute() {}
};

/*
 * 図形のリサイズを担うコマンド
 */
class ResizeDiagramCommand : public Command {
 public:
  virtual void Execute() {}
};
}  // namespace CommandPattern
}  // namespace DesignPattern

using namespace DesignPattern::CommandPattern;
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
}
