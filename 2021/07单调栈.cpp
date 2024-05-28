#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        scanf("%d", &x);
        while (tt && stk[tt] >= x) tt--;
        if (!tt)
            printf("-1 ");
        else
            printf("%d ", stk[tt]);
        stk[++tt] = x;
    }

    return 0;
}
// 输出左侧第一个小于当前元素的元素
// tt 代表 栈中元素的个数，

// https://www.acwing.com/activity/content/code/content/1461928/