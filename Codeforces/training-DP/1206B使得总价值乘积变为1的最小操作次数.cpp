// URL: https://codeforces.com/contest/1206/problem/B
// NAME: B. Make Product Equal One, Codeforces - Codeforces Round #580 (Div. 2)
// LIMIT: 256 MB, 5000 ms
// DATE: 2022-08-11 22:45:17

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/

typedef long long LL;
// sum 1e9, so use LL to store 1e19 number

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<LL> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    LL ans = 0;
    LL negaSum = 0, posiSum = 0;
    LL negaCnt = 0, posiCnt = 0, zeroCnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < -1) {
            negaSum += abs(a[i]) - 1;
        } else if (a[i] > 1) {
            posiSum += a[i] - 1;
        }

        if (a[i] < 0) {
            negaCnt++;
        } else if (a[i] == 0) {
            zeroCnt++;
        } else if (a[i] > 0) {
            posiCnt++;
        }
    }

    if ((negaCnt % 2) == 0) {
        ans = negaSum + zeroCnt * 1 + posiSum;
    } else {
        if (zeroCnt) {
            ans++;
            zeroCnt--;
            ans += zeroCnt;
            ans += negaSum + posiSum;
        } else {
            ans += negaSum + posiSum;
            ans += 2;
        }
    }

    cout << ans << endl;

    return 0;
}

/*

1206B使得总价值乘积变为1的最小操作次数

首先所有数字最后都会变为 1 或者 -1

首先将所有的正数变为 1 ，将所有的负数变为 -1
-1，0，1 三种值不变

如果此时的负数的总数为偶数，也就是说明乘积可以为 正数，
    因为 0 变为 1 和 -1 的代价相同，所以这里把 0 全变为 1
    1 不变
    -1 不变
    就是最佳的答案

如果此时的负数的总数是奇数，说明少了一个数字变为 负数，或者说多了一个数字变为
    负数 a 统计负数中的和 1 最接近的值 b 统计 0 和正数中的和 -1 最接近的值 将 a
b 中的更小的一个距离加入答案中即可

    但是他们其实已经都变为了 1 和 -1，两种情况对 ans 的贡献都是将 ans += 2
*/

int main2() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<LL> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    LL ans = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            ans += (-1 - a[i]);
            a[i] = -1;
        } else if (a[i] == 0) {
            ans++;
        } else {
            ans += (a[i] - 1);
            a[i] = 1;
        }
    }

    int s = 1;
    int zeroCnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            s *= a[i];
        } else {
            zeroCnt++;
        }
    }

    if (s == -1 && zeroCnt == 0) {
        ans += 2;
    }
    // 如果乘积是 -1 并且没有可以动手脚的 0，那么就要在 ans 中加 2

    cout << ans << endl;

    return 0;
}