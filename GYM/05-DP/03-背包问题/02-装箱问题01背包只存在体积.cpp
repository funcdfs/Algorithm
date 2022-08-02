// Problem: 装箱问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1026/
// date: 2022-07-23 14:06:27
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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; 
    cin >> m >> n; 
    
    vector<int> v(n + 1, 0); 
    for (int i = 1; i <= n; i++) cin >> v[i]; 
    
    vector<int> f(m + 1, 0); 
    
    for (int i = 1; i <= n; i++) {
    	for (int j = m; j >= v[i]; j--) {
    		f[j] = max(f[j], f[j - v[i]] + v[i]); 
    	}
    } 
    
   	cout << m - f[m] << endl;  
    
    return 0;
}