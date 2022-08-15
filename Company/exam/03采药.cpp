// Problem: 采药
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/425/
// date: 2022-03-27 15:24:17
// Memory Limit: 128 MB
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
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T, M; 
    cin >> T >> M; 
    
    vector<int> t(M + 1, 0); 
    vector<int> w(M + 1, 0); 
    
    for (int i = 1; i <= M; i++) cin >> t[i] >> w[i]; 
    // 将所有的价值读入 
    
    // 在 T 时间内可以获得的最大价值 
    // f[i][j] 表示 前 i 个物品，使用 j 时间的最大价值 
    
    vector<vector<int>> f(M + 1, vector<int>(T + 1, 0)); 
    // 则 结果就是 f[M][T] 
    
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j <= T; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= t[i]) f[i][j] = max(f[i][j], f[i - 1][j - t[i]] + w[i]); 
        }
    }
    // 在所有的 i 维度加上 & 1 就可以变为滚动数组优化空间 

    cout << f[M][T] << endl; 
    
    return 0;
}