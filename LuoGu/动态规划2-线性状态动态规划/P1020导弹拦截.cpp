// Problem: P1020 [NOIP1999 普及组] 导弹拦截
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1020
// date: 2022-07-06 16:32:40
// Memory Limit: 125 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */
// for debug:
// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";
#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
	vector<int> a(0, 0); 
	int x = 0;
	while (cin >> x) {
		a.push_back(x); 
	}
    int n = a.size(); 
    vector<int> f(n, 1); 
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < i; j++) {
    		if (a[i] < a[j]) {
    			f[i] = max(f[i], f[j] + 1); 
    		}
    	}
    }
    
    cout << *max_element(f.begin(), f.end()) << endl; 
    
    vector<int> g(n, 0); 
    // g 数组存储当前现有的所有的子序列 
    // cnt 表示当前产生的子序列的个数 
    
    int cnt = 0; 
    for (int i = 0; i < n; i++) {
    	int k = 0; 
    	while (k < cnt && g[k] < a[i]) {
    		k++; 
    	}
    	// 现在找到的 k 就是需要放入的位置 
    	
    	g[k] = a[i]; 
    	
    	if (k >= cnt) {
    		cnt++; 
    	}
    }
    
    cout << cnt << endl; 
    
    return 0;
}


/*
第一行: 	
	一个系统最多可以拦截多少个导弹 
	
第二行: 
	如果要拦截所有的导弹，需要多少的拦截系统
*/