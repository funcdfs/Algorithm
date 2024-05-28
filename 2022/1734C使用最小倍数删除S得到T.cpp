#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      string t = "";
      cin >> t;
      int64_t ans = 0;
      vector<bool> vis(n, 0);
      for (int i = 1; i <= n; i++) {
         for (int j = i; j <= n && t[j - 1] == '0'; j += i) {
            if (vis[j - 1] == false) {
               vis[j - 1] = true;
               ans += i;
            }
         }
      }
      cout << ans << '\n';
   }

   return 0;
}

/*

1734C使用最小倍数删除S得到T



*/