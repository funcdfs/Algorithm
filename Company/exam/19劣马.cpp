// Problem: 劣马
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/697/
// date: 2022-04-21 19:56:52
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
    
    int t = 0; 
    cin >> t ;
    
    for (int l = 0; l < t; l++) {
        int m = 0;
        cin >> m; 
        for (int i = 0; i < m; i++) {
            string a, b; 
            cin >> a >> b; 
            // 代表 a 和 b 是一个敌对关系 
            // 在无向图中连接 a 和 b 
            
        }
        
        // 输出这个无向图是否为一个二分图 
        cout << "Case #" << l + 1 << ": " << cal() << endl;  
    }
    
    return 0;
}