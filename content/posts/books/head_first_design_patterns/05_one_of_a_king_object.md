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
title : "唯一のオブジェクト / One of a king object"
# type: ""
# url ""
# weight: 
tags: ["Design Pattern", "Head First Design Patterns", "Singleton"]
categories: ["book", "design"]
---

## Singleton Pattern

インスタンスを 1 つしか必要としないオブジェクトは存在し，そのケースで複数のインスタンスを生成すると問題になるケースが存在する．

- Thread pool
- Cache
- Dialogbox
- Logger
- etc.

Singleton Pattern はインスタンスを 1 つだけ生成する仕組みである．

典型的にはコンストラクタを非公開，つまり private にすることで (外部から) 生成を禁ずる．

{{< readfile file="head_first_design_patterns/one_of_a_king_object/singleton.cpp" lang="cpp" >}}

```cpp
class Hoge
