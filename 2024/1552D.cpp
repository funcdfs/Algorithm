/**
 * name: D. Array Differentiation
 * link: https://codeforces.com/contest/1552/problem/D
 * time: 2024/5/20 16:53:47 https://github.com/funcdfs
 **/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif



auto solve(int _case) -> void {
   dbg(_case);
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];
   
   auto check = [&]() -> bool {
      
   };

   if (check() == true) {
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
您将获得一个 $n$ 整数序列 $a_1, \, a_2, \, \dots, \, a_n$ 。

是否存在满足以下属性的 $n$ 整数 $b_1, \, b_2, \, \dots, \, b_n$ 序列？

- 对于每个 $1 \le i \le n$ ，存在两个（不一定不同）索引 $j$ 和 $k$ ( $1 \le j, \, k \le n$ )，使得 $a_i = b_j - b_k$ 。
*/