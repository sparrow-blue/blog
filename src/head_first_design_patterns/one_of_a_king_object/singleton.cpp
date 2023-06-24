// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/blog/blob/main/LICENSE for details.

#include <memory>

class Singleton {
 private:
  // 外部からのインスタンス化を禁ずる．
  Singleton() {}
  static Singleton* singleton_;

 public:
  static Singleton* GetInstance() {
    // 内部からであればコンストラクタが呼べる．
    if (!singleton_) singleton_ = new Singleton();
    return singleton_;
  }

  // コピーコンストラクタなどは delete で禁止しなければならない．
  Singleton(const Singleton& other) = delete;
  void operator=(const Singleton&) = delete;
};

Singleton* Singleton::singleton_ = nullptr;

int main() {
  // コンストラクタが private なので外部からインスタンス化できない．
  // auto singleton = new Singleton();

  // static なメンバ関数からのみインスタンス化できる．
  auto singleton = Singleton::GetInstance();
}
