// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/imageimporter/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_COMPONENT_CANVAS_HPP_
#define DESIGN_PATTERN_COMPONENT_CANVAS_HPP_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "../demangle.hpp"
#include "../join.hpp"
#include "Diagram.hpp"

namespace design_pattern::component {

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

}  // namespace design_pattern::component

#endif  // DESIGN_PATTERN_COMPONENT_CANVAS_HPP_
