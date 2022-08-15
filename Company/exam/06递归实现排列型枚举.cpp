// Problem: 递归实现排列型枚举
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/96/
// date: 2022-03-30 10:57:52
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
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional> 

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 0;
    cin >> n; 
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) a[i] = i + 1; 
    
    vector<int> path; 
    vector<vector<int>> ans; 
    vector<bool> st(n, false); 
    
    function<void()> dfs = [&]() {
        if (path.size() >= n) {
            ans.push_back(path); 
            return; 
        }
        
        for (int i = 0; i < n; i++) {
            if (st[i] == false) {
                path.push_back(a[i]); 
                st[i] = true; 
                dfs(); 
                st[i] = false; 
                path.pop_back(); 
            } 
        }
    }; 
    
    dfs(); 
    
    for (auto x : ans) {
        for (auto y : x) {
            cout << y << ' '; 
        }
        cout << endl; 
    }
    return 0;
}