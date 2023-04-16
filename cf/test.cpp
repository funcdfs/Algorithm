class Solution {
   public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price,
                          vector<vector<int>>& trips) {
        // 构建邻接表
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // 统计所有节点的经过次数
        unordered_map<int, int> count;
        for (const auto& trip : trips) {
            int start = trip[0], end = trip[1];
            count[start]++;
            count[end]++;
            // 统计路径上的所有节点的经过次数
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(start);
            visited[start] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        count[v]++;
                        q.push(v);
                    }
                }
            }
        }

        // 贪心策略：每次找到经过次数最多的节点并减半其价格
        vector<int> copyPrice = price;
        while (!count.empty()) {
            int maxCount = 0, node = -1;
            for (const auto& [n, c] : count) {
                if (c > maxCount) {
                    maxCount = c;
                    node = n;
                }
            }
            if (node == -1) break;
            count.erase(node);
            copyPrice[node] /= 2;
            for (int v : adj[node]) {
                count[v]--;
            }
        }

        // 计算最小价格总和
        int ans = 0;
        for (const auto& trip : trips) {
            int start = trip[0], end = trip[1];
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(start);
            visited[start] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == end) break;
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            int pathPrice = 0;
            int last = start;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                pathPrice += copyPrice[cur];
                last = cur;
            }
            if (last != end) return -1;  // 无法到达终点
            ans += pathPrice;
        }
        return ans;
    }
};