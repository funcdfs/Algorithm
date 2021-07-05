#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    // 前缀和的初始化 从一开始， 第一位的值为 0 
    // 因为需要用到 s0 的值，所以用相减的方法统一值就可以  

    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);  // 注意下标值
        // s_r   = a1 + a2 + a3 + ar;
        // s_l-1 = a1 + a2 + a_(l-1)  所以减完之后就会是 al 到 ar 的和！
    }

    return 0;
}

// https:  // www.acwing.com/activity/content/code/content/1415611/