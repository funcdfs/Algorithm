// LINK: https://atcoder.jp/contests/abc281/tasks/abc281_d
// NAME: D - Max Multiple, AtCoder - AtCoder Beginner Contest 281
// CODE: https://github.com/fengwei2002, 2022.12.10-20:23:52, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, k = 0, d = 0; 
   cin >> n >> k >> d;
   vector<int> a(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   
   // 从 a 中选择 k 个数字的和组成一个 set 
   // 在这个 set 中找 D 的最大倍数是多少
   vector<int> st(n, 0);
   for (int i = 0; i < n; i++) {
      if (a[i] % d == 0) {
         st[i] = 1;
      }
   }
   if (count(st.begin(), st.end(), 1) < 1) {
      return cout << -1, 0; 
   }
   dbg(n, k, d);
   dbg(a); 
   dbg(st);
   
   // 乘积是倍数就可以直接最大的取一个，然后剩下 k - 1 个数字都取数组中最大的部分即可
   // 但是此题的问题是 set 中存储的是 sum，sum 是 D 的倍数，最大的 sum 是多少
   
   
   
   return 0;
}

/*

找出数量为k的和为D的倍数的子集的最大和

*/