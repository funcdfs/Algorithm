// Problem: 雨
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/594/
// date: 2022-04-21 20:01:32
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
    
    // 接雨水二维版本 
    // 给定岛屿的高度矩阵，计算最后可以获得的雨水的总和 
    
    int t = 0; 
    cin >> t; 
    
    function<int(vector<vector<int>>&)> cal = [&](vector<vector<int>>& a) -> int {
        int ans = 0; 
        
        
        
        return ans;  
    }; 
    
    for (int l = 0; l < t; l++) {
        int r = 0, c = 0; 
        cin >> r >> c; 
        vector<vector<int>> a(r, vector<int>(c, n)); 
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> a[i][j]; 
            }
        }
        
        cout << "Case #" << l + 1 << ": " << cal(a) << endl; 
    }
    
    
    return 0;
}