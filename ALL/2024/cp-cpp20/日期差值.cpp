/**
 * author: https://github.com/funcdfs
 * created: 2024-04-10 12:52:56
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

const int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_add(int year) {
    if (year % 100 && year % 4 == 0 || year % 400 == 0) return 1;
    return 0;
}

int get_month_days(int year, int month) {
    int res = months[month];
    if (month == 2) res += is_add(year);
    return res;
}

int get_total_days(int y, int m, int d) {
    int res = 0;
    for (int i = 1; i < y; i++) res += 365 + is_add(i);
    for (int i = 1; i < m; i++) res += get_month_days(y, i);
    return res + d;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int y1, m1, d1, y2, m2, d2;
    while (scanf("%04d%02d%02d", &y1, &m1, &d1) != -1) {
        scanf("%04d%02d%02d", &y2, &m2, &d2);
        printf(
            "%d\n",
            abs(get_total_days(y1, m1, d1) - get_total_days(y2, m2, d2)) + 1);
    }

    return 0;
}
/*

*/