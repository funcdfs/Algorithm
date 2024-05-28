// LINK: https://codeforces.com/contest/1133/problem/A
// NAME: 1133A. Middle of the Contest, Codeforces - Codeforces Round #544 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.12-17:47:08, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   string a = "", b = "";
   cin >> a >> b;

   auto convert = [](string& s) -> vector<int> {
      vector<int> ans(2, 0);
      ans[0] = stoi(s.substr(0, 2));
      ans[1] = stoi(s.substr(3, (int)s.size()));
      return ans;
   };

   vector<int> h1 = convert(a);
   vector<int> h2 = convert(b);

   dbg(h1, h2);
   
   int t1 = h1[0] * 60 + h1[1];
   int t2 = h2[0] * 60 + h2[1];
   int t = (t1 + t2) / 2;
   printf("%02d:%02d\n", t / 60, t % 60);

   return 0;
}

/*

1133A两个时间点的中间时间是多少

*/