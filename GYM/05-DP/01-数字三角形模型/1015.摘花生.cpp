// Problem: 摘花生
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/1017/
// date: 2022-02-13 18:23:25
// Memory Limit: 64 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

// for debug:

// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";

#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int t;

vector<vector<int>> a;
vector<vector<int>> f;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // 只可以向上或者向下走一格
    // 问最多可以摘到多少个花生
    cin >> t;
    vector<vector<int>> a;
    while (t--) {
    	int r, c;
    	cin >> r >> c;
    	a.clear();
    	f.clear();
    	
    	a.resize(r);
    	for (auto& x : a) x.resize(c);
    	f.resize(r + 1);
    	for (auto& x : f) x.resize(c + 1);
    	
    	for (int i = 0; i < r; i++) {
    		for (int j = 0; j < c; j++) {
    			cin >> a[i][j];
    		}
    	}
		
    	for (int i = 1; i <= r; i++) {
    		for (int j = 1; j <= c; j++) {
    			f[i][j] = a[i - 1][j - 1] + max(f[i - 1][j], f[i][j - 1]);
    		}
    	}
    
        cout << f[r][c] << endl;
    }
    
    
    return 0;
}




































