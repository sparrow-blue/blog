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
