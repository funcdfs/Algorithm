// LINK: https://codeforces.com/contest/1316/problem/B
// NAME: 1316B. String Modification, Codeforces - CodeCraft-20 (Div. 2)
// DATE: 2022.09.27 23:01:18, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
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
      string s = string(n, ' ');
      cin >> s;
      auto ans = make_pair(s, 1);
      for (int i = 2; i <= n; i += 1) {
         string t = s.substr(0, i - 1);
         if ((n - i) % 2 == 0) reverse(t.begin(), t.end());

         t = s.substr(i - 1) + t;
         ans = min(ans, make_pair(t, i));
      }
      cout << ans.first << "\n" << ans.second << "\n";
   }

   return 0;
}

/*

1316B旋转所有k长度的子串使得字典序最小找最小的k


经过第 i 次旋转之后，结果中的 prefix 就是 sk, sk+1, sk+2, sk+i-1
由于要反转的子串的数量是 n - k + 1
所以最终的 answer string prefix 就会是 sk, sk+1, sk+2, ..., sk+(n-k+1)-1


而这个 prefix 就正好是 origin s 的 suffix sk...sn


前半部分和 k 的 value 已经确定了，但是 answer 的 suffix string 是什么？
   可以观察到如果 n and k have the same parity, the suffix string is s0,sk
   otherwise, the suffix string is reversed(s0, sk);
*/