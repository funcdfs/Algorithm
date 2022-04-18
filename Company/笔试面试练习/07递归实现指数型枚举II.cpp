// Problem: 递归实现指数型枚举 II
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/1574/
// date: 2022-04-09 19:09:30
// Memory Limit: 64 MB
// Time Limit:   1000 ms


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
    
    int n = 0; 
    cin >> n; 
    
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    sort(a.begin(), a.end()); 
    
    vector<vector<int>> ans;
    vector<int> path; 
    
    function<void(int)> dfs = [&](int index) {
        if (index > n) return; 
        
        ans.push_back(path); 
        for (int i = index; i < n; i++) {
            if (i > index && a[i] == a[i - 1]) continue;
            path.push_back(a[i]); 
            dfs(i + 1); 
            path.pop_back();
        }
    }; 
    
    dfs(0); 
    
    for (auto x : ans) {
        for (auto y : x) {
            cout << y << ' '; 
        }
        cout << endl; 
    }
    
    return 0;
}