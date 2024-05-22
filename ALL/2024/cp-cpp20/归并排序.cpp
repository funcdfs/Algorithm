/**
 * name: 归并排序
 * link: https://www.acwing.com/problem/content/description/789/
 * time: 2024/5/16 18:25:16 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> tmp(n + 1, 0);

    function<void(int, int)> mergeSort = [&](int l, int r) -> void {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        int i = l, j = mid + 1, k = 0;
        while (i <= mid and j <= r) {
            if (a[i] <= a[j]) {
                tmp[k] = a[i];
                k++, i++;
            } else {
                tmp[k] = a[j];
                k++, j++;
            }
        }
        while (i <= mid) {
            tmp[k] = a[i];
            k++, i++;
        }
        while (j <= r) {
            tmp[k] = a[j];
            k++, j++;
        }
        for (i = l, j = 0; i <= r; i++, j++) {
            a[i] = tmp[j];
        }
    };
    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}
/*

*/