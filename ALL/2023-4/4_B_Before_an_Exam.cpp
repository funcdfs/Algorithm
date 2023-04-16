/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-14 17:55:27
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

struct day {
   int minTime;
   int maxTime;
   int diff;
   day() { this->minTime = 0, this->maxTime = 0, this->diff = 0; }
   day(int x, int y) {
      this->minTime = x;
      this->maxTime = y;
      this->diff = y - x;
   }
};

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int d = 0, sumTime = 0;
   cin >> d >> sumTime;
   if (sumTime == 0) {
    cout << "YES\n";
    for (int i = 0; i < d; i++) {
      cout << 0 << " \n"[i == d - 1];
    }
    return 0;
   }
   vector<day> days(d);
   for (int i = 0; i < d; i++) {
      cin >> days[i].minTime;
      cin >> days[i].maxTime;
      days[i].diff = days[i].maxTime - days[i].minTime;
   }

   int64_t minTotalTime = 0;
   for (auto& x : days) {
      minTotalTime += x.minTime;
   }
   if (sumTime >= minTotalTime) {
      int left = sumTime - minTotalTime;
      vector<int> ans(d, 0);
      for (int i = 0; i < d; i++) {
         ans[i] = days[i].minTime;
      }
      for (int i = 0; i < d; i++) {
         if (left - days[i].diff < 0) {
            ans[i] += left;
            left = 0;
            break;
         }
         ans[i] = days[i].maxTime;
         left -= days[i].diff;
      }
      if (left > 0) {
         return cout << "NO\n", 0;
      }
      cout << "YES\n";
      for (int i = 0; i < d; i++) {
         cout << ans[i] << " \n"[i == d - 1];
      }
   } else {
      return cout << "NO\n", 0;
   }

   return 0;
}
/*

*/