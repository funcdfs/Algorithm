// Problem: 1295：装箱问题
// Contest: SSOIER
// URL: http://ybt.ssoier.cn:8088/problem_show.php?pid=1295
// date: 2022-02-19 11:26:53
// Memory Limit: 65 MB
// Time Limit: 1000 ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int main() {
    // 因为每一个物品只可以使用一次
    // 所以是一个 01 背包 
    // 01 背包中每个物品有体积，有价值，
    // 这个题目中每个物品只存在体积  
    //     将物品的体积作为每个物品的价值即可 
    int v = 0;
    cin >> v; 
    int n = 0;
    cin >> n; 
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> f(n vector<int>(v, 0));
    
}



