#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;  /// 在 l 到 r 的区间上加的每一个值上 c
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];  
    // 为了和二维差分统一可以使用insert(i,i,a[i]) 进行记忆

    while (m--) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i++) b[i] += b[i - 1];
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);

    return 0;
}

// https://www.acwing.com/activity/content/code/content/1415613/