// LINK: https://codeforces.com/contest/1373/problem/D
// NAME: 1373D. Maximum Sum on Even Positions, Codeforces - Educational Codeforces Round
// 90 (Rated for Div. 2) CODE: https://github.com/fengwei2002, 2022.10.21-21:38:02, 2000ms

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
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) cin >> a[i];

      int64_t ans = 0;
      for (int i = 0; i < n; i++) {
         if (!(i & 1)) {
            ans += a[i];
         }
      }  // 统计偶数位的和
      int64_t t = 0;
      { // 从偶数下标开始反转的总和
         int64_t sum = 0;
         int64_t ans = 0;
         vector<int> x;
         for (int i = 1; i < n; i += 2) {
            x.push_back(a[i] - a[i - 1]); // 奇数变为偶数 a[i] - a[i - 1]
         }
         for (int i = 0; i < (int)x.size(); i++) {
            sum += x[i];
            if (sum < 0) { // 拖后腿的部分 不要了
               sum = 0;
            }
            ans = max(ans, sum);
         }
         t = ans;
      }
      { // 从奇数下标开始反转的总和
         int64_t sum = 0;
         int64_t ans = 0;
         vector<int> x;
         for (int i = 2; i < n; i += 2) {
            x.push_back(a[i - 1] - a[i]); // 奇数变为偶数，a[i - 1] - a[i]
         }
         for (int i = 0; i < (int)x.size(); i++) {
            sum += x[i];
            if (sum < 0) { // 拖后腿的部分也不要了
               sum = 0;
            }
            ans = max(ans, sum);
         }
         t = max(t, ans); 
      }
      // 最后的值就是 
      // 原本的偶数位置上面的和，加上从奇数下标或者偶数下标开始反转可以得到的最大的反转变化值
      cout << ans + t << '\n'; 
   }

   return 0;
}

/*

1373D反转一个区间使得反转之后的序列偶数项的总和最大

也就是求最大子段和

扫描其实是一个贪心。
如果发现某一个点的前缀和变成负数了，那么明显不能要前面这个区间，否则会拉低后面的区间。
所以，得出以下做法：累加前缀和，每累加一个就比 max，如果累加成负数了就清零。
*/