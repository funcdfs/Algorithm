#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt = 0;
    cin >> tt;
    vector<string> ans;
    ans.reserve(95);
    unordered_map<int, bool> col, ltor, rtol; 
    string path; 
    const int N = 8; 
    function<void(int)> dfs = [&](int row) -> void {
        if (row == 8) {
            ans.push_back(path);
            return; 
        }
        for (int i = 0; i < N; i++) {
            if (col[i] == false and ltor[row-i] == false and rtol[row+i] == false) {
                path.push_back(char(i+1)+char('0'));
                col[i] = ltor[row-i] = rtol[row+i] = true;
                dfs(row+1);
                col[i] = ltor[row-i] = rtol[row+i] = false;
                path.pop_back();
            }
        }
        return;
    };
    dfs(0);
    while (tt--) {
        int n = 0;
        cin >> n;
        n -= 1;
        cout << ans[n] << endl;
    }
    return 0; 
}