// URL: https://codeforces.com/problemset/problem/1538/A
// NAME: A. Stone Game, Codeforces - Codeforces Round #725 (Div. 3)
// LIMIT: 256 MB, 2000 ms
// DATE: 2022-08-04 12:46:07

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

int solve(vector<int>& a) {
	int ans = INT_MAX; 
	// return minimum number of destroy large and lowest
	
	int n = a.size(); 
	int minPos = find(a.begin(), a.end(), 1) - a.begin(); 
	int maxPos = find(a.begin(), a.end(), n) - a.begin(); 
	
	ans = min({
		max(maxPos, minPos) + 1, // all in left 
		(n - 1) - min(maxPos, minPos) + 1, // all in right 
		(n - 1) - maxPos + minPos + 2, // maxPos right, minPos left 
		(n - 1) - minPos + maxPos + 2  // maxPos left, minPos right
		// in array i, j's distance is i - j + 1
	});
	
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
    	vector<int> stones(n, 0); 
    	for (int i = 0; i < n; i++) cin >> stones[i]; 
    	
    	cout << solve(stones) << endl; 
    }

    return 0;
}


/*

一行 n 个石头，每一行的石头的权重互不相同 

每一次可以去除最左侧的石头或者最右侧的石头 

现在，Polycarp 想要两个成就。
如果他摧毁力量最小的石头和力量最大的石头，他就会得到它们。
帮助 Polycarp 找出他为了实现目标而应该采取的最少移动次数。

*/