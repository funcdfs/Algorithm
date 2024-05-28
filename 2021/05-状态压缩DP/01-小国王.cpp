#include <iostream>
#include <algorithm> 
#include <cstring>
#include <vector>

using namespace std; 

const int N = 12, M = 1 << 10, K = 110; 

int n, m; 
vector<int> state; // 存储每一个状态
int id[M]; // 存储每一个状态和下标的映射关系 
vector<int> head[M]; // 每一个状态可以转移到的其他的状态
int cnt[M]; // 每一个状态里面 1 的个数 

int64_t f[N][K][M]; 

// check 如果存在两个连续的 1 说明当前的这个 state 就是不合法的
bool check(int state) {
    for (int i = 0; i < n; i++) {
        if (((state >> i) & 1) && ((state >> (i + 1)) & 1)) {
            return false; 
        }
    }
    return true; 
}

int count(int state) {
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        ans += (state >> i) & 1; 
    } 
    return ans; 
}

int main() {
    cin >> n >> m; 

    for (int i = 0; i < 1 << n; i++) {
        if (check(i)) {
            state.push_back(i); 
            id[i] = state.size() - 1; 
            cnt[i] = count(i); 
        }
    }

    for (int i = 0; i < (int)state.size(); i++) {
        for (int j = 0; j < (int)state.size(); j++) {
            int a = state[i], b = state[j]; 
            if ((a & b) == 0 && check(a | b)) {
                head[i].push_back(j); 
            }
        }
    }

    f[0][0][0] = 1; 
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= m; j++) {
            for (int a = 0; a < (int)state.size(); a++) {
                for (int b : head[a]) {
                    int c = cnt[state[a]]; 
                    if (j >= c) {
                        f[i][j][a] += f[i - 1][j - c][b]; 
                    } 
                }
            }
        }
    }

    cout << f[n + 1][m][0] << '\n'; 

    return 0; 
}