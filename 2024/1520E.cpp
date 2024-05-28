#include <bits/stdc++.h>
using namespace std;

auto solve() -> void {

   int n = 0;
   cin >> n;
   string s;
   cin >> s;

   vector<int> idxs(0, 0);
   for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
         idxs.push_back(i);
      }
   }
   if ((int)idxs.size() == 0 or (int) idxs.size() == n) {
      cout << 0 << '\n';
      return;
   }

   int midIdx = (int)idxs.size() / 2;
   int leftLen = 0, rightLen = 0;

   vector<bool> linked(n, false);
   int l = idxs[midIdx], r = idxs[midIdx];
   while (l >= 0 and s[l] == '*') {
      linked[l] = true;
      l -= 1;
   }
   while (r <= n - 1 and s[r] == '*') {
      linked[r] = true;
      r += 1;
   }

   int64_t ans = 0;

   for (int i = midIdx - 1; i >= 0; i--) {
      if (linked[idxs[i]] == true) {
         // assert(s[idxs[i]] == '*');
         leftLen += 1;
         continue;
      }
      ans += (idxs[midIdx] - leftLen) - idxs[i] - 1;
      leftLen += 1;
   }

   for (int i = midIdx + 1; i < (int)idxs.size(); i++) {
      if (linked[idxs[i]] == true) {
         // assert(s[idxs[i]] == '*');
         rightLen += 1;
         continue;
      }
      ans += idxs[i] - (idxs[midIdx] + rightLen) - 1;
      rightLen += 1;
   }

   cout << ans << '\n';

   return;
}

auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int TT = 0;
   cin >> TT;
   for (int _case = 1; _case <= TT; _case++) {
      solve();
   }

   return 0;
}