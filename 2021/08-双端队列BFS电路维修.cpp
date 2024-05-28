// LINK: https://www.acwing.com/problem/content/177/
// NAME: 电路维修, AcWing
// DATE: 2022-08-22 12:46:46, LIMIT: 64 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

// 从左上角的方块开始顺时针考虑四个线路
const int dx[4] = {-1, -1, 1, 1}; 
const int dy[4] = {-1, 1, 1, -1}; // 这个点对应的四个结尾点的坐标

const int ix[4] = {-1, -1, 0, 0}; 
const int iy[4] = {-1, 0, 0, -1}; // 四个结尾点对应的读入字符的下标

char cs[5] = "\\/\\/"; // 转义，左上，右上，右下，左下 

const int N = 510, M = N * N; 
int dist[N][N]; 
bool st[N][N]; 

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        int n = 0, m = 0; 
        cin >> n >> m; 
        vector<vector<char>> g(n, vector<char>(m, ' ')); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j]; 
            }
        }
        
        
        function<int()> bfs = [&]() -> int {
            deque<pair<int, int>> que; 
            memset(dist, 0x3f, sizeof dist); 
            memset(st, 0, sizeof st); 
            
            que.push_back({0, 0}); 
            dist[0][0] = 0; 
            
            while (que.size()) {
                auto [x, y] = que.front(); 
                dbg(x, y); 
                que.pop_front(); 
                if (x == n && y == m) return dist[x][y]; 
                
                if (st[x][y]) continue; 
                st[x][y] = true; 
                
                for (int i = 0; i < 4; i++) {
                    int a = x + dx[i]; 
                    int b = y + dy[i]; 
                    
                    if (a < 0 || a > n || b < 0 || b > m) continue; 
                    int ga = x + ix[i]; 
                    int gb = y + iy[i]; // 这个方向的字符在 g 中的下标
                    int w = (g[ga][gb] != cs[i]); 
                    int d = dist[x][y] + w; 
                    // 和预测字符相同的话，边权为 0, 距离不需要加 1 
                    
                    if (d <= dist[a][b]) {
                        dist[a][b] = d; 
                        if (w == 0) {
                            que.push_front({a, b}); 
                        } else {
                            que.push_back({a, b}); 
                        }
                    }
                }
            }
            return -1; 
        };
        
        
        if ((n + m) & 1) {
            /*
            算一下每一个点的横纵坐标之和
            每次的移动一定是按照斜线走的 
            如果当前的横纵坐标之和是偶数，
            那么他走到的点的横纵坐标之和也是偶数（1 + 1 + 偶数）
                所以，如果横纵坐标之和是奇数就一定到不了
            */
            cout << "NO SOLUTION" << "\n"; 
        } else {
            cout << bfs() << "\n"; 
        }
    }
    
    
    
    return 0;
}


/*

等价于在无向图中给定两种类型的边 

一种边的权重是 0 （直达不需要旋转的）
另一种边的权重是 1 （反对角线的，需要进行一次旋转的操作）

求在这样的一个图上的起点到终点的距离最短是多少 

多了一种边权为 0 的边

dijkstra: 只要边权都是正数，就是正确的


可以发现有一些点一定到达不了
    图中有一半的点永远不可以到达 
    反对角线，相隔一个，线上的点都不可以直接到达
    （一个边在最终的状态下只存在一种旋转的形态）
    
做法：
    使用双端队列
    一般的宽搜: 
        从队列取出来队头之后，把所有能从队头扩展到的元素放到队尾
    双端队列宽搜： 
        根据扩展出来的这个边的权重是 0 还是 1 分成两种情况
        如果扩展出来的权重是 0 就放到队头
        如果是 1 就放到队尾 
        
        其他的步骤和一般的宽搜步骤完全相同
    
    因为每一次取出队头的时候，都是距离最近的点，所以和 dijkstra 相同
    所以正确


*/