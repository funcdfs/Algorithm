// URL: https://codeforces.com/problemset/problem/1472/B
// NAME: B. Fair Division, Codeforces - Codeforces Round #693 (Div. 3)
// LIMIT: 256 MB, 2000 ms
// DATE: 2022-08-04 12:22:13

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

bool solve(vector<int>& cand) {
	dbg(cand);
	int sum = accumulate(cand.begin(), cand.end(), 0); 
	if (sum % 2) {
		return false; 
	} 
	sum >>= 1;  
	dbg(sum);
	vector<bool> f(sum + 1, false); 
	f[0] = true; 
	for (int i = 1; i <= cand.size(); i++) {
		for (int j = sum + 1; j >= cand[i - 1]; j--) {
			f[j] = f[j] || f[j - cand[i - 1]]; 
		}
	} 
	for (auto x : f) dbg(x); 
	return f[sum]; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    cin >> tt;
    while (tt--) {
    	int n = 0; 
    	cin >> n; 
    	vector<int> cand(n, 0); 
    	for (int i = 0; i < n; i++) cin >> cand[i]; 
    	dbg(cand);
    	if (solve(cand)) {
    		cout << "YES" << endl; 
    	} else {
    		cout << "NO" << endl; 
    	}
    }
    
    return 0;
}


/*

每个糖果 1 克或者 2 克 

分配糖果使得 alice 和 bob 的糖果总重量相等 

所有的糖果不可以分割，求最终是否可以达到目的

*/