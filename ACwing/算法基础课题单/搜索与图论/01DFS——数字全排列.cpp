#include <iostream>
using namespace std;
const int N = 10;

int n;
int path[N];
bool states[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", path[i]);
        }
        puts("");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (states[i] == 0) {
            path[u] = i + 1;
            states[i] = true;

            dfs(u + 1);

            // path[u] = 0;
            states[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}
// https://www.acwing.com/activity/content/code/content/1519737/