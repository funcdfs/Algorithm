// Problem: 登山
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1016/
// date: 2022-07-22 11:52:59
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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 0; 
    cin >> n; 
    
    vector<int> h(n, 0); 
    
    for (int i = 0; i < n; i++) {
    	cin >> h[i]; 
    }
    
	// 然后计算 h[i] 的左侧可以得到的最大的景点的数量
	// 再预处理 h[i] 的右侧可以得到的最大的景点的数量
	// 最后遍历求和 同时维护最大值 
	
	vector<int> left(n, 0); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (h[j] < h[i]) {
				left[i] = max(left[i], left[j] + 1); 
			}
		}
	}
	
	vector<int> right(n, 0); 
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= i; j--) {
			if (h[j] < h[i]) {
				right[i] = max(right[i], right[j] + 1); 
			}
		}
	}
    
    int ans = 0; 
    for (int i = 0; i < n; i++) {
    	ans = max(ans, left[i] + right[i] + 1); 
    } 
    
    cout << ans << endl; 
    
    return 0;
}