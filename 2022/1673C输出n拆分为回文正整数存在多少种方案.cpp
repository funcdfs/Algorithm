// URL: https://codeforces.com/contest/1673/problem/C
// NAME: C. Palindrome Basis, Codeforces - Codeforces Round #785 (Div. 2)
// LIMIT: 256 MB, 2000 ms
// DATE: 2022-08-08 18:33:24

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

const int MOD = 1e9+7; 

const int N = 4*1e4+10; 
int f[N]; 

inline bool isPalindrome(int x) {
	int t = 0;  
	int originX = x; 
	while (x > 0) {
		t = t * 10; 
		t += (x % 10); 
		x /= 10; 
	} 
	return t == originX; 
}

void init() {
	vector<int> t; 
	
	f[0] = 1; 
	for (int i = 1; i <= N; i++) {
		if (isPalindrome(i)) {
			t.push_back(i); 
		}
	} 
	
	for (int i = 0; i < t.size(); i++) {
		for (int j = t[i]; j <= N; j++) {
			f[j] = (f[j] + f[j - t[i]]) % MOD; 
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    cin >> tt; 
    
    init(); 
    
    while (tt--) {
    	int n = 0; 
    	cin >> n; 
    	cout << f[n] << endl; 
    }

    return 0;
}


/*

1673C输出n拆分为回文正整数存在多少种方案

*/