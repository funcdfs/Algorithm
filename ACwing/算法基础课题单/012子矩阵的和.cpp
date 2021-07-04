#include <iostream>

using namespace std;

const int N = 1010;

int n, m, q;
int s[N][N];

int main() {
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &s[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];  //三项

    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n",
               s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] +
                   s[x1 - 1][y1 - 1]);  //四项
    }

    return 0;
}
