// LINK: https://codeforces.com/contest/1006/problem/A
// NAME: 1006A. Adjacent Replacements, Codeforces - Codeforces Round #498 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.05-14:47:19, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<int> a(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   
   vector<int> ans(n, 0); 
   int maxVal = *max_element(ans.begin(), ans.end()); 
   if (maxVal % 2 == 0) {
   	for (int i = 0; i < n; i++) {
   		if (a[i] % 2 == 0) {
   			ans[i] = a[i] - 1; 
   		} else {
   			ans[i] = a[i]; 
   		}
   	}
   } else {
   	for (int i = 0; i < n; i++) {
   		if (a[i] % 2 == 0) {
   			ans[i] = a[i]; 
   		} else {
   			ans[i] = a[i] + 1; 
   		}
   	}
   }
    
   for (int i = 0; i < n; i++) {
   	cout << ans[i] << ' '; 
   }
   
   return 0;
}

/*

1006A替换数组每一步基础前一步得到的结果

*/