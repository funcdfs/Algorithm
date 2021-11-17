#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> get_divisors(int x) {
    vector<int> ans;

    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            ans.push_back(i);
            if (i != x / i) ans.push_back(x / i);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        auto ans = get_divisors(x);
        for (auto x : ans) cout << x << ' ';
        cout << endl;
    }
    return 0;
}

// 倍数的反义词，就叫做约数
// O(sqrt(n))