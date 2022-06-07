// problem: P4017 最大食物链计数
// url: https://www.luogu.com.cn/problem/P4017
// date: 2022-06-07 12:59:06
// time: 1000 ms

/* https://github.com/fengwei2002/algorithm */

// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";
#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>
/* ------------------------------ */

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

const int MOD = 80112002; 
// 不是统计最长的食物链的长度，是统计图中一共存在多少个食物链

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; 
    
    cin >> n >> m; 
    
    vector<vector<int>> g(n, vector<int>(0, 0)); 
    vector<int> inDegree(n, 0); 
    vector<int> outDegree(n, 0); 
    
    auto add = [&](int a, int b) {
    	g[a].push_back(b); 
    	inDegree[b]++; 
    	outDegree[a]++; 
    }; 
    
    for (int i = 0; i < m; i++) {
    	int a, b; 
    	cin >> a >> b; 
    	add(a, b); 
    }
    
    
    return 0;
}