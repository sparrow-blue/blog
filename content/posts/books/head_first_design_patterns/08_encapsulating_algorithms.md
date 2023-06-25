---
date: "2023-06-24"
description: ""
draft: false
# expiryDate: ""
keywords: []
# lastmod: ""
# publishDate: 1970-01-01
# slug: ""
# summary: ""
title : "アルゴリズムのカプセル化 / Encapsulating Algorithm"
# type: ""
# url ""
# weight: 
tags: ["Design Pattern", "Head First Design Patterns", "Templata Method"]
categories: ["book", "design"]
---

## Template Method Pattern

同じような処理の流れを踏むクラスが複数あったとして，Template Method Pattern は処理の流れを抽象化する．

本文中では例として以下の 2 つのクラスを考えている．
1. コーヒーを淹れる
2. 紅茶を淹れる

それぞれ，大枠として以下の 4 つのステップを踏むという点で共通している．

1. お湯を沸かす
2. コーヒー/紅茶を抽出する
3. カップに注ぐ
4. コンディメントを淹れる

Template Method Pattern はこの一連の手続きの流れ自体を抽象化する．

### Template Method Pattern の定義

本書では以下のように Template Method Pttern を定義している．

> Template Method パターンは，メソッド内でアルゴリズムの骨組みを定義し，一部の手順をサブクラスに委ねる．Template Method は，アルゴリズムの構造を変えることなく，アルゴリズムのある手順をサブクラスに再定義させる．

### CaffeineBeverage の実装

本文中にある例をベースに Template Method Pattern の例を示す．

{{< readfile file="head_first_design_patterns/encapsulating_algorithm/caffeine_beverage.cpp" lang="cpp" is_open="true" >}}

### ハリウッドの原則 / Hollywood Principle

> ハリウッドの原則  
> こちらを呼び出すな．こちらから呼び出す．  
> (Don't call up, we'll call you.)

Object Oriented Design におけるハリウッドの原則は，コンポーネント (典型的にはオブジェクト) 間の依存 (参照) 関係にルールを持たせようとするものである．OSI Reference Model や TCP/IP Protocol Suite の概念が類するといえるだろう．つまり上位のレイヤは下位のレイヤに依存するが，下位のレイヤは上位のレイヤに依存しない関係である．

Template Method Pattern の文脈でこの言葉が出てきたのは親クラスが呼び出し方を定義し，子クラスが呼び出される処理を実装する，という意味で子クラスはハリウッドの原則でいうところの呼び出される側に徹している，という意味合いであると思われる．

高水準コンポーネントと低水準コンポーネントについては 4 章 (P.139) で説明されているので，引用しておく．

> 「高水準」コンポーネントとは，他の「低水準」コンポーネントに対して定義された振る舞いを持つクラスのことです．

なお，ハリウッドの原則と依存関係反転の原則の関係性について述べられている (P.300) が，依存関係反転の原則については 4 章で説明されているとのことなので，ここでは言及しない．  
// 章立ての順で読んでいないため，8 章についてのまとめを書いている今現在，また 4 章を読んでいない．

## 感想

### Abstract Method と Hhok

本文中では Template Method Pattern の実現方法として抽象メソッドを具象クラスで実装する方式とフックするメソッドをオーバライドする方式の 2 種類を提示している．ただ，Temmplate Method Pattern の定義にもあるように Template Method Pattern の目的は「アルゴリズムの骨組みを定義」することにあると考える．

### Hollywood Principle について

ハリウッドの原則について以下のように補足されている (P.298).

> ハリウッドの原則を使うと，低水準コンポーネントがそれ自体をシステムにフックすることはできますが，高水準コンポーネントが低水準コンポーネントがいつどのように必要になるかについて判断します．

個人的には (確かに親クラスと読んだりはするが) 基底クラスを高水準コンポーネントと呼び，派生クラスを低水準コンポーネントの呼ぶのは，なんとなく抵抗がある (派生クラスのほうがレイヤが上ではないか)．  
// 確かに派生クラスが基底クラスに依存しているので，基底クラスが高水準コンポーネント (依存される側) で派生クラスが低水準コンポーネント (依存する側) である，と言っているというのはわかる．
