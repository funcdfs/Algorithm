// Problem: 数独检查
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/705/
// date: 2022-07-24 12:13:21
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
#include <cstring>

using namespace std;




const int N = 40; 

int n, m; 
int a[N][N];   // 存储具体的矩阵
bool st[N]; // 


bool check_row() {
	for (int i = 0; i < m; i++) {
		memset(st, 0, sizeof st); 
		for (int j = 0; j < m; j++) {
			int t = a[i][j]; 
			
			if (t < 1 || t > m) {
				return false; 
			} 
			if (st[t] == true) {
				return false; 
			} 
			
			st[t] = true; 
		}
	}
	
	return true; 
}

bool check_col() {
	for (int i = 0; i < m; i++) {
		memset(st, 0, sizeof st); 
		for (int j = 0; j < m; j++) {
			int t = a[j][i]; 
			if (t < 1 || t > m) return false; 
			if (st[t] == true) return false; 
			
			st[t] = true; 
		}
	} 
	
	return true; 
} 


bool check_cell() {
	for (int x = 0; x < m; x += n) {
		for (int y = 0; y < m; y += n) { // 枚举具体的小方格左上角起始点 
		memset(st, 0, sizeof st); // 杜宇每一个小方格，清空判重数组
			for (int dx = 0; dx < n; dx++) {
				for (int dy = 0; dy < n; dy++) { // 枚举每个 cell 中的点
					int t = a[x + dx][y + dy]; 
					if (t < 1 || t > m) return false; 
					if (st[t] == true) return false; 
					
					st[t] = true; 
				}
			}
		}
	}
	return true; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T; 
    cin >> T; 
    
    for (int C = 1; C <= T; C++) {
    	cin >> n; 
    	m = n * n; 
    	
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < m; j++) {
    			cin >> a[i][j]; 
    		}
    	}
    	// 读入整个矩阵 
    	
    	if (check_row() && check_col() && check_cell()) {
    		cout << "Case #" << C << ": Yes\n";
    	} else {
    		cout << "Case #" << C << ": No\n";
    	}
    }
    
    
    
    return 0;
}


/*

每一个三乘三的小方格中的 1 到 9 都要至少出现一次

同时，每一行和每一列都要包含 1 到 9 的所有数字 

判断数独是否合法
	也就是，方格，行和列中的数独中的数字 1 到 n^2 只出现一次
	是的话输出 Yes
	不是的话输出 No
*/