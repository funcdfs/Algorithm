// LINK: https://codeforces.com/contest/1618/problem/A
// NAME: 1618A. Polycarp and Sums of Subsequences, Codeforces - Codeforces Round #760 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.06-15:09:24, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      vector<int> b(7, 0); 
      for (int i = 0; i < 7; i++) cin >> b[i]; 
      cout << b[0] << ' ' << b[1] << ' ' << b[6] - b[1] - b[0] << '\n'; 
   }
   
   return 0;
}

/*

1618Arestorearraya

根据 7 个数字的结果，找出得到子集排列的 长度为 3 的原数组具体是多少

x, y, z

x,
y
z
x + y
x + z
y + z
x + y + z = maxValue


*/