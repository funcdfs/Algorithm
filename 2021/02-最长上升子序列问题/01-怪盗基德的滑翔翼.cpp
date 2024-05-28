// Problem: 怪盗基德的滑翔翼
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1019/
// date: 2022-07-22 11:04:26
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

void calc(vector<int>& h) {
	int n = h.size(); 
	
	int ans = 0; 

	vector<int> f(n, 1); 
	// 对于每一个位置 i 考虑他前面的是否有比他大的，如果有，说明在这里可以继续下降一步
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (h[i] < h[j]) {
				f[i] = max(f[i], f[j] + 1); 
			}
		}
	}
	ans = max(ans, *max_element(f.begin(), f.end())); 
	fill(f.begin(), f.end(), 1); 
	// 对于每一个位置 i 考虑他的后面是否存在比他大的，如果有，说明在这里可以继续下降一步
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= i; j--) {
			if (h[i] < h[j]) {
				f[i] = max(f[i], f[j] + 1); 
			}
		}
	}
	ans = max(ans, *max_element(f.begin(), f.end())); 
	cout << ans << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    int k = 0; 
    cin >> k; 
    
    while (k--) {
    	int n = 0; // n 栋楼
    	cin >> n; 
    	vector<int> h(n, 0); 
    	for (int i = 0; i < n; i++) cin >> h[i]; // 读入 n 栋楼的具体高度 
    	
    	calc(h); 
    }
    
    
    return 0;
}