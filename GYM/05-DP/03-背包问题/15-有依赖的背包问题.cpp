// URL: https://www.acwing.com/problem/content/10/
// NAME: 有依赖的背包问题, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-03 18:28:54

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

const int N = 110; 

int n, m; 
int v[N], w[N]; // 读入每一个节点的体积和价值
int h[N], e[N], ne[N], idx; // 使用邻接表存储树
int f[N][N]; 

void add(int a, int b) {
	e[idx] = b; 
	ne[idx] = h[a]; 
	h[a] = idx++; 
}

void dfs(int u) {
	
	// 枚举节点 u 的所有的出边
	for (int i = h[u]; i != -1; i = ne[i]) { // 循环物品组
		int son = e[i]; 
		dfs(son); 
		
		// 分组背包 
		for (int j = m - v[u]; j >= 0; j--) { // 循环具体的体积, 选定 v[i] 之后，剩余 m - v[i] 个体积
			for (int k = 0; k <= j; k++) {    // 循环决策, son 中体积为 k 的最大的那个存在 f[u][j] 中
				f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]); 
			}
		}
	} 
	
	// 将物品 u 的价值加到物品 u 可以走的路线的权值中 
	for (int i = m; i >= v[u]; i--) {
		f[u][i] = f[u][i - v[u]] + w[u]; 
	} 
	
	// 当体积小于 v[u] 的时候，一定一个物品都放不进去，都是 0 （连根节点都放不进去） 
	for (int i = 0; i < v[u]; i++) {
		f[u][i] = 0; 
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m; 
    memset(h, -1, sizeof h); 
    
    int root; // 根节点不一定是一号点
    for (int i = 1; i <= n; i++) {
    	int p; 
    	cin >> v[i] >> w[i] >> p; 
    	if (p == -1) {
    		root = i; 
    	} else {
    		add(p, i); // 添加从 p 指向 i 的一个边 
    	}
    }
    
    dfs(root); 
    // 根节点不选的话，其他节点都不能选，所以需要从根节点开始找
    
    cout << f[root][m] << endl; 
    // 输出以 root 为根节点，体积不超过 m 的情况下，最大价值是多少 

    return 0;
}


/*
在满足树形依赖的关系下，最多可以选择的价值 

每个物品只能选择一次 

如果选择一个节点的话，就必须选择他的父节点 

状态表示：f[u, j]
	代表所有以 u 为根的子树中选，且总体积不超过 j 的方案 

状态属性： max 最大价值

状态计算： 
	方案内部： 
	
	1： 子树 1 
	2： 子树 2 
	3： 子树 3   
	
	每一个方案按照子树分成不同的部分 
	
	每一个子树的内部也可以继续划分
		每一个子树的内部按照体积来划分（如果按照方案来划分就会有 2^100 种选择）
	
	现在对于 f[u, j] 来说就是，存在三个子树，每一个子树的内部可以选择具体使用多大的体积
	问总体积不超过 j 的最大价值是多少
	
	现在就变为了分组背包问题（因为物品数量只有一个，所以选择父亲节点之后，子树就需要从中挑选1个，并且只能是一个） 
*/