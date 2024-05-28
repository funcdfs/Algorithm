#include <bits/stdc++.h>
using namespace std;

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end()), a.erase(unique(a.begin(), a.end()), a.end());
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}
/*

*/