// LINK: https://codeforces.com/contest/489/problem/C
// NAME: 489C. Given Length and Sum of Digits..., Codeforces - Codeforces Round #277.5 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.01-16:16:33, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int m = 0, s = 0; 
   cin >> m >> s; 
   string b = ""; 
   if (s == 0) {
      cout << (m == 1 ? "0 0\n" : "-1 -1\n"); 
      return 0; 
   }
   int t = 0; 
   for (int i = 0; i < m; i++) {
      t = min(s, 9); 
      b += t + '0'; 
      s -= t; 
   }
   if (s > 0) {
      cout << "-1 -1" << '\n'; 
      return 0; 
   }
   string a(b.rbegin(), b.rend()); 
   int k = 0; 
   while (a[k] == '0') k++; 
   a[k]--, a[0]++; 
   cout << a << ' ' << b << '\n'; 
   
   return 0;
}

/*

489C数位长度为m数位和为s的最大值和最小值



*/