// URL: https://www.acwing.com/problem/content/description/9/
// NAME: 分组背包问题, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-03 15:12:59

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/

const int N = 110; 

int n, m;
int v[N][N], w[N][N], s[N];  
int f[N]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m; 
    
    for (int i = 1; i <= n; i++) {
    	cin >> s[i]; 
    	for (int j = 0; j < s[i]; j++) {
    		cin >> v[i][j] >> w[i][j]; 
    	} 
    } 
    
    // 从前往后枚举每一组，从大到小枚举所有体积 
    for (int i = 1; i <= n; i++) {
    	for (int j = m; j >= 0; j--) {
    		for (int k = 0; k < s[i]; k++) {
    			if (v[i][k] <= j) {
    				f[j] = max(f[j], f[j - v[i][k]] + w[i][k]); 
    			}
    		}
    	}
    }
    
    cout << f[m] << endl; 

    return 0;
}

/*

n 组物品和一个容量是 v 的背包 

每一组存在若干个物品，同一组内的物品最多只可以选择一个 

vij wij 

求最后把哪些物品装入背包，可以使得总体积不超过背包容量，并且总价值最大

状态表示: 
	f[i][j]: 只从前 i 组物品中选择，并且总体积不大于 j 的所有的选法 
状态划分: 
	f[i - 1][j] 
	f[i - 1][j - v[i,k]] + w[i,k] 
	
	用的是上一层，从大到小枚举
*/