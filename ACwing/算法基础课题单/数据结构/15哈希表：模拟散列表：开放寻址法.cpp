#include <cstring>
#include <iostream>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x) {
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x) {
        t++;
        if (t == N) t = 0;
    }
    return t;
}

int main() {
    memset(h, 0x3f, sizeof h);

    int n;
    scanf("%d", &n);

    while (n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'I')
            h[find(x)] = x;
        else {
            if (h[find(x)] == null)
                puts("No");
            else
                puts("Yes");
        }
    }

    return 0;
}
