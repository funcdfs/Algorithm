#!/bin/bash

# Script optimized by GPT.

# 获取当前日期和时间，格式为 YYYYMMDD-HH:MM:SS
time=$(date "+%Y%m%d-%H:%M:%S")

# 获取当前作者和分支名称
author=$(git config user.name)
branch=$(git rev-parse --abbrev-ref HEAD)

# 创建提交信息，包含时间戳、作者和分支信息
commit_message="[$time] [$author] [Branch: $branch]"

# 添加所有更改到暂存区
git add .

# 提交更改，使用生成的提交信息
if git commit -m "$commit_message"; then
    echo "提交成功：$commit_message"
else
    echo "提交失败"
    exit 1
fi

# 推送更改到远程仓库
if git push; then
    echo "推送成功"
else
    echo "推送失败"
    exit 1
fi
