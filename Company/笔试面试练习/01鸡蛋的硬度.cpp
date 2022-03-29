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