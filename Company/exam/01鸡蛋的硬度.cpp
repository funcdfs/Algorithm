// url:  https://www.acwing.com/problem/content/1050/
// date: 2022-03-23 21:06:33
// Memory Limit: 64 MB
// Time Limit:   1000 ms

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

const int N = 110; 
const int M = 11; 

int n, m; 
int f[N][M];

int main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            f[i][1] = i; 
        } // 用一个鸡蛋测试长度为 i 的区间，必须要测试 i 次 
        
        for (int i = 1; i <= m; i++) {
            f[1][i] = 1; 
        } // 高度为 1 的区间，有 i 个鸡蛋，只需要测试 1 次 
        
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                f[i][j] = f[i][j - 1]; 
                for (int k = 1; k <= i; k++) {
                    f[i][j] = min(f[i][j], max(f[k - 1][j - 1], f[i - k][j]) + 1);
                }
            }
        }
        
        cout << f[n][m] << endl; 
    }
    return 0;
}

/*

首先根据 100 2 14 进行推导 

如果说 第一颗鸡蛋在第 14 层碎掉了
    那么就剩下一个鸡蛋，把 1 到 13 依次试一遍即可 
如果说 第一颗鸡蛋在第 14 层没有掉
    那么还剩下两颗鸡蛋，和 13 次机会，那么就在 14 + 13 = 27 的地方再试一次 
    如果这次在 27 的地方碎掉了，那么就用第二个鸡蛋在 15 - 26 中间的所有数字都试一遍 
    如果没有碎掉，那么还剩下两颗鸡蛋，和 12 次机会，那么就在 27 + 12 = 39 的地方再试一次 

39 + 11 = 50 
50 + 10 = 60 
60 + 9  = 69 
69 + 8  = 77 
77 + 7  = 84 
84 + 6  = 90 
90 + 5  = 95 
95 + 4  = 99 
99 + 3  = 102 
...
106


f[i][j] 表示所有测量区间长度是 i 并且有 j 个鸡蛋的测量方案 
存储的值是，最坏情况下的最小值 

考虑 f[i][j] 的来源 

1: 没有用过鸡蛋 j  f[i][j - 1] 
2: 用过鸡蛋 j     
    根据在第几层用的这一个鸡蛋 j 把结果分成 k 类 
    1 ... .k .. . . i 
    求出每一种情况下的最小值，第二种情况就是 这 k 种情况之间的最小值 
        碎了:    f[k - 1][j - 1] 
        没有碎:  f[i - k][j]
    max(f[k - 1][j - 1], f[i - k][j]) + 1 
    
*/