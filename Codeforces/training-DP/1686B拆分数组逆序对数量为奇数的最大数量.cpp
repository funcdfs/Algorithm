// URL: https://codeforces.com/contest/1686/problem/B
// NAME: B. Odd Subarrays, Codeforces - Codeforces Round #794 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-10 13:50:46

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

int findMaxSplitMethodCnt(vector<int>& a) {
	int n = a.size(); 
	int ans = 0; 
	
	for (int i = 0; i < n - 1; i++) {
		dbg(a[i]); 
		if (a[i] > a[i+1]) {
			ans++; 
			i++; 
		}
	} 
	
	return ans; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
    	int n = 0; 
    	cin >> n; 
    	vector<int> a(n, 0); 
    	for (int i = 0; i < n; i++) cin >> a[i]; 
    	cout << findMaxSplitMethodCnt(a) << endl; 
    }

    return 0;
}


/*

1686B拆分数组逆序对数量为奇数的最大数量

一个“奇怪”的序列满足此序列中有奇数个逆序对

拆分为连续的子数组，使得这些子序列中“奇怪的”序列数量最多


---

每一个数字的取值范围从 1 到 n 并且每个数字都只出现一次 

按照每一个数字一个单独序列进行分类，这样得到的段数最多 

考虑贪心： 

从前往后，
将这两个数组合成一个序列可以增加逆序对数为奇数序列数的数量，同时剩下的序列数会尽可能的多

所以遇到两个相邻逆序的加起来就可以了，

i++ 为了防止重复判断逆序对中的元素 
*/