---
date: "2023-06-13"
description: ""
draft: false
# expiryDate: ""
keywords: []
# lastmod: ""
# publishDate: "2023-06-13"
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

Command Pattern の要点は大きく以下 2 つであると考える．

1. 一連の処理をオブジェクトに隠蔽できる
2. 処理の定義とその実行をそれぞれ別の責務として扱える

この結果，Command を実行する責務を負う Invoker で Execute したという事実が保持でき，条件さえそろえば実行履歴やその順序を保持できる．実行の順序が保持できていれば工夫次第で Redo/Undo も実現できる．

一連の処理をオブジェクトにすることを目的と据えるのであれば Redu/Undo は結果的に導かれるだけであって，例えば非同期に実行するタスクを積む一種の Producer-Consumer Pattern のベースとも考えられる．

## 実例

キャンバスに図形を描くプログラムを考える．Canvas に対して Line や Triangle などの図形を配置する Command，図形を Move したり Resize したりする Command も定義し，これらの実行履歴を保持する Invoker を定義する．

### 設計

### 環境

```
$ cat /etc/os-release 
PRETTY_NAME="Ubuntu 22.04.2 LTS"
NAME="Ubuntu"
VERSION_ID="22.04"
VERSION="22.04.2 LTS (Jammy Jellyfish)"
VERSION_CODENAME=jammy
ID=ubuntu
ID_LIKE=debian
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
UBUNTU_CODENAME=jammy
$ clang++ --version
Ubuntu clang version 14.0.0-1ubuntu1
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```

### 実装

{{< readfile file="src/command_pattern.cpp" lang="cpp" is_open="false" >}}
{{< readfile file="src/command_pattern.hpp" lang="cpp" >}}
{{< readfile file="src/demangle.hpp" lang="cpp" >}}
{{< readfile file="src/join.hpp" lang="cpp" >}}

### 実行結果

```
$ date; clang++ src/command_pattern.cpp  -o command_pattern.out && ./command_pattern.out
Thu Jun 15 01:50:06 JST 2023
# state
## canvas
empty
## executer
empty
# add diagrams
# state
## canvas
x: 0, y: 0 - design_pattern::command_pattern::Line (0,5)
x: 0, y: 0 - design_pattern::command_pattern::Triangle (5,10)
## executer
0: design_pattern::command_pattern::CreateLineDiagramCommand
1: design_pattern::command_pattern::CreateTriangleDiagramCommand
# operate diagrams
# state
## canvas
x: 100, y: 500 - design_pattern::command_pattern::Line (0,200)
x: 250, y: 50 - design_pattern::command_pattern::Triangle (5,10)
## executer
0: design_pattern::command_pattern::CreateLineDiagramCommand
1: design_pattern::command_pattern::CreateTriangleDiagramCommand
2: design_pattern::command_pattern::ResizeDiagramCommand
3: design_pattern::command_pattern::MoveDiagramCommand
4: design_pattern::command_pattern::MoveDiagramCommand
```
