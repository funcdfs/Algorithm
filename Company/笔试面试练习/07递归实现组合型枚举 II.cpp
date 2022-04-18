// Problem: 递归实现组合型枚举 II
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/1575/
// date: 2022-04-09 19:30:23
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
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    // 元素可以重复，但是生成的集合不可以重复 
    
    vector<vector<int>> ans; 
    vector<int> path; 
    
    sort(a.begin(), a.end()); 
    
    function<void(int)> dfs = [&](int index) {
        if (index > n) {
            return; 
        }
        if (path.size() == m) {
            ans.push_back(path); 
            return; 
        }
        for (int i = index; i < n; i++) {
            if (i > index && a[i] == a[i - 1]) continue; 
            // 规定值相同的元素在答案中出现的前后顺序 
            
            path.push_back(a[i]); 
            dfs(i + 1);
            path.pop_back(); 
        }
    }; 
    
    dfs(0); 
    
    for (auto& x: ans) {
        for (auto& y : x) {
            cout << y << ' '; 
        }
        cout << endl; 
    }
    
    return 0;
}