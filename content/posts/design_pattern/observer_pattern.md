---
date: "2023-06-16"
description: ""
draft: false
# expiryDate: ""
keywords: []
# lastmod: ""
# publishDate: "2023-06-13"
# slug: ""
# summary: ""
title : "Observer Pattern"
# type: ""
# url ""
# weight: 
tags: ["command_pattern", "design_pattern"]
categories: ["design"]
---

## このエントリの目指すところ

Observer Pattern は大きく以下の観点があると仮説をたて，それが妥当なのか，あるいは過不足があるのかを考える．

1. データモデルとそれに対する操作の参照関係を `1..*` を実現しつつ操作同士を疎結合に保つ
   - Subject が Model だとすると，そのモデルが保持する値の変更に伴って処理を担う ViewModel や Controller が呼ばれなければならない．しかし Model のある値が変化したからといって，Model 自身はどんな処理をすべきかは知らない (知るべきではない)．
   - したがって Model は「値が変化した」という事実を外部に公開し，それをトリガとして操作を受け付ける必要がある．これを実現する典型的な実装が Callback の登録である．

例にもれず実装はする．

## 調査

### 語られる像

### 整理

### 疑問

## 要点

## 実例

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
$ scons --version
SCons by Steven Knight et al.:
        SCons: v4.0.1.c289977f8b34786ab6c334311e232886da7e8df1, 2020-07-17 01:50:03, by bdbaddog on ProDog2020
        SCons path: ['/usr/lib/python3/dist-packages/SCons']
Copyright (c) 2001 - 2020 The SCons Foundation
```

### 実装

関連するファイル数が多いため，重要と思われるファイルをデフォルトで展開するようにした．

{{< readfile file="design_pattern/observer_pattern.cpp" lang="cpp" is_open="true" >}}
{{< readfile file="design_pattern/observer_pattern/observer_pattern.hpp" lang="cpp" >}}
{{< readfile file="design_pattern/observer_pattern/Display.hpp" lang="cpp" >}}
{{< readfile file="design_pattern/observer_pattern/Observable.hpp" lang="cpp" is_open="true" >}}
{{< readfile file="design_pattern/observer_pattern/ObservableDiagram.hpp" lang="cpp" >}}
{{< readfile file="design_pattern/observer_pattern/ObservableLine.hpp" lang="cpp" >}}
{{< readfile file="design_pattern/observer_pattern/ObservableTriangle.hpp" lang="cpp" >}}
{{< readfile file="design_pattern/observer_pattern/Observer.hpp" lang="cpp" is_open="true" >}}
{{< readfile file="design_pattern/component/Canvas.hpp" lang="cpp" >}}
{{< readfile file="design_pattern/component/Diagram.hpp" lang="cpp" >}}
{{< readfile file="design_pattern/component/Line.hpp" lang="cpp" >}}
{{< readfile file="design_pattern/component/Triangle.hpp" lang="cpp" >}}
{{< readfile file="demangle.hpp" lang="cpp" >}}
{{< readfile file="join.hpp" lang="cpp" >}}

### 実行結果

```
$ ./content/build/design_pattern/observer_pattern
design_pattern::component::Line (100,100)
design_pattern::component::Line (0,0)
design_pattern::component::Line (101,101)
design_pattern::component::Triangle (100,100)
design_pattern::component::Triangle (0,0)
design_pattern::component::Triangle (101,101)
```
