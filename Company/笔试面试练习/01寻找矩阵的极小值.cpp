
class Solution {
public:
    // query(a, b) ==> matrix[a][b]
    vector<int> getMinimumValue(int n) {
        // 在 nlogn 时间复杂度内找出任意一个极小值的位置，输出他在第几行的第几列
        typedef long long LL; 
        const int INF = 0x3f3f3f3f; 
        
        int l = 0; 
        int r = n - 1; 
        
        while (l < r) {
            int mid = (l + r) >> 1; 
            // 找到中间列 
            
            int minValueRow = 0; 
            int minValue = INF; 
            
            // 这里必须找最小值而不是极小值，保证这堵墙密不可分
            for (int i = 0; i < n; i++) { 
                int t = query(i, mid); // matrix[i][mid]; 
                if (t < minValue) {
                    minValue = t; 
                    minValueRow = i; 
                }
            }
            
            // 找出 mid 的左右两个 value 
            LL leftValue = (mid > 0) ? query(minValueRow, mid - 1) : INF; 
            LL rightValue = (mid <= n - 1) ? query(minValueRow, mid + 1): INF; 
            
            if (minValue < leftValue && minValue < rightValue) return {minValueRow, mid};
            if (leftValue < minValue) r = mid - 1; 
            else l = mid + 1; 
        }
        
        // l == r 只剩下最后一列数据了 直接遍历找到最小的元素即可 
        int minValueRow = 0; 
        LL minValue = INF; 
        for (int i = 0; i < n; i++) {
            int t = query(i, r); 
            if (t < minValue) {
                minValue = t; 
                minValueRow = i; 
            }
        }
        
        return {minValueRow, r};
    }
};