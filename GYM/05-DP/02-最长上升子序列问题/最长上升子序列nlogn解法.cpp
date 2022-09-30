// URL: https://www.acwing.com/problem/content/898/
// NAME: 最长上升子序列 II, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-07 12:59:03

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 0; 
    cin >> n; 
    
    vector<int> a(n, 0); 
    
    for (int i = 0; i < n; i++) {
    	cin >> a[i]; 
    }
    
    vector<int> q(n + 1, 0); 
    // q 存储所有不同长度下，最长上升子序列的最小值 
    
    int len = 0; 
    q[0] = -2e9; 
    
    for (int i = 0; i < n; i++) {
    	int l = 0, r = len; 
    	// 找到从 0 到 len 之间小于 a[i] 的最大的数字 
    	while (l < r) {
    		int mid = (l + r + 1) >> 1; 
    		if (q[mid] < a[i]) l = mid; 
    		else r = mid - 1; 
    	} 
    	len = max(len, r + 1);  
    	// r 找的是可以接到某个值的后面
    	q[r+1] = a[i]; 
    }
    
    cout << len << endl; 
    
    return 0;
}


/*

求以每个数字结尾的最长上升子序列的长度 

枚举一下倒数第二个数是哪个数

3 1 2 1 8 5 6

加入说 8 前面接的数字

如果可以接 3 的话，那么一定可以接 1 

如果可以接到一个结尾比较大的子序列后面，那么一定可以接到一个比较小的子序列后面

	所以可以
		存储一下，每一种长度的，上升子序列的，结尾的值最小是多少 

长度越长的话，结尾的最小值越大 

要是想要最长的话，就应该把这个 a[i] 拼接到最大的小于 a[i] 的结尾的后面去 

现在就是多了一步，在有序序列中，找到小于 a[i] 的最大的一个数字 
*/