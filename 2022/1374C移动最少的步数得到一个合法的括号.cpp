// https://github.com/fengwei2002, 2023.02.21-00:06:45
// https://codeforces.com/contest/1374/problem/C
// 1374C. Move Brackets, Codeforces - Codeforces Round #653 (Div. 3)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      vector<char> s(n, ' ');
      for (int i = 0; i < n; i++) cin >> s[i];
      
      int minVal = 0, b = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == '(') {
            b += 1;
         } else {
            b -= 1;
         }
         minVal = min(minVal, b);
      }
      cout << -minVal << '\n';
   }
   
   return 0;
}

/*

1374C移动最少的步数得到一个合法的括号

如果出现 () 则不用移动，因为已经是合法的了，
如果出现 )( 的情况则需要将任意一个 移走，步数贡献 为 1 

*/