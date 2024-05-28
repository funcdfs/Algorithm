// LINK: https://codeforces.com/contest/1697/problem/C
// NAME: 1697C. awoo's Favorite Problem, Codeforces - Educational Codeforces
// Round 130 (Rated for Div. 2) DATE: 2022.09.28 00:21:15, LIMIT: 256 MB, 2000
// ms

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
      string s = string(n, ' ');
      string t = string(n, ' ');
      cin >> s >> t;

      function<bool()> solve = [&]() -> bool {
         for (auto& c : {'a', 'b', 'c'}) {
            if (count(s.begin(), s.end(), c) != count(t.begin(), t.end(), c)) {
               return false;
            }
         }
         string s1, t1;
         vector<int> a, b;
         for (int i = 0; i < n; i++) {
            if (s[i] != 'b') {
               s1 += s[i];
               a.push_back(i);
            }
         }
         for (int i = 0; i < n; i++) {
            if (t[i] != 'b') {
               t1 += t[i];
               b.push_back(i);
            }
         }
         if (s1 != t1) {
            return false;
         }

         for (int i = 0; i < (int)a.size(); i++) {
            if (s1[i] == 'a' ? (a[i] > b[i]) : (a[i] < b[i])) {
               // s1[i] == 'a' 的时候，s1 中的 a 要在 t1 中的 a 的前面
               // s1[i] == 'c' 的时候, s1 中的 c 要在 t1 中的 c 的后面
               return false;
            }
         }

         return true;
      };

      if (solve()) {
         cout << "YES\n";
      } else {
         cout << "NO\n";
      }
   }

   return 0;
}

/*

1697Cs中的ab替换为baT中的bc替换为cb

change s to make it equal to string t

ab 可以转换为 ba，bc 可以转换为 cb 所以 a 只可以向后移动，c 只可以向前移动
对于每一次调换，只调换 a b 的前后位置， b c 的前后位置， 但是并不调换 a c
的前后位置

如果 s 可以调换为 t
那么，不论如何调换都无法改变 a c 的前后位置的关系
   所以把 s 和 t 中的 b 全部删掉
      则 s == t

由于在调换的过程中 a 只能向后移动，c 只能向前移动
   所以在 t 中，相同的 a 一定在 s 中原来的地方或者后面，相同的 c 一定在 s
中原来的地方或者前面 其余的情况就不可以换成 t
*/