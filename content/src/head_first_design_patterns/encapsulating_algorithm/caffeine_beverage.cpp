// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/blog/blob/main/LICENSE for details.

/// @brief 飲み物を淹れるカップを表現する
class Cup {};

/// @brief カフェインを含む飲み物を表現する
class CaffeineBeverage {
 public:
  /// @brief 抽象化された手続き
  virtual Cup PrepareRecipe() final {
    // この部分が Template Method であり，それぞれの処理自体は具象クラスの実装に任せる．
    this->BoilWater();
    this->Brew();
    this->PourInCup();
    this->AddCondiments();
    return cup_;
  }

 protected:
  /// @brief カップ
  Cup cup_;
  /// @brief お湯を沸かす
  virtual void BoilWater() {}
  /// @brief 淹れる
  virtual void Brew() {}
  /// @brief カップにそそぐ
  virtual void PourInCup() {}
  /// @brief ミルクやレモンなどを添加する
  virtual void AddCondiments() {}
};

class Coffee : public CaffeineBeverage {
 protected:
  virtual void Brew() { /* コーヒーを淹れる */
  }
  virtual void AddCondiments() { /* ミルクを入れる */
  }
};

class Tea : public CaffeineBeverage {
  virtual void Brew() { /* 紅茶を淹れる */
  }
  virtual void AddCondiments() { /* レモンを入れる */
  }
};

int main() {}
