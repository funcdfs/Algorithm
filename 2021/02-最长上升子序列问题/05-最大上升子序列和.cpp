// Problem: 最大上升子序列和
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1018/
// date: 2022-07-22 17:56:06
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
    
    int n = 0; 
    cin >> n; 
    
    vector<int> a(n, 0); 
    
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    
    vector<int> f(n, 0);  
    for (int i = 0; i < n; i++) f[i] = a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                f[i] = max(f[i], f[j] + a[i]); 
            }
        }
    }
    
    cout << *max_element(f.begin(), f.end()) << endl; 
    
    return 0; 
}
/*

求解的问题变为了，最长上升子序列的每个数字的和的最大值是多少 

状态表示: 
	所有以 a[i] 结尾的上升子序列 
	属性: 和的最大值 
状态计算:
	f[i] = f[j] + a[i] 

*/