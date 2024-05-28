// LINK: https://codeforces.com/contest/1486/problem/B
// NAME: 1486B. Eastern Exhibition, Codeforces - Codeforces Round #703 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.15-18:19:00, 1000 ms
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      int n = 0; 
      cin >> n; 
      vector<int> x(n, 0), y(n, 0); 
      for (int i = 0; i < n; i++) cin >> x[i] >> y[i]; 
      
      if (n % 2 == 1) {
         cout << 1 << '\n'; 
      } else {
         sort(x.begin(), x.end()); 
         sort(y.begin(), y.end()); 
         int64_t A = x[n / 2] - x[n / 2 - 1] + 1; 
         int64_t B = y[n / 2] - y[n / 2 - 1] + 1; 
         cout << A * B << '\n'; 
      }
   }

   return 0;
}


/*

1486B二维找到一个点到达其他所有点的曼哈顿距离总和最小


求共有多少个满足该要求的点
曼哈顿距离：x 和 y 的坐标差距之和

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20221015220943.png)
*/