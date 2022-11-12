#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

const int N = 110, M = 11, S = 1 << M; 

int n, m; 
int g[N]; // 存储每一行的状态 
int f[2][S][S]; 
vector<int> state; 
int cnt[S]; 

bool check(int s) {
    for (int i = 0; i < m; i++) {
        if ((s >> i & 1) && ((s >> i + 1 & 1) | (s >> i + 2 & 1))) {
            return false; 
        }
    }
    return true; 
}

int count(int s) {
    int ans = 0; 
    while (s) {
        ans += s & 1; 
        s >>= 1; 
    } 
    return ans; 
}

int main() {
    cin >> n >> m; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; 
            cin >> c; 
            if (c == 'H') g[i] += 1 << j; 
        }
    }

    for (int i = 0; i < 1 << m; i++) {
        if (check(i)) {
            state.push_back(i);
            cnt[i] = count(i); 
        }
    }


    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < (int)state.size(); j++) {
            for (int k = 0; k < (int)state.size(); k++) {
                for (int u = 0; u < (int)state.size(); u++) {
                    int a = state[u]; 
                    int b = state[j]; 
                    int c = state[k]; 
                    if ((a & b) || (a & c) || (b & c)) continue; 
                    if (g[i] & c) continue; 
                    f[i & 1][j][k] = min(f[i & 1][j][k], f[(i - 1) & 1][u][j] + cnt[c]); 
                }
            }
        }
    }

    cout << f[n + 1 & 1][0][0] << '\n'; 

    return 0; 
}