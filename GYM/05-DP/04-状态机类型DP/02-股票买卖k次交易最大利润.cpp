// URL: https://www.acwing.com/problem/content/1059/
// NAME: 股票买卖k次交易最大利润, AcWing
// LIMIT: 128 MB, 1000 ms
// DATE: 2022-08-06 11:09:13

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/

const int N = 1e5+10; 
const int M = 110; 

int f[N][M][2]; 

const int INF = 0x3f3f3f3f; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; 
    cin >> n >> m; 
    vector<int> w(n + 1, 0); 
    for (int i = 1; i <= n; i++) {
    	cin >> w[i]; 
    } 
 	memset(f, -0x3f, sizeof f); 
 	
 	for (int i = 0; i <= n; i++) { 
 	// 在一次交易都没有进行的情况下，手中一定是无货的 
 	// when j == 0 f[i][j][0] = 0 
 		f[i][0][0] = 0;
 		// f[i][0][1] = -INF; // 代表不可达
 	}   
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1] + w[i]); 
    		f[i][j][1] = max(f[i-1][j][1], f[i-1][j-1][0] - w[i]);  
    	}
    }
    
    // 最多进行 k 次交易，不一定进行 k 次交易，所以再枚举一下 
    int ans = 0; 
    for (int i = 0; i <= m; i++) {
    	ans = max(ans, f[n][i][0]);  
    	// 进行了 n 天，交易了 i 次， 最终手中无货的最大值 (完整的交易)
    }
    
    cout << ans << endl; 
    
    return 0;
}


/*

一次交易存在两个状态: 
	手中有货 
		下一天可以选择继续持有，就是这个状态走回自己
		下一天卖掉，就是这个状态走向 手中无货的状态
	手中无货 	
		下一天可以继续无货，状态走回自己
		下一天可以买入一个，就是走向 手中有货的状态


状态表示: 
	有两维，天数和次数，所以状态表示就是这两维加上个 0 和 1 
		f[i,j,0] 
			所有前 i 天，且已经进行了 j 次交易，且手中无货的所有的购买方式的集合
		f[i,j,1] 
			所有前 i 天，正在进行第 j 次交集，且手中有货的购买方式 
	
状态计算: 
	f[i][j][0]: 
		max(f[i-1][j][0], f[i-1][j][1] + w[i])  
			(f[i-1][j][1] 就是第 j 次进行了一半，需要从这个一半的状态转移过来 )
	f[i][j][1]: 
		max(f[i-1][j][1], f[i-1][j-1][0] - w[i]) 
		

*/