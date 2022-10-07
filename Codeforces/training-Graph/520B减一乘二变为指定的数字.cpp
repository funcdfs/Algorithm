// LINK: https://codeforces.com/contest/520/problem/B
// NAME: 520B. Two Buttons, Codeforces - Codeforces Round #295 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.04-22:10:19, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, m = 0; 
   cin >> n >> m; 
   
   vector<int> d(1e5 + 10, 1e9); 
   d[n] = 0; 
   queue<int> que; 
   que.push(n); 
   while (que.size()) {
      auto t = que.front(); 
      que.pop(); 
      vector<int> a(0, 0); 
      if (t > 1) {
         a.push_back(t - 1); 
      } 
      if (t <= m) {
         a.push_back(t * 2); 
      }
      for (auto& x : a) {
         if (d[x] > d[t] + 1) {
            d[x] = d[t] + 1; 
            que.push(x); 
         }
      }
   }
   cout << d[m] << '\n'; 

   return 0;
}


/*

520B减一乘二变为指定的数字

*/