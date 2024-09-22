#!/bin/bash

# 颜色定义
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # 无色

# 获取当前日期和时间，格式为 YYYY_MM_DD--HH:MM:SS
time=$(date "+%Y_%m_%d--%H:%M:%S")
# 获取当前作者
author=$(git config user.name)

# 添加所有更改到暂存区
git add .

# 获取添加的文件数量和总行数
file_count=$(git diff --cached --name-only | wc -l)
line_count=$(git diff --cached | wc -l)

# 创建提交信息
commit_message="[$time] [Files: $file_count] [Lines: $line_count] [$author]"

# 提交更改
if git commit -m "$commit_message"; then
    echo -e "${GREEN}暂存成功: $commit_message${NC}"
else
    echo -e "${RED}暂存失败: ${NC}"
    exit 1
fi

# 推送更改到远程仓库
if git push; then
    echo -e "${GREEN}推送成功${NC}"
else
    echo -e "${RED}推送失败${NC}"
    exit 1
fi
