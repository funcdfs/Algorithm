[题目链接](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)  
[题解链接](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/jz04-fengwei2002-by-kycu-i6im/)

https://github.com/fengwei2002/algorithm

### 思路

考察 target 大于某一行的起始位置并且 target 小于这一行的结束位置
那么 target 就会在这一行的数据中有可能出现

时间复杂度由 $O(n^2)$ 变为了 $O(n)$

### 代码

``` cpp
// https://github.com/fengwei2002/algorithm

class Solution {
   public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        bool ans = false;
        if (matrix.size() == 0 || matrix.at(0).size() == 0) return ans;
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][m - 1]) {
                for (int j = 0; j < m; j++) {
                    if (target == matrix[i][j]) {
                        ans = true;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
```


``` go
func findNumberIn2DArray(matrix [][]int, target int) bool {
    ans := false
    if len(matrix) == 0 || len(matrix[0]) == 0  {
        return ans
    }
    n := len(matrix)
    m := len(matrix[0])
    
    for i := 0; i < n; i++ {
        if target <= matrix[i][m - 1] && target >= matrix[i][0] {
            for j := 0; j < m; j++ {
                if matrix[i][j] == target {
                    ans = true
                    break;
                }
            }
        } 
    }
    return ans;
}
```