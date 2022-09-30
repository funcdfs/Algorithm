// URL: https://www.acwing.com/problem/content/1051/
// NAME: 大盗阿福, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-06 10:23:14

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

const int INF = 0x3f3f3f3f; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    for (cin >> tt; tt--; ) {
    	int n = 0; 
    	cin >> n; 
    	vector<int> a(n, 0); 
    	for (int i = 0; i < n; i++) cin >> a[i]; 
    	
    	vector<vector<int>> f(n + 1, vector<int>(2, 0)); 
    	f[0][0] = 0; 
    	f[0][1] = -INF;  
    	// 状态机的入口，表示这个虚拟头节点状态可以不选，但是不能选
    	
    	for (int i = 1; i <= n; i++) {
    		f[i][0] = max(f[i-1][0], f[i-1][1]); 
    		f[i][1] = f[i-1][0] + a[i - 1];
    	} 
    	
    	cout << max(f[n][0], f[n][1]) << endl; 
    	// 状态机的终点可以选择也可以不选择 
    }

    return 0;
}


/*

f[i] 代表前 i 个屋子得到的最大价值

那么最终的结果就是 f[n] 

考虑 f[i] 的状态表示 
	f[i] = max(f[i-2]+w[i], f[i-1]) 
	


使用状态机类型 DP 的分析过程
希望每一次的状态只依赖上一层的状态 

由于一维状态表示只可以存储一个值，但是上一个状态明显存在两个值
所以可以使用 f[i-1][0] 和 f[i-1][1] 来分别代表上一个状态的两种不同的表现形式 

f[i][0]
f[i][1] 


0: 没有选择当前的店铺 
1: 选择了当前的店铺 

f[i][0] = f[i-1][0], f[i-1][1] 
f[i][1] = f[i-1][0] + w[i]


最终的状态机，两个点，三个边

0 到 0 有边
0 到 1 有边
1 到 0 有边 

每一步走一条边，求最优决策，任何一个抢劫的方案，都可以对应到状态机中的一种选择方法


状态表示: f[i][0], f[i][1] 
集合: 所有走了 i 步，并且当前位于状态 j 的所有走法
属性: max 


状态计算: 
max
f[i, 0]: f[i-1][0], f[i-1][1] 
f[i, 1]: f[i-1][1] + w[i]

*/