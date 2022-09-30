// URL: https://www.acwing.com/problem/content/1060/
// NAME: 股票买卖带有冷却期, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-06 12:04:54

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

const int INF = 0x3f3f3f3f; 
const int N = 1e5+10; 
int f[N][3]; 
int w[N]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n = 0; 
	cin >> n; 
	for (int i = 1; i <= n; i++) cin >> w[i]; 
	
	f[0][0] = -INF; 
	f[0][1] = -INF; 
	f[0][2] = 0;
	
	for (int i = 1; i <= n; i++) {
		f[i][0] = max(f[i-1][0], f[i-1][2] - w[i]); 
		f[i][1] = f[i-1][0] + w[i]; 
		f[i][2] = max(f[i-1][1], f[i-1][2]); 
	}
	
	cout << max(f[n][1], f[n][2]) << endl; 

    return 0;
}

/*

状态机分类:


手中有货     手中无货的第一天    手中无货的第 大于等于二天


状态机之间的转换关系:
    手中有货:
        囤着
        变成手中无货的第一天
    手中无货的情况:
        不能再买了，所以不可以变为手中有货，也不能变为自己，只有向
		手中无货的大于等于二天走一个边 
	手中无货的第二天:
		继续维持手中无货的状态
		或者变为手中有货

f[i][0] = max(f[i-1][0], f[i-1][2] - w[i]) 
f[i][1] = f[i-1][0] + w[i] 
f[i][2] = max(f[i-1][1], f[i-1][2]) 

最终答案就是 max(f[n][1], f[n][2]); 

*/