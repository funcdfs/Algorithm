#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> 

using namespace std; 

struct edge {
    int a, b, w; 
}; 

int main() {
    int n = 0, m = 0, k = 0; 
    cin >> n >> m >> k; 
    vector<edge> edges(m); 
    
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0, c = 0; 
        cin >> a >> b >> c; 
        edges[i] = {a, b, c}; 
    }
    vector<int> dist(n + 1, 1e9); 
    vector<int> backUp(n + 1, 0); 
    
    function<void()> bellmanFord = [&]() {
        dist[1] = 0; 
        for (int i = 0; i < k; i++) {
            backUp = dist; 
            for (int j = 0; j < m; j++) {
                auto e = edges[j]; 
                dist[e.b] = min(dist[e.b], backUp[e.a] + e.w); 
            }
        }
    };
    
    bellmanFord(); 
    if (dist[n] > 1e9 / 2) {
        cout << "impossible" << '\n'; 
    } else {
        cout << dist[n] << '\n'; 
    } 
    return 0; 
}