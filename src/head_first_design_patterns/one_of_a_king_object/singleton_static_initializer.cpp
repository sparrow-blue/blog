// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/blog/blob/main/LICENSE for details.

#include <iostream>
#include <memory>

class Singleton {
 private:
  // 外部からのインスタンス化を禁ずる．
  Singleton() {}
  static Singleton* singleton_;

 public:
  static Singleton* GetInstance() {
    // 起動時に初期化されているため null check が不要である．
    return singleton_;
  }

  // コピーコンストラクタなどは delete で禁止しなければならない．
  Singleton(const Singleton& other) = delete;
  void operator=(const Singleton&) = delete;
};

// null でなくインスタンスで初期化する．
Singleton* Singleton::singleton_ = new Singleton();

int main() {
  // コンストラクタが private なので外部からインスタンス化できない．
  // auto singleton = new Singleton();

  // static なメンバ関数からのみインスタンス化できる．
  auto singleton = Singleton::GetInstance();
}
