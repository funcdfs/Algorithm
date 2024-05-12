void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    auto check = [&](int a) -> bool {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] < a) {
                res += a - v[i];
            }
            check
        }
        return res <= x;
        func
    };
checkkkkkkkkkkk
    int l = 0, r = 1e10;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else
            r = mid - 1;
    }
    cout << l << endl;
}