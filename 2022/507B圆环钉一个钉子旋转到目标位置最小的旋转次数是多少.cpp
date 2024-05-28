// LINK: https://codeforces.com/contest/507/problem/B
// NAME: 507B. Amr and Pins, Codeforces - Codeforces Round #287 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.11.08-11:50:03, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/* ------------------------------------------ */
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/* ------------------------------------------ */

double getDistance(double x, double y, double a, double b) {
   return sqrt(abs(a - x) * abs(a - x) + abs(b - y) * abs(b - y)); 
}

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int r = 0, x = 0, y = 0, a = 0, b = 0; 
   cin >> r >> x >> y >> a >> b; 
   
   double d = getDistance(x, y, a, b); 
   dbg(d); 
   int cnt = d / (r * 2); 
   if (cnt * (r * 2) < d) {
      cnt++; 
   }
   cout << cnt << '\n'; 
   
   return 0;
}


/*

507B圆环钉一个钉子旋转到目标位置最小的旋转次数是多少

*/