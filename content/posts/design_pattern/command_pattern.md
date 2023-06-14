---
date: "2023-06-13"
description: ""
draft: false
# expiryDate: ""
keywords: []
# lastmod: ""
# publishDate: 1970-01-01
# slug: ""
# summary: ""
title : "Command Pattern"
# type: ""
# url ""
# weight: 
tags: ["command_pattern", "design_pattern"]
categories: ["design"]
---

## このエントリの目指すところ

以下の観点で調査/検討する．
1. どのようなシーンで使えるのか
1. なぜそのシーンで使えるのか

必要に応じてプログラムに起こす．

## 調査

### 語られる像

- [Wikipedia - Command パターン](https://ja.wikipedia.org/wiki/Command_%E3%83%91%E3%82%BF%E3%83%BC%E3%83%B3)
    > リクエストのために必要な手続きとデータをCommandオブジェクトとしてカプセル化した上で取り回し[1]、必要に応じてExecute（実行）するパターンである。オブジェクトであることを生かして命令のキューイングやロギング、Undo等が可能になり[2]、Executeを分離したことで手続きと実行を疎結合にできる。 
- [TECHSCORE - 22. Commandパターン](https://www.techscore.com/tech/DesignPattern/Command)
    > あるオブジェクトに対して要求を送るということは、そのオブジェクトのメソッドを呼び出すことと同じです。 そして、メソッドにどのような引数を渡すか、ということによって要求の内容は表現されます。さまざまな要求を送ろうとすると、引数の数や種類を増やさなければなりませんが、 それには限界があります。そこで要求自体をオブジェクトにしてしまい、そのオブジェクトを引数に渡すようにします。それがCommandパターンです。
- [フロントエンドのデザインパターン - コマンドパターン](https://zenn.dev/morinokami/books/learning-patterns-1/viewer/command-pattern)
    > コマンドパターン (command pattern) を用いると、あるタスクを実行するオブジェクトと、そのメソッドを呼び出すオブジェクトを切り離すことができことができます。
- [IT専科 - Command パターン](https://www.itsenka.com/contents/development/designpattern/command.html)
    > 「Command」という英単語は、「命令」を意味します。
    > このパターンでは、1つもしくは複数の命令を1つのオブジェクトで表現(命令の詳細処理をカプセル化)します。また、命令をオブジェクトとして管理するため、その命令の履歴管理、UNDO(取消し)機能の実装等が容易に行えます。

### 整理

1. Command Pattern の典型的な用例として Undo/Redo が挙げられる
1. 手続き一式を隠ぺいし，オブジェクトとして取り扱えるようにする
1. 手続きがオブジェクトとして扱われることで，キューイングや呼び出し履歴の記録が可能になる
1. ある手続きを定義したとして，それを実行する責務と分離される

### 疑問

1. Redo はともかく Undo をどのように実現するのか
   - Command に対する入力と出力を保持しておくということか

## 要点

## 検討

### どのようなシーンで使えるのか

### なぜそのシーンで使えるのか

## 実例

### 設計

### 環境

```
$ clang++ --version
Ubuntu clang version 14.0.0-1ubuntu1
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```

### 実装

{{< readfile file="src/command_pattern.cpp" lang="cpp" >}}
{{< readfile file="src/command_pattern.hpp" lang="cpp" >}}
{{< readfile file="src/demangle.hpp" lang="cpp" >}}

### 実行結果

```
$ clang++ ./src/command_pattern.cpp  -o command_pattern.out && ./command_pattern.out 
# initial state
# final state
design_pattern::command_pattern::Triangle: (5,10)
design_pattern::command_pattern::Line: (0,10)
# history
0: design_pattern::command_pattern::CreateLineDiagramCommand
1: design_pattern::command_pattern::CreateTriangleDiagramCommand
```
