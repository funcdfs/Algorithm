// Problem: 货币系统
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1023/
// date: 2022-07-23 18:35:13
// Memory Limit: 64 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */
// for dbg:
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

const int N = 20;
const int M = 3010; 

int v[N];
long long f[M]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; 
    cin >> n >> m; 
    
    for (int i = 1; i <= n; i++) {
    	cin >> v[i]; 
    }
    
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
    	for (int j = v[i]; j <= m; j++) {
    		f[j] += f[j - v[i]]; 
    	}
    }
    
    cout << f[m] << endl; 
    
    return 0;
}


/*
n 种面值，求组成 m 有多少种方案
*/