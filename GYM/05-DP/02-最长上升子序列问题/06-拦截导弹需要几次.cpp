// Problem: 拦截导弹
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1012/
// date: 2022-07-22 18:09:23
// Memory Limit: 64 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */
// for debug:
// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";
#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 1010; 

int n; 
int q[N]; 
int f[N], g[N]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while (cin >> q[n]) n++; 
    
    int ans = 0; 
    for (int i = 0; i < n; i++) {
    	f[i] = 1; 
    	for (int j = 0; j < i; j++) {
    		if (q[j] >= q[i]) {
    			f[i] = max(f[i], f[j] + 1); 
    		}
    	}
    	ans = max(ans, f[i]); 
    }
    
    cout << ans << endl; 
    
    // g 数组存储当前现有的所有子序列
    // cnt 表示当前产生的子序列的个数
    int cnt = 0; 
    for (int i = 0; i < n; i++) {
    	int k = 0; 
    	while (k < cnt && g[k] < q[i]) {
    		k++; 
    	}
    	// 现在找到的 k 就是需要放入的位置 
    	g[k] = q[i]; 
    	
    	if (k >= cnt) { // 说明没有任何一个序列是大于等于当前数字的
    		cnt++; // 就为这个数字开辟一个新的序列
    	}
    }
    
    cout << cnt << endl; 
    
    return 0;
}

/*

第一问：一次拦截最多可以拦截多少个 LIS 问题

第二问：最少使用多少个防御系统，才可以将所有的导弹拦截住
		
		
	对于每一个新的导弹，可以选择， 接在现有的子序列的后面
	还可以选择，新开辟一个子序列
	
	那么具体应该拼接到哪一个子序列的后面呢？
	
	答案是拼接到，前面的一堆子序列中，结尾大于等于当前的集合中，结尾元素最小的那个子序列的后面
	
解法： （贪心）
	从前往后扫描每个数字，对于每一个数字
		情况 1 如果现有的子序列的结尾都小于当前数字，创建一个新的子序列，放到新的子序列中
		情况 2 如果存在可以进行拼接的子序列，选取结尾最小的子序列进行拼接
	
如何实现： 
	g 数组存储当前所有的开好的子序列的结尾的数字
	如果每一个数字都是按照贪心解法， 那么 g 序列是单调递增的
	
	一个数组最长上升子序列，等价于最少用多少个非上升子序列覆盖掉
*/