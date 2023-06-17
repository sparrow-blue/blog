#ifndef DESIGN_PATTERN_COMMAND_PATTERN_HPP_
#define DESIGN_PATTERN_COMMAND_PATTERN_HPP_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <queue>
#include <sstream>

#include "../demangle.hpp"
#include "../join.hpp"

namespace design_pattern {
namespace command_pattern {

/**
 * 描画される図形の抽象クラス
 */
class Diagram {
 public:
  Diagram() : height_(0), width_(0) {}
  virtual ~Diagram() = 0;
  std::string ToString() {
    std::stringstream ss;
    ss << Demangle(typeid(*this)) << " "
       << "(" << this->height() << "," << this->width() << ")";
    return ss.str();
  }
  int height() { return this->height_; }
  int width() { return this->width_; }
  virtual void Resize(int height, int width) {
    this->height_ = height;
    this->width_ = width;
  }

 private:
  int height_;
  int width_;
};
Diagram::~Diagram() {}

/**
 * 図形が描画されるキャンバス
 */
class Canvas {
 public:
  void AddDiagram(std::shared_ptr<Diagram> diagram) {
    this->diagram_sets.push_back(std::make_shared<DiagramSet>(diagram));
  }
  void Dump() {
    std::cout << (this->diagram_sets.size() != 0 ? this->ToString()
                                                 : std::string("empty"))
              << std::endl;
  }
  std::string ToString() {
    auto messages = std::vector<std::string>();
    std::transform(diagram_sets.begin(), diagram_sets.end(),
                   std::back_inserter(messages),
                   [](std::shared_ptr<DiagramSet> diagram_set) {
                     return diagram_set->ToString();
                   });
    return Join("\n", messages);
  }
  void Move(size_t index, int offset_x, int offset_y) {
    this->diagram_sets.at(index)->Move(offset_x, offset_y);
  }
  std::vector<std::shared_ptr<Diagram>> diagrams() {
    auto result = std::vector<std::shared_ptr<Diagram>>();
    std::transform(this->diagram_sets.begin(), this->diagram_sets.end(),
                   std::back_inserter(result),
                   [](std::shared_ptr<DiagramSet> diagram_set_) {
                     return diagram_set_->diagram();
                   });
    return result;
  }

 private:
  /**
   * Canvas が管理する Diagram のそれぞれがどの位置に存在するかを管理する
   */
  class DiagramSet {
   public:
    DiagramSet(std::shared_ptr<Diagram> diagram, int x = 0, int y = 0)
        : diagram_(diagram), x_(x), y_(y) {}
    void Move(int offset_x, int offset_y) {
      this->x_ += offset_x;
      this->y_ += offset_y;
    }
    std::shared_ptr<Diagram> diagram() { return this->diagram_; };
    std::string ToString() {
      char buffer[0xFF];
      sprintf(buffer, "x: %d, y: %d - %s", this->x_, this->y_,
              this->diagram_->ToString().c_str());
      return buffer;
    }

   private:
    std::shared_ptr<Diagram> diagram_;
    int x_;
    int y_;
  };
  std::vector<std::shared_ptr<DiagramSet>> diagram_sets;
};

/**
 * 線分を表現するクラス
 */
class Line : public Diagram {
 public:
  Line() { this->Resize(0, 5); }
  virtual void Resize(int height, int width) override {
    // height は無視する
    Diagram::Resize(0, width);
  }
};

/**
 * 三角形を表現するクラス
 */
class Triangle : public Diagram {
 public:
  Triangle() { this->Resize(5, 10); }
};

/**
 * コマンドの抽象クラス
 */
class Command {
 public:
  Command(std::shared_ptr<design_pattern::command_pattern::Canvas> canvas_)
      : canvas_(canvas_) {}
  virtual void Execute() = 0;
  virtual std::string ToString() = 0;

 protected:
  std::shared_ptr<Canvas> canvas_;
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
    this->canvas_->AddDiagram(new_diagram);
  }

  virtual std::string ToString() { return Demangle(typeid(*this)); }
};

/*
 * 三角形の生成を担うコマンド
 */
class CreateTriangleDiagramCommand : public Command {
 public:
  CreateTriangleDiagramCommand(
      std::shared_ptr<design_pattern::command_pattern::Canvas> canvas_)
      : Command(canvas_) {}
  virtual void Execute() {
    auto new_diagram = std::make_shared<Triangle>();
    this->canvas_->AddDiagram(new_diagram);
  }

  virtual std::string ToString() { return Demangle(typeid(*this)); }
};

/*
 * 図形の移動を担うコマンド
 */
class MoveDiagramCommand : public Command {
 public:
  MoveDiagramCommand(
      std::shared_ptr<design_pattern::command_pattern::Canvas> canvas_,
      size_t index, int offset_x, int offset_y)
      : Command(canvas_),
        index_(index),
        offset_x_(offset_x),
        offset_y_(offset_y) {}
  virtual void Execute() {
    canvas_->Move(this->index_, this->offset_x_, this->offset_y_);
  }
  virtual std::string ToString() { return Demangle(typeid(*this)); }

 private:
  size_t index_;
  int offset_x_;
  int offset_y_;
};

/*
 * 図形のリサイズを担うコマンド
 */
class ResizeDiagramCommand : public Command {
 public:
  ResizeDiagramCommand(
      std::shared_ptr<design_pattern::command_pattern::Canvas> canvas_,
      size_t index, int target_height, int target_width)
      : Command(canvas_),
        index_(index),
        height_(target_height),
        width_(target_width) {}
  virtual void Execute() {
    this->canvas_->diagrams().at(index_)->Resize(this->target_height(),
                                                 this->target_width());
  }
  int target_height() { return this->height_; }
  int target_width() { return this->width_; }

  virtual std::string ToString() { return Demangle(typeid(*this)); }

 private:
  size_t index_;
  int height_;
  int width_;
};

/**
 * コマンドの実行し，その履歴を保持する．
 */
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
