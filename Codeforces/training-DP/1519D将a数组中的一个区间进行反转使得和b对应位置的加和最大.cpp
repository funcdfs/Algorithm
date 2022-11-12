// LINK: https://www.luogu.com.cn/problem/CF1519D
// NAME: CF1519D Maximum Sum of Products, Luogu
// CODE: https://github.com/fengwei2002, 2022.10.29-21:36:44, 2000 ms

#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
   int n;
   cin >> n;
   vector<li> a(n), b(n);
   for (auto& x : a) cin >> x;
   for (auto& x : b) cin >> x;
   vector<li> pr(n + 1, 0);
   for (int i = 0; i < n; ++i) pr[i + 1] = pr[i] + a[i] * b[i];
   li ans = pr[n];
   for (int c = 0; c < n; ++c) {
      li cur = a[c] * b[c];
      for (int l = c - 1, r = c + 1; l >= 0 && r < n; --l, ++r) {
         cur += a[l] * b[r];
         cur += a[r] * b[l];
         ans = max(ans, cur + pr[l] + (pr[n] - pr[r + 1]));
      }
      cur = 0;
      for (int l = c, r = c + 1; l >= 0 && r < n; --l, ++r) {
         cur += a[l] * b[r];
         cur += a[r] * b[l];
         ans = max(ans, cur + pr[l] + (pr[n] - pr[r + 1]));
      }
   }
   cout << ans << endl;
}
/*

1519D将a数组中的一个区间进行反转使得和b对应位置的加和最大



naive approach is to iterate over l and r
reverse the subsegment of the array l, r and calculate the answer
O(n^3)

instead

iterate over the center of the reversed segment and its length
if the current segment is [l, r]
and we want to go to [l - 1, r + 1]
then the answer for the subsegment will increase by
   a[l - 1] * b[r + 1] + a[r + 1] * b[l - 1]
it remains to add the answer for [1, l) and (r, n]
but without reversion
this is easy to do if you pre-calculate the prefix sum of the values ai*bi
*/