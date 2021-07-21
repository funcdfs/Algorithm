#include <iostream>

using namespace std;

const int N = 1000010;

int a[N], q[N];
// 维护一个动态长度的栈而不是一个固定长度等于窗口的栈

int main() {
    int n, k;
    // n 代表数组长度， k 代表滑动窗口的长度
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int hh = 0, tt = -1;
    // 老样子， tt 代表栈顶，hh 代表应该弹出的栈边界
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        // 如果栈底小于栈顶
        // 并且固定长度的窗口没有移动到最右侧，
        // 栈底边界++
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        // 如果栈底小于栈顶，
        // 并且当前循环的 a[i] 比栈顶更加小
        // 上面栈顶元素不会再被用到了
        // tt--;
        q[++tt] = i;
        // 当栈中没有比当前 i 更加大的值得时候，把i放入栈中
        // 同时栈顶坐标 tt + 1
        if (i >= k - 1) printf("%d ", a[q[hh]]);
        // 从可以放下一个滑动窗口的位置开始，
        // 输出栈底元素即可
    }

    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;

        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;

        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    puts("");

    return 0;
}