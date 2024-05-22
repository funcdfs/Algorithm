/**
 * name: C. Parity Shuffle Sorting
 * link: https://codeforces.com/contest/1733/problem/C
 * time: 2024/5/22 22:07:51 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto solve(int _case) -> void {
   dbg(_case);
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];

   vector<int> oddIdx, evenIdx;
   for (int i = 0; i < n; i++) {
      if (a[i] % 2) {
         oddIdx.push_back(i);
      } else {
         evenIdx.push_back(i);
      }
   }

   reverse(oddIdx.begin(), oddIdx.end());

   int ansCnt = 0;
   if (oddIdx.size()) {
      ansCnt += (int)oddIdx.size() - 1;
   }
   if (evenIdx.size()) {
      ansCnt += (int)evenIdx.size() - 1;
   }
   if (oddIdx.size()) {
      ansCnt += (int)evenIdx.size();
   }

   if (ansCnt == 0) {
      cout << ansCnt << '\n';
      return;
   }

   cout << ansCnt << '\n';
   if ((int)oddIdx.size() >= 2) {
      for (int i = 1; i < (int)oddIdx.size(); i++) {
         cout << oddIdx[0] << ' ' << oddIdx[i] << endl;
         a[oddIdx[i]] = a[oddIdx[0]];
      }
   }

   reverse(evenIdx.begin(), evenIdx.end());
   if ((int)evenIdx.size() >= 2) {
      for (int i = 1; i < (int)evenIdx.size(); i++) {
         cout << evenIdx[0] << ' ' << evenIdx[i] << endl;
         a[evenIdx[i]] = a[evenIdx[0]];
      }
   }

   reverse(oddIdx.begin(), oddIdx.end());
   reverse(evenIdx.begin(), evenIdx.end());

   if (oddIdx.size() == 0 or evenIdx.size() == 0) {
      return;
   }

   dbg("before", a);
   for (int i = 0; i < (int)evenIdx.size(); i++) {
      cout << oddIdx[0] << ' ' << evenIdx[i] << '\n';
      a[evenIdx[i]] = a[oddIdx[0]];
   }

   dbg(a);

   return;
}

auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int TT = 0;
   cin >> TT;
   for (int _case = 1; _case <= TT; _case++) {
      solve(_case);
   }

   return 0;
}
/*

*/