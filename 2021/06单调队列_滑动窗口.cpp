#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N], q[N];
// 维护一个动态长度的栈而不是一个固定长度等于窗口的栈

int main() {
    int n, k; 
    cin >> n >> k;           // n 代表数组长度，k 代表滑动窗口的长度
    for (int i = 0; i < n; i++) cin >> a[i];

    int hh = 0, tt = -1;     // 老样子， tt 代表右侧的边界，hh 代表应该弹出的数组左边界
    for (int i = 0; i < n; i++) {

        if (hh <= tt && i - q[hh] + 1 > k) hh++;
        // 数组首元素下标如果距离 i 超过了 k
        // 模拟窗口向右移动的操作， 如果数组左边界比数组右边界小（数组中仍然存在元素）
        // 并且 固定长度的窗口没有移动到最右侧，左边界右移一位

        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        // 如果数组中仍然拥有元素（栈底小于栈顶）
        // 并且 当前循环的 a[i] 比数组最右侧的更加小 说明数组最右侧的元素不会再被用到了 (tt--)

        q[++tt] = i;
        // 当数组中已经没有比当前 i 下标对应的更加大的数值得时候，把 i 放入数组的最右侧
        // 同时栈顶坐标 tt + 1 （这一行开始执行 k 次用来初始化栈）

        if (i - 0 + 1 >= k) printf("%d ", a[q[hh]]);
        // 从可以放下一个滑动窗口的位置开始，
        // 输出栈底元素即可（他就是 i 之前的最小值了）
    }

    puts("");

    hh = 0, tt = -1;

    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - q[hh] + 1 > k) hh++; // 模拟窗口右移的操作

        while (hh <= tt && a[q[tt]] <= a[i]) tt--; // 进行元素的筛选
        q[++tt] = i;                   // 将无敌的这一位元素放入数组中

        if (i - 0 + 1 >= k) printf("%d ", a[q[hh]]); // 可以输出之后进行输出
    }

    puts("");

    return 0;
// }

// 链接：https://www.acwing.com/activity/content/code/content/1492128/
