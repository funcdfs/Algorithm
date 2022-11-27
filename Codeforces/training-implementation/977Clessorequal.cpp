// LINK: https://codeforces.com/contest/977/problem/C
// NAME: 977C. Less or Equal, Codeforces - Codeforces Round #479 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.11.26-10:13:18, 2000 ms

#include <bits/stdc++.h>
using namespace std;
auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, k = 0; 
   cin >> n >> k; 
   vector<int> a(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   
   sort(a.begin(), a.end()); 
   if (k == n) return cout << a[n - 1], 0; 
   if (k == 0 and a[0] > 1) return cout << a[0] - 1, 0; 
   if (k > 0 and a[k] != a[k - 1]) return cout << a[k - 1], 0; 
   cout << -1 << '\n'; 
   
   return 0;
}
/*

977Clessorequal

*/