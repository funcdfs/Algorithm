// Problem: 数字组合
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/280/
// date: 2022-07-23 16:11:21
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

const int N = 10010; 

int n, m; 
int f[N]; 

int main() {
	cin >> n >> m; 
	
	f[0] = 1; 
	
	for (int i = 0; i < m; i++) {
		int v; 
		cin >> v; 
		
		for (int j = m; j >= v; j--) {
			f[j] += f[j - v]; 
		}
		// f[i][j] = f[i - 1][j] + f[i - 1][j - v[i]]
	}
	
	cout << f[m] << endl; 
	
	return 0; 
}

/*
N 个正整数 

选出几个数，使得总和是 M 

把 M 作为背包容量

a[i] 看为一个物品 

求出总和恰好为 M 的方案数量，也就是总体积是指定容量的方案数量 



f[i][j] 

所有只从前 i 个物品中选择， 且总体积恰好是 j 的方案的集合
属性 count 

状态计算: 

f[i][j] 
	不包括物品 i 的所有的选法
		f[i - 1][j] 
	包括物品 i 的所有的选法 
		f[i - 1][j - v[i]]

等于两个部分的数量之和: 
f[i][j] = f[i - 1][j] + f[i - 1][j - v[i]]; 

*/