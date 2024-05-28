#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 14, M = 1 << 12, mod = 1e8;

int n, m;
int w[N];
vector<int> state;
vector<int> head[M];
int f[N][M];

bool check(int state) {
    for (int i = 0; i + 1 < m; i++)
        if ((state >> i & 1) && (state >> i + 1 & 1)) return false;
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            w[i] += !t * (1 << j);
        }

    for (int i = 0; i < 1 << m; i++)
        if (check(i)) state.push_back(i);

    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++) {
            int a = state[i], b = state[j];
            if (!(a & b)) head[i].push_back(j);
        }

    f[0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j < state.size(); j++)
            if (!(state[j] & w[i]))
                for (int k : head[j]) f[i][j] = (f[i][j] + f[i - 1][k]) % mod;

    cout << f[n + 1][0] << endl;

    return 0;
}