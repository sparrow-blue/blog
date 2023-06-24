// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/blog/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_COMPONENT_DIAGRAM_HPP_
#define DESIGN_PATTERN_COMPONENT_DIAGRAM_HPP_

#include <sstream>
#include <string>

#include "../demangle.hpp"

namespace design_pattern::component {

/**
 * 描画される図形の抽象クラス
 */
class Diagram {
 public:
  Diagram() : height_(0), width_(0) {}
  virtual ~Diagram() = 0;
  /**
   * 自身の型と大きさを文字列で表現する．
   */
  std::string ToString() {
    std::stringstream ss;
    ss << Demangle(typeid(*this)) << " "
       << "(" << this->height() << "," << this->width() << ")";
    return ss.str();
  }
  /**
   * 自身の高さを返す．
   */
  int height() { return this->height_; }
  /**
   * 自身の幅を返す．
   */
  int width() { return this->width_; }
  /**
   * リサイズする．
   */
  virtual void Resize(int height, int width) {
    this->height_ = height;
    this->width_ = width;
  }

 private:
  int height_;
  int width_;
};
Diagram::~Diagram() {}

}  // namespace design_pattern::component

#endif  // DESIGN_PATTERN_COMPONENT_DIAGRAM_HPP_
