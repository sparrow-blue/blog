// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_COMMAND_PATTERN_HPP_
#define DESIGN_PATTERN_COMMAND_PATTERN_HPP_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include "../demangle.hpp"
#include "../join.hpp"
#include "component/Canvas.hpp"
#include "component/Diagram.hpp"
#include "component/Line.hpp"
#include "component/Triangle.hpp"

using design_pattern::component::Diagram;
using design_pattern::component::Line;
using design_pattern::component::Triangle;

namespace design_pattern::command_pattern {

/**
 * 図形が描画されるキャンバス
 */
class Canvas {
 public:
  void AddDiagram(std::shared_ptr<Diagram> diagram) {
    this->diagram_sets.push_back(std::make_shared<DiagramSet>(diagram));
  }
  void Dump() { std::cout << (this->diagram_sets.size() != 0 ? this->ToString() : std::string("empty")) << std::endl; }
  std::string ToString() {
    auto messages = std::vector<std::string>();
    std::transform(diagram_sets.begin(), diagram_sets.end(), std::back_inserter(messages),
                   [](std::shared_ptr<DiagramSet> diagram_set) { return diagram_set->ToString(); });
    return Join("\n", messages);
  }
  void Move(size_t index, int offset_x, int offset_y) { this->diagram_sets.at(index)->Move(offset_x, offset_y); }
  std::vector<std::shared_ptr<Diagram>> diagrams() {
    auto result = std::vector<std::shared_ptr<Diagram>>();
    std::transform(this->diagram_sets.begin(), this->diagram_sets.end(), std::back_inserter(result),
                   [](std::shared_ptr<DiagramSet> diagram_set_) { return diagram_set_->diagram(); });
    return result;
  }

 private:
  /**
   * Canvas が管理する Diagram のそれぞれがどの位置に存在するかを管理する
   */
  class DiagramSet {
   public:
    explicit DiagramSet(std::shared_ptr<Diagram> diagram, int x = 0, int y = 0) : diagram_(diagram), x_(x), y_(y) {}
    void Move(int offset_x, int offset_y) {
      this->x_ += offset_x;
      this->y_ += offset_y;
    }
    std::shared_ptr<Diagram> diagram() { return this->diagram_; }
    std::string ToString() {
      char buffer[0xFF];
      sprintf(buffer, "x: %d, y: %d - %s", this->x_, this->y_, this->diagram_->ToString().c_str());
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
 * コマンドの抽象クラス
 */
class Command {
 public:
  explicit Command(std::shared_ptr<design_pattern::command_pattern::Canvas> canvas) : canvas_(canvas) {}
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
  explicit CreateLineDiagramCommand(std::shared_ptr<design_pattern::command_pattern::Canvas> canvas)
      : Command(canvas) {}
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
  explicit CreateTriangleDiagramCommand(std::shared_ptr<design_pattern::command_pattern::Canvas> canvas_)
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
  MoveDiagramCommand(std::shared_ptr<design_pattern::command_pattern::Canvas> canvas_, size_t index, int offset_x,
                     int offset_y)
      : Command(canvas_), index_(index), offset_x_(offset_x), offset_y_(offset_y) {}
  virtual void Execute() { canvas_->Move(this->index_, this->offset_x_, this->offset_y_); }
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
  ResizeDiagramCommand(std::shared_ptr<design_pattern::command_pattern::Canvas> canvas_, size_t index,
                       int target_height, int target_width)
      : Command(canvas_), index_(index), height_(target_height), width_(target_width) {}
  virtual void Execute() { this->canvas_->diagrams().at(index_)->Resize(this->target_height(), this->target_width()); }
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
class Executor {
 private:
  std::vector<std::shared_ptr<Command>> execution_history_;

 public:
  Executor &operator+=(std::shared_ptr<Command> &&command) {
    command->Execute();
    this->execution_history_.push_back(command);
    return *this;
  }

  void DumpExecutionHistory() {
    if (this->execution_history_.size()) {
      std::for_each(this->execution_history_.begin(), this->execution_history_.end(), [idx = 0](auto &command) mutable {
        std::cout << idx++ << ": " << command->ToString() << std::endl;
      });
    } else {
      std::cout << "empty" << std::endl;
    }
  }
};

}  // namespace design_pattern::command_pattern

#endif  // DESIGN_PATTERN_COMMAND_PATTERN_HPP_
