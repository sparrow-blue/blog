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

{{< readfile file="head_first_design_patterns/one_of_a_king_object/singleton.cpp" lang="cpp" is_open="true" >}}

## 感想

Singleton の是非についてはだいぶ意見が割れているような気がする．はたから見ている限り，仕組みが単純で導入しやすいため安易に使われてしまうが，他のパターンに比べてデメリットが明確であることが多いのがその所以のように思う．

この節 (おそらくこの書籍全体) を通して，正確さよりも分かりやすさを意識しているようで，しばしば (言いたいことはわかるが) 矛盾した記述が散見された．

例えば P.170 に以下の記載がある．

> Singleton パターンでは，オブジェクトは必要になったときに初めて作成できるのだ．

一方で P.174 には以下の記載がある．

> どの時点でもインスタンスが 1 つしか存在しないことを保証する，Singleton パターンに基づいています．

前者の「必要になるまでオブジェクトが作成 (インスタンス化の意と理解している) されない」に対して後者は「いついかなる時も (つまり必要か否かによらず) 1 つのインスタンスが存在する」と述べている．

(私の理解では) Singleton の本旨は後者が正しい．矛盾するかを厳密に詰めていけば使用する言語にもよってくるのだが，一般に矛盾していると解釈して差し支えないだろう．しかし Singleton Pattern を実装した結果，前者の性質を持つことが往々にしてあり，それ自体は知っていなければならないだろう．そうはいってもこの下りを厳密に説明することが本来の目的ではないのもわかる．このように必要な情報を (言葉を選ばずに言えば) 騙し騙し混ぜ込んでいるように感じた．
