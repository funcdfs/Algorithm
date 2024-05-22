/**
 * name: C. Arrow Path
 * link: https://codeforces.com/contest/1948/problem/C
 * time: 2024/5/20 15:14:29 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto solve(int _case) -> void {
    dbg(_case;
    
    int n = 0;
    string s1 ,s2;
    cin >> n >> s1 >> s2;

    auto check = [&]() -> bool {
        
    };

    if (check()) {
      cout << format("YES\n");
    } else {
      cout << format("NO\n");
    }
    
    return;
}

auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int TT = 0;
   cin >> TT;
   for (int _case = 1; _case <= TT; _case++) {
      solve(_case);
   }

   return 0;
}
/*
有一个网格，由 $2$ 行和 $n$ 列组成。这些行从上到下编号为从 $1$ 到 $2$
。这些列从左到右编号为 $1$ 到 $n$
。网格的每个单元格都包含一个指向左侧或右侧的箭头。没有箭头指向网格之外。

有一个机器人在单元格 $(1, 1)$ 中启动。每一秒，以下两个动作相继发生：

1. 首先，机器人向左、向右、向下或向上移动（**它不能尝试走出网格，也不能跳过移动**）；
2. 然后它沿着当前单元格（移动后最终到达的单元格）中放置的箭头移动。

您的任务是确定机器人是否可以到达单元格 $(2, n)$ 。
*/