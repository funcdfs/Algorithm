// LINK: https://codeforces.com/contest/550/problem/C
// NAME: 550C. Divisibility by Eight, Codeforces - Codeforces Round #306 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.07-11:47:10, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   string s = "";
   cin >> s;
   int n = (int)s.size();
   if (count(s.begin(), s.end(), '0') > 0) {
      cout << "YES\n";
      cout << 0 << '\n';
      return 0;
   }
   vector f(n, vector<bool>(8, false));
   vector prev(n, vector<int>(8, -1));
   f[0][(s[0] - '0') % 8] = true;
   for (int i = 1; i < n; i++) {
      f[i][(s[i] - '0') % 8] = true;
      for (int j = 0; j < 8; j++) {
         if (f[i - 1][j]) {
            f[i][(j * 10 + s[i] - '0') % 8] = true;
            prev[i][(j * 10 + s[i] - '0') % 8] = j;

            f[i][j] = true;
            prev[i][j] = j;  // 存储每一个状态的 余数来源本体
         }
      }
   }
   for (int i = 0; i < n; i++) {
      if (f[i][0]) {
         string ans = "";
         int curI = i, curJ = 0;
         while (true) {
            if (prev[curI][curJ] == -1 || prev[curI][curJ] != curJ) {
               ans.append(1, s[curI]);
            }
            if (prev[curI][curJ] == -1) break;
            curJ = prev[curI][curJ];
            curI--;
         }

         cout << "YES\n";
         reverse(ans.begin(), ans.end());
         cout << ans << '\n';
         return 0;
      }
   }

   cout << "NO\n";

   return 0;
}

/*

550C删除数字中的一些数位使得最终的结果可以整除8


首先 1000 可以整除八
所以所有的四位数取值以及更加大的取值都无所谓

8 的整除特征：如果末尾的三位是 8 的倍数，则整个数字就是 8 的倍数

然后暴力枚举


使用 DP
f[i][j] 表示可以从长度为 i 的前缀中删除一些数字，使得剩余的数字 % 8 == j 的所有集合
集合中存在元素 value 就是 true 否则就是 false

状态来源：
f[i][ai mod 8] = true
   for all j in 1 \to 8:
      f[i - 1][j] = true
      f[i][(j * 10 + a[i]) mod 8] = true

如果某一个位置的 f[i][0] == true 答案就是 YES
因为还要存储具体的路径，所以要构造一个 prev[i][j]

O(8*n)
*/