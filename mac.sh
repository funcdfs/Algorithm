#!/bin/bash

# 检查参数数量
if [ "$#" -ne 1 ]; then
   echo -e "\033[0;31mUsage: ./run.sh <*.cpp source file path>\033[0m"
   exit 1
fi

# 设置彩色输出
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# 编译选项
CXX_FLAGS=(
   -O2                          # 优化等级
   -Wall                        # 常见错误警告
   -Wextra                      # 额外的警告信息
   -std=c++2b                   # C++ 标准
   -pedantic                    # 严格语法检查
   -Wshadow                     # 变量名隐藏警告
   -Wformat=2                   # 字符串格式检查
   -Wfloat-equal                # 浮点比较警告
   -Wconversion                 # 隐式转换警告
   -Wcast-qual                  # const 属性丢失警告
   -Wcast-align                 # 指针对齐警告
   -D_GLIBCXX_DEBUG             # 启用调试模式
   -D LOCAL                      # 本地宏定义
)

# 开始计时
START_TIME=$(date +%s)

# 生成可执行文件的名称
SOURCE_FILE="$1"
FILE_DIR=$(dirname "$SOURCE_FILE")
FILE_BASENAME=$(basename "$SOURCE_FILE" .cpp)
OUTPUT_FILE="${FILE_DIR}/${FILE_BASENAME}.out"

# 编译命令
cd "$FILE_DIR" && clang++ "${CXX_FLAGS[@]}" "$SOURCE_FILE" -o "$OUTPUT_FILE"

# 检查编译是否成功
if [ $? -eq 0 ]; then
   END_TIME=$(date +%s)
   DIFF_TIME=$((END_TIME - START_TIME))
   echo -e "${GREEN}Compilation completed successfully!${YELLOW} Time taken: ${DIFF_TIME}s ${NC}"
   # 执行生成的可执行文件
   ./"$OUTPUT_FILE"
   # 删除可执行文件（如果需要保留，注释掉以下行）
   rm "$OUTPUT_FILE"
else
   echo -e "${RED}Compilation failed. Please review the error details.${NC}"
fi

