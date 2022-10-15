// LINK: https://codeforces.com/contest/1526/problem/C1
// NAME: 1526C1. Potions (Easy Version), Codeforces - Codeforces Round #723 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.12-21:55:20, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   int n = 0; 
   cin >> n; 
   int64_t sum = 0; 
   priority_queue<int, vector<int>, greater<int>> drunks; 
   for (int i = 0; i < n; i++) {
      int a = 0; 
      cin >> a; 
      if (sum + a >= 0) {
         sum += a; 
         drunks.push(a);
      } else if (!drunks.empty() && drunks.top() < a) {
         sum -= drunks.top(); drunks.pop(); 
         sum += a; =】
         drunks.push(a); 
      }
   }
   cout << (int)drunks.size() << '\n';
   return 0;
}


/*

1526C1健康值为正数的情况下可以喝的最多的药水的数量


6
4 -4 1 -3 1 -3
遍历到 -3 的时候 如果再喝就会立马嗝屁，
   就要取出已经喝了的药水中，最小的那一个，
      进行比较，如果当前的比最小的还小，就不要了，扔掉
      如果当前的比最小的大，（消耗的健康值更少）就悔棋，然后将新的放入
*/