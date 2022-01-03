#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], cnt;

void down(int u) {
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        swap(h[u], h[t]);
        down(t);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    cnt = n;
    for (int i = n / 2; i; i--) down(i);
    while (m--) {
        printf("%d ", h[1]);
        h[1] = h[cnt--];
        down(1);
    }
    return 0;
}

// https://www.acwing.com/activity/content/code/content/1465888/