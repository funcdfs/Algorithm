// https://www.acwing.com/activity/content/code/content/1625393/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main() {
    scanf("%d%s", &n, a + 1);
    scanf("%d%s", &m, b + 1);

    for (int i = 0; i <= m; i ++ ) f[0][i] = i;
    // 考虑从 A[0] 变为 B[i] 的解法，增加 i 个元素， 步骤数量为 i
    for (int i = 0; i <= n; i ++ ) f[i][0] = i;
    // 考虑从 A[i] 变为 B[0] 的解法，删除 i 个元素, 步骤数量为 i

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (a[i] == b[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else 
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }

    printf("%d\n", f[n][m]);

    return 0;
}