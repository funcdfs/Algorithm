#include <iostream>
using namespace std;
const int N = 10;

int n;
int path[N];
bool states[N];


// 不需要真正的去存一棵树，存路径

void dfs(int u) {
    if (u == n) { // 说明已经把所有的位置填满了
        for (int i = 0; i < n; i++) {
            printf("%d ", path[i]);
        }
        puts("");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (states[i] == false) { // 找到一个没有被用过的数字

            path[u] = i + 1;
            states[i] = true;

            dfs(u + 1); 

            // 恢复现场：  // path[u] = 0;
            states[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}
// https://www.acwing.com/activity/content/code/content/1519737/D