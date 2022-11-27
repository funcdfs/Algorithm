// LINK: https://www.acwing.com/problem/content/4724/
// NAME: 排队, AcWing
// CODE: https://github.com/fengwei2002, 2022.11.25-22:05:54, 1000 ms

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
   vector<int> h(n, 0); 
   for (int i = 0; i < n; i++) cin >> h[i]; 
   vector<int> f(n, 0); 
   f[n - 1] = h[n - 1]; 
   // 把后缀看作一个单调递增的 f 数组
   
   for (int i = n - 2; i >= 0; i--) {
   	f[i] = min(h[i], f[i + 1]); 
   }
   // 每一个位置，都是后面出现的最小的
   
   for (int i = 0; i < n; i++) {
   	int l = i, r = n - 1; 
   	while (l < r) {
   		int mid = (l + r + 1) >> 1; 
   		if (f[mid] < h[i]) l = mid; // 找到小于 h[i] 的最靠后的位置
   		else r = mid - 1; 
   	}
   	cout << r - i - 1 << ' '; 
   }
   
   return 0;
}

/*



*/