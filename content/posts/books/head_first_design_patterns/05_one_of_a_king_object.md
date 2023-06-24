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

h_title: "Singleton Pattern の定義"
h_define: "Singleton Pattern の定義"
h_threadsafe: "Thread-safe な実装"
h_report: "感想"
---

## {{< param h_title>}}

インスタンスを 1 つしか必要としないオブジェクトは存在し，そのケースで複数のインスタンスを生成すると問題になるケースが存在する．

- Thread pool
- Cache
- Dialogbox
- Logger
- etc.

Singleton Pattern はインスタンスを 1 つだけ生成する仕組みである．

典型的にはコンストラクタを非公開，つまり private にすることで (外部から) 生成を禁ずる．

{{< readfile file="head_first_design_patterns/one_of_a_king_object/singleton.cpp" lang="cpp" is_open="true" >}}


### {{< param h_define >}}

本書において Singleton Pattern を以下のように定義されている (P.177)．

> Singleton パターンは，クラスがインスタンスを 1 つしか持たないことを保証し，そのインスタンスにアクセスするグローバルポイントを提供する．

書籍内には「グローバル」という言葉に対する定義は記述されていないが，ここでいうグローバルは「あるプロセスの中」と解釈して差し支えないとは思うが必ずしもプロセスである必要はないだろう．  
// 極端なことをいえば Singleton Pattern の概念自体は現実世界に拡張できるだろう．

一方で現実的には，そのオブジェクトの定義およびインスタンスにアクセスしうる範囲をグローバル呼ぶものと想像する．前者は生成の可否，後者は複製の可否に影響する．例えば C# において `internal class Singleton {}` のような形で定義されるとき，ここでいうグローバルはプロセスとは一致しない Singleton Pattern のクラスが定義されるだろう．

### {{< param h_threadsafe >}}

本書でも指摘されているが `GetInstance()` が Thread-unsafe なため Multi-thread Programming の文脈ではインスタンスが単一であることを保証できない．

この問題に対する解決策を述べる．

1. `GetInsntance()` への同時アクセスを許容しない  
    - 言語によって実装は異なるが本書では Java を扱っているので synchronized 修飾子を例に挙げている  
    - C++ では `std::mutex` で排他処理を行うことになるだろう
    - 同期処理はパフォーマンスへの影響が大きくなるため，頻繁に呼ばれるような処理ではなるべく避けたい
1. 遅延インスタンス生成から先行インスタンス生成に変える
    - 書籍中では `GetInstance()` が呼ばれたタイミングでインスタンス化される (遅延インスタンス生成) が Singleton Pattern のメリットであるかのように述べられている (詳細については[{{< param h_report >}}](#{{< param h_report >}})で述べる) が，実際は生成するタイミング自体は Singleton Pattern の関知する所ではない ([Singleton Pattern の定義](#Singleton Pattern の定義) を参照)，
    - 端的にいえば `GetInstance()` を呼ばれたタイミングではなく (static 初期化子などで) クラスがロードされたタイミングで初期化してしまえばよい．


### {{< param h_report >}}

Singleton の是非についてはだいぶ意見が割れているような気がする．はたから見ている限り，仕組みが単純で導入しやすいため安易に使われてしまうが，他のパターンに比べてデメリットが明確であることが多いのがその所以のように思う．

この節 (おそらくこの書籍全体) を通して，正確さよりも分かりやすさを意識しているようで，しばしば (言いたいことはわかるが) 矛盾した記述が散見された．

例えば P.170 に以下の記載がある．

> Singleton パターンでは，オブジェクトは必要になったときに初めて作成できるのだ．

一方で P.174 には以下の記載がある．

> どの時点でもインスタンスが 1 つしか存在しないことを保証する，Singleton パターンに基づいています．

前者の「必要になるまでオブジェクトが作成 (インスタンス化の意と理解している) されない」に対して後者は「いついかなる時も (つまり必要か否かによらず) 1 つのインスタンスが存在する」と述べている．

(私の理解では) Singleton の本旨は後者が正しい．矛盾するかを厳密に詰めていけば使用する言語にもよってくるのだが，一般に矛盾していると解釈して差し支えないだろう．しかし Singleton Pattern を実装した結果，前者の性質を持つことが往々にしてあり，それ自体は知っていなければならないだろう．そうはいってもこの下りを厳密に説明することが本来の目的ではないのもわかる．このように必要な情報を (言葉を選ばずに言えば) 騙し騙し混ぜ込んでいるように感じた．
