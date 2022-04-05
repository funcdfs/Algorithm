// Problem: P4017 最大食物链计数
// Contest: Luogu
// url:  https://www.luogu.com.cn/problem/P4017
// date: 2022-03-31 16:10:46
// Memory Limit: 125 MB
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

const int MOD = 80112002; 
const int N = 5010; 
const int M = 500010; 

int serach(int st, int ed) {
    // 计算图中 st 到 ed 的最短路径 
    // 属于多源汇最短路，使用 floyd 解决 
    // 10^10 TLE 
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 找出图中入度为 0 的点到达出度为 0 的点的最大的路径长度 
    cin >> n >> m;     
    vector<int> indegree(n, 0); 
    vector<int> ourdegree(n, 0); 
    
    for (int i = 0; i < m; i++) {
        int st, ed; 
        cin >> st >> ed; 
        g[st][ed] = 1; 
        indegree[ed] += 1; 
        outdegree[st] += 1; 
    }
    
    for (auto x : indegree) {
        if (x == 0) erase(x); 
    } 
    for (auto x : outdegree) {
        if (x == 0) erase(x); 
    }
    // 统计所有入度和出度为 0 的点 
    
    int ans = 0; 
    for (int i = 0; i < indegree.size(); i++) {
        for (int j = 0; j < outdegree.size(); j++) {
            ans = max(ans, search(indegree[i], outdegree[j])); 
        }
    }
    // 计算路径中的最大路径 
    
    cout << ans << endl; 
    // 输出最大路径 
    
    return 0;
}