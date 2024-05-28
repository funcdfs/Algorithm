// LINK: https://codeforces.com/contest/474/problem/D
// NAME: 474D. Flowers, Codeforces - Codeforces Round #271 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.11.23-00:30:27, 1500 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

const int mod = 1e9 + 7; 

int64_t f(int x, int k) {
	// 在 f 中放置 k 的方案的数量有多少种，k 的具体数量没有具体的限制
}

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; cin >> tt; 
   int k = 0; cin >> k; 
   while (tt--) {
   	int a = 0, b = 0; 
   	cin >> a >> b;
   	b -= a, a = 0;  
   	cout << f(b, k) << '\n'; 
   }
   
   return 0;
}

/*



*/