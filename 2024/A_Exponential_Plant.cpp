/**
 * name: A - Exponential Plant
 * link: https://atcoder.jp/contests/abc354/tasks/abc354_a
 * time: 2024/5/18 20:00:32 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int H = 0;
    cin >> H;

    int idx = 0;
    int nowSum = 0;
    for (int i = 0; nowSum <= H; i++) {
        idx = i;
        nowSum += (1 << i);
    }

    cout << idx + 1;

    return 0;
}
/*

*/