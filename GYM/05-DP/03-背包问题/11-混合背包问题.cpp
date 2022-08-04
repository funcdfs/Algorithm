// Problem: 混合背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/7/
// date: 2022-07-25 16:33:54
// Memory Limit: 64 MB
// Time Limit: 1000 ms

/*
01 背包，完全背包，多重背包 

这三种状态表示都是 f[i][j] 

集合: 只从前 i 个物品种选，且总体积不超过 j 的选法
属性: 最大价值 

状态计算: 
01背包  f[i, j] = max(f[i-1,j]. f[i-1,j-v[i]]+w[i]
完全背包 f[i,j] = max(f[i-1,j], f[i,j-v[i]]+w[i]; 
多重背包 f[i,j] = max(f[i-1,j], f[i-1,j-v[i]]+w[i]	
					f[i-1,j-2v[i]]+2w[i], 
					... )
----

在做状态转移的过程中，因为只和第 i 件物品的类型是有关系的

*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std; 

const int N = 1010; 

int n, m; 
int f[N]; 

int main() {
	cin >> n >> m; 
	
	for (int i = 0; i < n; i++) {
		int v, w, s; // 体积，重量，和价值 
		cin >> v >> w >> s; 
		if (s == 0) { // 一个完全背包的物品
			for (int j = v; j <= m; j++) {
				f[j] = max(f[j], f[j - v] + w); 
			} 
		} else {
			if (s == -1) {
				s = 1; 
			} 
			// 01 背包其实是每件物品只有一件的特殊的多重背包问题 
			
			// 使用二进制优化的多重背包解法
			
		}
	}
	
	cout << f[m] << endl; 
	
	return 0; 
}