// URL: https://www.acwing.com/problem/content/1015/
// NAME: 机器分配, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-03 14:59:56

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/

const int N = 15; 
const int M = 20; 

int n, m; 
int w[N][M]; 
int f[N][M]; 
int path[N]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m; 
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            cin >> w[i][j];
    
//     for (int i = 1; i <= n; i++) {
//     	for (int j = m; j >= 0; j--) {
//     		for (int k = 0; k < m; k++) {
//     			if (j - i >= 0) {
//     				f[j] = max(f[j], f[j - i] + w[i][k]); 
//     			}
//     		}
//     	}
//     }
// 	cout << f[m] << endl;
	

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]); 
            }
        }
    }
    cout << f[n][m] << endl;
	
	/* 接下来寻找具体的方案 */
    int j = m; 
    for (int i = n; i; i--) {
        for (int k = 0; k <= j; k++) {
            if (f[i][j] == f[i - 1][j - k] + w[i][k]) {
                path[i] = k; 
                j -= k; 
                break; 
            }
        }
    } 
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << path[i] << endl; 
    }

    return 0;
}

/*

背包容量为 M
存在一系列公司可以拿到一些机器，不同机器产生的权益不同

分配这些机器，求国家可以拿到的最大利益

为什么是一个分组背包的问题： 

 

将每一个公司作为物品组 

公司1: 
	一台，两台，三台
公司2: 
	一台，两台，三台
公司3: 
	一台，两台，三台

每一个公司相当于一个分组，每一个分组中只有一个物品可以选择，不同物品不同价值

*/