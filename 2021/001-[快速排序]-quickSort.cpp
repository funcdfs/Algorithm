#include <iostream>

using namespace std;

int n;
const int N = 1e5 + 10;
int a[N];

void quickSort(int q[], int l, int r) {
    if (l >= r) return;

    int x = q[(l + r) >> 1], i = l - 1, j = r + 1; // x 的取值，取的值除了 q[r] 都可以，但是取中间的数字略微快一些
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quickSort(q, l, j);
    quickSort(q, j + 1, r);
    // 第一次的基准值不取 q[r] 边界值为：
    // q, l, j 
    // q, j + 1, r
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}

// https://www.acwing.com/activity/content/code/content/1391771/