// Problem: 递归实现组合型枚举
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/95/
// date: 2022-04-09 19:23:09
// Memory Limit: 256 MB
// Time Limit:   5000 ms


// #define d(a)  // https://github.com/fengwei2002/Algorithm
// #define dline // konng0120@gmail.com
// #define dendl // 

#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define INF 0x3f3f3f3f

#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; 
    cin >> n >> m; 
    
    // c_n^m 
    
    vector<vector<int>> ans;
    vector<int> path; 
    
    vector<int> a; 
    for (int i = 0; i < n; i++) a.push_back(i + 1); 
    
    function<void(int)> dfs = [&](int index) {
        if (path.size() == m) {
            ans.push_back(path); 
            return; 
        }
        if (index > n) return; 
        
        for (int i = index; i < n; i++) {
            path.push_back(a[i]); 
            dfs(i + 1);
            path.pop_back(); 
        }
    }; 
    
    dfs(0); 
    
    for (auto& x : ans) {
        for (auto& y : x) {
            cout << y << ' '; 
        }
        cout << endl; 
    }
    
    return 0;
}