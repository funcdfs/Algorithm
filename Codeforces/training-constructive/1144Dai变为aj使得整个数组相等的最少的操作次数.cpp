// LINK: https://codeforces.com/contest/1144/problem/D
// NAME: 1144D. Equalize Them All, Codeforces - Codeforces Round #550 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.10.01-11:23:36, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL // g++ -D -LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<int> a(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   
   unordered_map<int, int> hs; 
   for (int i = 0; i < n; i++) hs[a[i]]++; 
   
   int maxCnt = 0, maxCntValue = 0; 
   for (auto& [k, v] : hs) {
      if (v > maxCnt) {
         maxCnt = v; 
         maxCntValue = k; 
      }
   }
   cout << n - maxCnt << '\n'; 
   int pos = find(a.begin(), a.end(), maxCntValue) - a.begin(); 
   for (int i = pos - 1; i >= 0; i--) {
      cout << 1 + (a[i] > a[i + 1]) << ' ' << i + 1 << ' ' << i + 2 << ' ' << '\n'; 
      a[i] = a[i + 1]; 
   }
   // 把第一个位置 pos 之前的所有的数字都变为和正统军
   
   for (int i = pos; i < n - 1; i++) {
      if (a[i + 1] != maxCntValue) {
         assert(a[i] == maxCntValue); 
         cout << 1 + (a[i + 1] > a[i]) << ' ' << i + 2 << ' ' << i + 1 << ' ' << '\n'; 
         a[i + 1] = a[i]; 
      }
   }
   // 把后面位置的所有不同的数字也都变为 maxCntValue
   
   return 0;
}


/*
1144Dai变为aj使得整个数组相等的最少的操作次数


1: ai = ai + |ai - aj|
2: ai = ai - |ai - aj|

如果 ai 大于 aj 则操作 2 可以使得 ai 变为 aj 
如果 ai 小于 aj 则操作 1 可以使得 ai 变为 aj 



*/