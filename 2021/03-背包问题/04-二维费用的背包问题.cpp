// Problem: 二维费用的背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/8/
// date: 2022-07-23 14:33:58
// Memory Limit: 64 MB
// Time Limit: 1000 ms


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

const int N = 110; 

int n; // 个数
int V; // 容量上限
int M; // 重量上限 

int f[N][N]; 

int main() {
    
    cin >> n >> V >> M; 
    
    for (int i = 0; i < n; i++) {
        int v, m, w; 
        cin >> v >> m >> w; // 体积重量和价值 
        
        for (int j = V; j >= v; j--) {
            for (int k = M; k >= m; k--) {
                f[j][k] = max(f[j][k], f[j - v][k - m] + w); 
            }
        }
    }
    
    
    cout << f[V][M] << endl; 
    
    return 0; 
}

/*
二维费用的背包问题，就是每一个物品除去 价值和体积之后，加上了物品的重量，

背包中总物品的重量同时也不可以超过 最大重量，同时体积不超过最大体积，求可以获得的最大价值 

集合: 
f[i, j, k] 表示 
	所有只从前 i 个物品中选，并且总体积不超过 j，总重量不超过 k 的选法 
	属性 max
	
	
状态计算: 
	f[i, j, k] 的来源: 
	
	所有不包含物品 i 的选法: 
		f[i - 1][j][k]
	
	所有包含物品 i 的选法: 
		max(f[i - 1][j - v[i]][k - m[i]] + w[i])
	
	同 01 背包的一维空间优化方法， 这里也要使用逆序来遍历 j 和 k 两个维度 
*/