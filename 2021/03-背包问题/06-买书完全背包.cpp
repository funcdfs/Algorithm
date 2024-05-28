// Problem: 买书
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1025/
// date: 2022-07-23 18:07:50
// Memory Limit: 64 MB
// Time Limit: 1000 ms

/*

#include <iostream>

using namespace std; 

const int N = 1010;

int v[5] = {0, 10, 20, 50, 100}; 
int f[4][N]; 

int main() {
	int m; 
	cin >> m; 
	
	f[0][0] = 1; 
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j <= m; j++) {
			f[i][j] = f[i - 1][j]; 
			if (j >= v[i]) {
				f[i][j] += f[i][j - v[i]]; 
			}
		}
	}
	
	cout << f[4][m]; 
	
	return 0; 
}
*/

#include <iostream>

using namespace std; 

const int N = 1010; 

int v[5] = {0, 10, 20, 50, 100}; 
int f[N]; 
int m; 

int main() {
	cin >> m; 
	
	f[0] = 1; 
	
	for (int i = 1; i <= 4; i++) {
		for (int j = v[i]; j <= m; j++) {
			f[j] += f[j - v[i]]; 
		}
	}
	
	cout << f[m] << endl; 
	
	return 0; 
}

/*

有 n 元，然后可以全部用来买书，

书的可能的价格为 10 20 50 100 

问小明有多少种买书的方案(每种书可以购买无限本


状态表示: 
	f[i][j] 表示所有只从前 i 个物品中选择，且总体积恰好是 j 的方案的集合 
状态属性: 
	集合的数量，最终结果就是 f[4][n]; 

状态计算:
	选 0 个第 i 个物品 f[i - 1][j] 
	选 1 个第 i 个物品 f[i - 1][j - v[i]]
	选 2 个第 i 个物品 f[i - 1][j - 2*v[i]]
	...
	选 k 个第 i 个物品 f[i - 1][j - k*v[i]]

则目前的状态就可以明确的表示出来了

考虑 f[i][j - v[i]] 的状态计算 

	f[i - 1][j - v[i]]
	f[i - 1][j - 2*v[i]] 

所以 f[i][j] 可以转换为 

f[i][j] = f[i - 1][j] + f[i][j - v[i]]

*/