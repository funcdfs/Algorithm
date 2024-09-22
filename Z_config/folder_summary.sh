#!/bin/bash

echo "File Count by Type: \n" > README.md

# 统计每种文件类型的数量和行数
find . -type f ! -name "*.DS_Store" ! -name "*clang-format*" | sed -E 's/.*\.([^.]*)/\1/' | sort | uniq | while read ext; do
    count=$(find . -type f -name "*.$ext" ! -name "*.DS_Store" ! -name "*clang-format*" | wc -l)
    lines=$(find . -type f -name "*.$ext" ! -name "*.DS_Store" ! -name "*clang-format*" -exec wc -l {} + | awk '{total += $1} END {print total}')
    echo "$ext: $count files, $lines lines   \n" >> README.md
done
