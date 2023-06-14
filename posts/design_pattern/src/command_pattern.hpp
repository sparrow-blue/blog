#ifndef DESIGN_PATTERN_COMMAND_PATTERN_HPP_
#define DESIGN_PATTERN_COMMAND_PATTERN_HPP_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <queue>
#include <sstream>

#include "join.hpp"
#include "demangle.hpp"

namespace design_pattern {
namespace command_pattern {
class Receiver {
 public:
  virtual std::string ToString() = 0;
};

/**
 * 描画される図形の抽象クラス
 */
class Diagram : Receiver {
 public:
  Diagram() : height(0), width(0) {}
  virtual ~Diagram() = 0;
  int height;
  int width;
  std::string ToString() {
    std::stringstream ss;
    ss << demangle(typeid(*this)) << " "
       << "(" << this->height << "," << this->width << ")";
    return ss.str();
  }
};
Diagram::~Diagram() {}

/**
 * 図形が描画されるキャンバス
 */
class Canvas : Receiver {
 public:
  void AddDiagram(std::shared_ptr<Diagram> diagram) {
    this->diagrams.push_back(diagram);
  }
  void Dump() {
    std::cout << (this->diagrams.size() != 0 ? this->ToString()
                                             : std::string("empty"))
              << std::endl;
    }
  std::string ToString() {
    auto messages = std::vector<std::string>();
    std::transform(
        this->diagrams.begin(), this->diagrams.end(),
        std::back_inserter(messages),
        [](std::shared_ptr<Diagram> diagram) { return diagram->ToString(); });

    return Join("\n", messages);
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
  Command(std::shared_ptr<design_pattern::command_pattern::Canvas> canvas_)
      : canvas(canvas_) {}
  virtual void Execute() = 0;
  virtual std::string ToString() = 0;

 protected:
  std::shared_ptr<Canvas> canvas;
};

/*
 * 線分の生成を担うコマンド
 */
class CreateLineDiagramCommand : public Command {
 public:
  CreateLineDiagramCommand(
      std::shared_ptr<design_pattern::command_pattern::Canvas> canvas_)
      : Command(canvas_) {}
  virtual void Execute() {
    auto new_diagram = std::make_shared<Line>();
    this->canvas->AddDiagram(new_diagram);
  }

  virtual std::string ToString() { return demangle(typeid(*this)); }
};

/*
 * 三角形の生成を担うコマンド
 */
class CreateTriangleDiagramCommand : public Command {
 public:
  CreateTriangleDiagramCommand(
      std::shared_ptr<design_pattern::command_pattern::Canvas> canvas_)
      : Command(canvas_) {
    auto new_diagram = std::make_shared<Triangle>();
    this->canvas->AddDiagram(new_diagram);
  }
  virtual void Execute() {}

  virtual std::string ToString() { return demangle(typeid(*this)); }
};

/*
 * 図形の移動を担うコマンド
 */
class MoveDiagramCommand : public Command {
 public:
  virtual void Execute() {}

  virtual std::string ToString() { return demangle(typeid(*this)); }
};

/*
 * 図形のリサイズを担うコマンド
 */
class ResizeDiagramCommand : public Command {
 public:
  virtual void Execute() {}

  virtual std::string ToString() { return demangle(typeid(*this)); }
};

class Executer {
 private:
  std::vector<std::shared_ptr<Command>> execution_history_;

 public:
  Executer &operator+=(std::shared_ptr<Command> &&command) {
    command->Execute();
    this->execution_history_.push_back(command);
    return *this;
  }

  void DumpExecutionHistory() {
    if (this->execution_history_.size())
      std::for_each(
          this->execution_history_.begin(), this->execution_history_.end(),
          [idx = 0](auto &command) mutable {
            std::cout << idx++ << ": " << command->ToString() << std::endl;
          });
    else
      std::cout << "empty" << std::endl;
  }
};

}  // namespace command_pattern
}  // namespace design_pattern

#endif
