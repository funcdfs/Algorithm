#!/bin/bash

# 检查参数数量
if [ "$#" -ne 1 ]; then
   echo -e "\033[0;31m用法: ./run.sh <cpp 源文件>\033[0m"
   exit 1
fi

# 设置彩色输出
RED='\033[0;31m'    # 红色
GREEN='\033[0;32m'  # 绿色
YELLOW='\033[0;33m' # 黄色
BLUE='\033[0;34m'   # 蓝色
NC='\033[0m'        # 无色（重置颜色）

# 编译选项
# 编译选项
CXX_FLAGS=(
   -std=c++2b                    # c++23
   -D LOCAL                      # dbg.h
   -Wno-string-compare           # dbg.h
   -Wno-deprecated-array-compare # dbg.h
   # -Wall # wall for common error
   # -Wextra # extra wall
   -O1                     # o^1
   -g                      # 生成调试信息
   -gline-tables-only      # 只提供行号调试信息
   -fno-omit-frame-pointer # 保留栈帧指针
   -fno-inline             # 禁止内联优化
   -Wformat=2              # string format error
   -Wfloat-equal           # float >=< error
   -Wconversion            # int64 -> int error
   -Wshift-overflow        # (l+r)>>1 error
   -Wcast-qual             # const -> !const
   -Wcast-align            # pointer cast
   #-fsanitize=address # 地址消毒器
   -fsanitize=undefined       # 未定义行为消毒器
   -fsanitize-recover=address # 允许继续运行（可选）
)

# 开始计时
START_TIME=$(date +%s)

# 生成可执行文件的名称
OUTPUT_FILE="./test"

# 编译命令
g++ "${CXX_FLAGS[@]}" "$1" -o "$OUTPUT_FILE"

# 检查编译是否成功
if [ $? -eq 0 ]; then
   END_TIME=$(date +%s)
   DIFF_TIME=$((END_TIME - START_TIME))
   echo -e "${GREEN}编译成功！${NC}"
   echo -e "${YELLOW}编译时间: ${DIFF_TIME} 秒${NC}"

   # 执行生成的可执行文件
   ./"$OUTPUT_FILE"
else
   echo -e "${RED}编译失败！请检查错误信息。${NC}"
fi

# 删除可执行文件（如果你希望保留可执行文件，可以注释掉这一行）
rm "$OUTPUT_FILE"
