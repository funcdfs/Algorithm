// Problem: 直方图中最大的矩形
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/133/
// date: 2022-03-30 12:59:38
// Memory Limit: 64 MB
// Time Limit:   1000 ms

#include <iostream>
#include <vector> 

using namespace std; 

typedef long long LL; 

const int N = 1e5 + 10; 

int n; 
int h[N], l[N], r[N]; 
int q[N]; 

int main() {
    cin >> n; 
    for (int i = 1; i <= n; i++) cin >> h[i]; 
    h[0] = -1; 
    h[n + 1] = -1; // 添加两个哨兵，遇到烧饼界定啊就停止，不用

    // 求左边界 
    vector<int> stkLeft;
    stkLeft.push_back(-1);  
    for (int i = 1; i <= n; i++) {
        while (h[stkLeft.back()] >= h[i]) {
            // 栈顶元素一定不会被用到 
            stkLeft.pop_back(); 
        }
        l[i] = stkLeft.back(); 
        // 左边界就是当前的栈顶元素
        stkLeft.push_back(h[i]); 
    }


}