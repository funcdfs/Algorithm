#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> path;
    vector<bool> st(n, false);

    function<void()> dfs = [&]() {
        if (path.size() >= n) {
            if (path.size() == n) {
                for (auto x : path) {
                    cout << x << ' ';
                }
                cout << endl;
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (st[i] == false) {
                if (i > 0 && a[i] == a[i - 1] && st[i - 1] == false) {
                    continue;
                }
                path.push_back(a[i]);
                st[i] = true;
                dfs();
                path.pop_back();
                st[i] = false;
            }
        }
    };

    dfs();

    return 0;
}