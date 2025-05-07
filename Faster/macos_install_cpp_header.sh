#!/bin/bash

set -e

GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

echo -e "${GREEN}🔧 开始安装 C++ 调试头文件和万能头文件...${RESET}"

# 1. 设置目标路径
BITS_DIR="/usr/local/include/bits"
ALGO_DIR="/usr/local/include/algo"
STDCPP_FILE="$BITS_DIR/stdc++.h"
DBG_FILE="$ALGO_DIR/dbg.h"

# 2. GitHub 原始文件链接
STDCPP_URL="https://raw.githubusercontent.com/funcdfs/Algorithm/main/Faster/maccopy/bits/std.h"
DBG_URL="https://raw.githubusercontent.com/funcdfs/Algorithm/main/Faster/maccopy/algo/dbg.h"

# 3. 创建目录
echo "📁 创建目录..."
sudo mkdir -p "$BITS_DIR"
sudo mkdir -p "$ALGO_DIR"

# 4. 下载头文件
echo "⬇️ 下载 bits/stdc++.h ..."
sudo curl -fsSL "$STDCPP_URL" -o "$STDCPP_FILE"

echo "⬇️ 下载 algo/dbg.h ..."
sudo curl -fsSL "$DBG_URL" -o "$DBG_FILE"

# 5. 检查内容是否成功获取
echo "🔍 验证文件内容："

if [[ -s "$STDCPP_FILE" && -s "$DBG_FILE" ]]; then
    echo -e "${GREEN}✅ bits/stdc++.h 内容预览：${RESET}"
    head -n 5 "$STDCPP_FILE"

    echo -e "${GREEN}✅ algo/dbg.h 内容预览：${RESET}"
    head -n 5 "$DBG_FILE"

    echo -e "\n${GREEN}✅ 安装完成！你现在可以使用：${RESET}"
    echo '#include <bits/stdc++.h>     // 万能头文件'
    echo '#include <algo/dbg.h>        // 调试专用头文件'
else
    echo -e "${RED}❌ 下载失败，可能是网络或路径问题。${RESET}"
    exit 1
fi
