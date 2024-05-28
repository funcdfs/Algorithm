#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int head[N], e[N], ne[N], idx;
// 领接表 

int d[N], q[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = head[a];
    head[a] = idx++;
}


// 每个点对应一个初始化为 -1 的距离，
int bfs() {
    int hh = 0, tt = 0;      // 定义队列 head 的位置和 队列尾的位置
    q[0] = 1;                // 第一个起点是位置 1
    
    memset(d, -1, sizeof d); // -1 表示没有被遍历过 
    d[1] = 0;                // 最开始的时候只有 1 这个点被遍历过，初始化为 0
    
    while (hh <= tt) {       // 当队列不为空的时候
        int t = q[hh++];     // 每一次取得队头元素
        
        for (int i = head[t]; i != -1; i = ne[i]) { // 遍历这个元素的所有出边
            int j = e[i];                           // 将出边的每一个值分别赋值给 j
            if (d[j] == -1) {                       // 如果某个出边的距离是 -1
                d[j] = d[t] + 1;                    // 就将这个距离更新为 d[t] + 1
                q[++tt] = j;                        // 然后把这个出边，放入队列中
            }
        }
    }
    
    return d[n]; // 如果不存在 1 到 n 的出边，输出 -1，否则输出 1 到 n 的距离
}


int main() {
    cin >> n >> m;

    memset(head, -1, sizeof head);    
    
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        add(a, b);
    }
    
    cout << bfs() << endl;
    
    return 0;
}