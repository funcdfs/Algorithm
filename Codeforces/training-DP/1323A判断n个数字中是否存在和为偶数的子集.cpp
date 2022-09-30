// URL: https://codeforces.com/contest/1323/problem/A
// NAME: A. Even Subset Sum Problem, Codeforces - Codeforces Round #626 (Div. 2, based on Moscow Open Olympiad in Informatics)
// LIMIT: 512 MB, 1000 ms
// DATE: 2022-08-09 23:40:02

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

vector<int> findEvenSubset(vector<int>& a) {
	int n = a.size(); 
	vector<int> odd; 
	vector<int> even; 
	
	for (int i = 0; i < n; i++) {
		if (a[i] % 2) {
			odd.push_back(i); 
		} else {
			even.push_back(i); 
		}
	} 
	
	if (even.size() >= 1) {
		return {even[0] + 1}; 
	} 
	if (odd.size() >= 2) {
		return {odd[0] + 1, odd[1] + 1}; 
	} 
	
	return {}; 
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
    	
    	auto ans = findEvenSubset(a); 
    	if (ans.size() == 0) {
    		cout << "-1" << endl; 
    	} else {
    		cout << ans.size() << endl; 
    		for (auto& x : ans) cout << x << ' '; 
    		cout << endl; 
    	}
    }

    return 0;
}


/*

1323A判断n个数字中是否存在和为偶数的子集

求出它一个和为偶数的的非空子集。

每组输入对应一个输出，若无这样的非空子集，则输出 -1 。
否则第一行输出一个整数 k ，表示这个非空子集内元素的个数，
第二行输出这个非空子集内元素在原集合中的位置[下标加一]。(如果有多个子集成立，随便输出一个)

*/