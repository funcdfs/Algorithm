/**
 * name: A. Balance the Bits
 * link: https://codeforces.com/contest/1503/problem/A
 * time: 2024/5/22 23:18:53 https://github.com/funcdfs
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
   
   int n =0;
   string s;
   cin >> s;

   // 构造两个合法的括号序列，使得这两个括号序列第 i 个字符相同
   // 当且仅当 a[i] == 1 


   // n = 2*1e5
   // 不能暴搜

   auto check = [&]() -> bool {
      
   };

   if (check() == false) {
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

*/