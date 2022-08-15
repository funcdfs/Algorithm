// Problem: 动态网格
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/645/
// date: 2022-04-21 19:38:35
// Memory Limit: 64 MB
// Time Limit:   2000 ms


// #define d(a)  // https://github.com/fengwei2002/Algorithm
// #define dline // konng0120@gmail.com
// #define dendl // 

#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define INF 0x3f3f3f3f

#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 0; 
    cin >> t; 
    
    for (int loop = 0; loop < t; loop++) {
        int r = 0, c = 0; 
        cin >> r >> c; 
        vector<vector<int>> a(r, vector<int>(c, 0)); 
        
        for (int i = 0; i < r; i++) {
            string line = "";
            cin >> line; 
            for (int j = 0; j < c; j++) {
                a[i][j] = line[j]; 
            }
        }
        
        int n = 0; 
        cin >> n; // 读入操作数量 
        
        cout << "Case #" << loop + 1 << ": " << endl; 
        
        for (int i = 0; i < n; i++) {
            string oper; 
            cin >> oper; 
            if (oper == "Q") {
                // 输出 1 四方向连通区域的数量    
                             
            } else if (oper == "M") {
                int x = 0, y = 0, z = 0; 
                cin >> x >> y >> z; 
                // 将第 x 行第 y 列方格内的值变为 z 
                a[x][y] = z; 
            }
        }
        
    }
    
    return 0;
}