// LINK: https://codeforces.com/contest/118/problem/D
// NAME: 118D. Caesar's Legions, Codeforces - Codeforces Beta Round #89 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.12.09-22:02:49, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n1 = 0, n2 = 0, k1 = 0, k2 = 0;
   cin >> n1 >> n2 >> k1 >> k2;
   // n1: footmen, n2: horsemen
   // > k1 footmen, > k2 horsemen is not beautiful
   // find the number of beautiful arrangements
   
   const int mod = 1e8;
   
   
   return 0;
}

/*

118D排列步兵和骑兵的漂亮方案数量


设 f[i][j][0/1] 表示将 i 个步兵和 j 个骑兵排列
最后一个士兵是步兵 / 骑兵的方案数量

枚举 k 表示当前排列末尾存在几个连续相同种类的士兵
f[i][j][0] = f[i - k][j][1] (k == [1, max(k)])

TODO
*/