#include <iostream>

using namespace std;
typedef long long LL;

const int N = 1e6 + 10;
int n, q[N], tmp[N];

// -- 左侧逆序对的数量
// -- 右侧逆序对的数量
// -- 交界处的 逆序对的数量 j = mid - i + 1

LL merge_sort(int q[], int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) >> 1;
    LL ans = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else {
            ans += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    // 扫尾
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    // 物归原主
    for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
    return ans;
}

int main (){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    printf("%lld", merge_sort(q, 0, n - 1));
    return 0;
}

// https://www.acwing.com/activity/content/code/content/1396468/