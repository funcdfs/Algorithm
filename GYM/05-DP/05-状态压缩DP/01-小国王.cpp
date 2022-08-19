// URL: https://www.acwing.com/problem/content/1066/
// NAME: 小国王, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-08 11:12:22

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 0; 
    cin >> n; 
    vector<int> a(n); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    debug(a); 

    return 0;
}


/*

n*n 个棋盘，放置 k 个国王， 国王可以攻击周围的 8 个格子，求使得他们无法相互攻击的方案的总数 

状态压缩DP: 

状态表示: 
	f[i,j,s] 
	表示前 i 行已经做完了，并且当前已经放置了 j 个棋子，并且第 i 行的摆放的状态是 s 的所有方案的集合 
	
假如说三个格子，0 0 0 然后第一个和第二个格子放置了一个 棋子

那么此时的状态表示就是 1 0 1 ，用二进制就是 101 


状态属性： 
	count 
	
状态计算： 
	每一行的状态，最多存在 2^n 种不同的情况
	
	f[i-1] 的状态需要满足: 
		这一行本身不存在可以相互攻击到的国王（两个 1 相邻）
		和下一行 f[i] 的状态不存在可以相互攻击的国王
		(a & b == 0)
		(a | b) 不存在两个相邻的 1 		
	
	已经摆完了前 i 排，并且第 i 排的状态是 a， 第 i-1 排的状态是 b 的所有的方案，并且已经摆放了 j 个国王的所有方案
	已经摆完了前 i-1 排， 并且第 i-1 排的状态是 b， 并且已经摆放了 j-1 个国王的所有方案
	
	
*/




