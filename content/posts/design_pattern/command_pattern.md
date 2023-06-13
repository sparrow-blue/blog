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
2. なぜそのシーンで使えるのか

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

## 検討

### どのようなシーンで使えるのか

### なぜそのシーンで使えるのか

## 実例

### 設計

### 実装
