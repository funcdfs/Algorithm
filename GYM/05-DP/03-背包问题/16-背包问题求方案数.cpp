// URL: https://www.acwing.com/problem/content/11/
// NAME: 背包问题求方案数, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-03 20:44:11

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

const int N = 1010; 
const int mod = 1e9 + 7; 

int n, m; 
int f[N], g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m; 
    
    memset(f, -0x3f, sizeof f); 
    f[0] = 0; 
    g[0] = 1; 
    
    for (int i = 0; i < n; i++) {
    	int v, w; 
    	cin >> v >> w; 
    	for (int j = m; j >= v; j--) {
    		int maxv = max(f[j], f[j - v] + w); 
    		int cnt = 0; 
    		if (maxv == f[j]) cnt += g[j]; 
    		if (maxv == f[j - v] + w) cnt += g[j - v]; 
    		g[j] = cnt % mod; 
    		f[j] = maxv; 
    	}
    }
    
    int ans = 0; 
    for (int i = 0; i <= m; i++) {
    	ans = max(ans, f[i]); 
    } 
    
    int cnt = 0; 
    for (int i = 0; i <= m; i++) {
    	if (f[i] == ans) {
    		cnt = (cnt + g[i]) % mod; 
    	}
    }
    
    cout << cnt << endl; 

    return 0;
}

/*

相比于之前的，背包问题

普通：求可以装满背包的方案的数量 
这个：求最优选法的方案数量，也就是最大价值的方案数

最优解的方案数，等价于求最短路径的条数

将动态规划的每一个状态看作一个点 
	问题就变为: 拓扑图中，等价于到达最终节点的时候求最短路径的条数


01背包的状态转移: f[i,j] = max(f[i-1,j], f[i-1,j-vi]+w[i]) 

同时再添加一个状态 
	g[i][j] 表示 f[i][j] 取最大值的方案数量

f[i][j] = 
	f[i-1][j]           g[i-1][j]
	f[i-1][j-vi]+w[i]   g[i-1][j-vi] 
	
	如果左右最大值一样大， 最终结果就是左边的元素数量加上右边的元素数量 
	
f[i][j] 代表前 i 个物品值恰好为 j 的方案数量 


*/