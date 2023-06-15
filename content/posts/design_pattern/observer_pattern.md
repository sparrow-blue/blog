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
```

### 実装

{{< readfile file="src/observer_pattern.cpp" lang="cpp" is_open="false" >}}
{{< readfile file="src/observer_pattern.hpp" lang="cpp" >}}
{{< readfile file="src/join.hpp.hpp" lang="cpp" >}}

Command Pattern のコードを流用している．そちらの詳細は当該記事を別途確認のこと．

### 実行結果

```
$ date; clang++ src/observer_pattern.cpp -o observer_pattern.out && ./observer_pattern.out 
Fri Jun 16 04:14:40 JST 2023
design_pattern::observer_pattern::Line (0,100)
design_pattern::observer_pattern::Line (0,0)
design_pattern::observer_pattern::Line (0,101)
```

