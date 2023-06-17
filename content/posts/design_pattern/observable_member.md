---
date: "2023-06-17"
description: ""
draft: false
# expiryDate: ""
keywords: []
# lastmod: ""
# publishDate: "2023-06-13"
# slug: ""
# summary: ""
title : "Observable Method"
# type: ""
# url ""
# weight: 
tags: ["design_pattern"]
categories: ["design"]
---

## このエントリの目指すところ

C# ライクなイベントハンドリングを実装する．パターンの名称がわからないので，とりあえず Observable Method という名称で記載する．

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

{{< readfile file="design_pattern/observable_method/EventHandler.hpp" lang="cpp" >}}

### 実行結果
