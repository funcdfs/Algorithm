#include <iostream>

using namespace std;
const int N = 1e6 + 10;

int n, q[N], tmp[N];

void merge_sort(int q[], int l, int r) {
    if (l >= r) return;

    int mid = (l + r) >> 1;  // 确定中点

    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);  // 将左右区间变为有序

    int k = 0, i = l, j = mid + 1;  // 归并：合二为一 

    while (i <= mid && j <= r) { // tmp 额外数组
        if (q[i] <= q[j]) {
            tmp[k++] = q[i++];
        } else {
            tmp[k++] = q[j++];
        }
    }

    while (i <= mid) tmp[k++] = q[i++]; // 扫尾操作
    while (j <= r) tmp[k++] = q[j++];

    for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j]; // 把结果 复制回 q 数组
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}

// https://www.acwing.com/activity/content/code/content/1394859/