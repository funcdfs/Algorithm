``` cpp 
// 每次只可以合并相邻的两堆石头
// 如何可以使得最终的结果是最小的代价。输出最小的代价

f[i, j] 表示所有从 i 到 j 的方案
        属性是最小值

考虑根据边界点划分 f[i, j]:
        f[l, k] + f[k + 1, r] + S[l, r]


最后一次合并区间的时候一定是左边一堆数据，右边一堆数据

#include <iostream>
using namespace std;

const int N = 310;

int n;
int s[N];  // 存储前缀和
int f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
    for (int len = 2; len <= n; len++) { 
        // 枚举区间的长度
        for (int i = 1; i + len - 1 <= n; i++) {
            // i 为左侧的端点，j 为右侧的端点
            int j = i + len - 1;
            f[i][j] = 1e8;
            for (int k = i; k < j; k++) {
                int x = f[i][k] + f[k + 1][j] + s[j] - s[i - 1];
                f[i][j] = min(f[i][j], x);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}
```