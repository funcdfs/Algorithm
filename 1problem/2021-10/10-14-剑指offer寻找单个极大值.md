[题目链接](https://leetcode-cn.com/problems/B1IidL)  
[题解链接](https://leetcode-cn.com/problems/B1IidL/solution/jzoffer-xun-zhao-ji-da-zhi-fengwei2002-b-xyvt/)

https://github.com/fengwei2002/algorithm

### 思路

往常我们使用「二分」进行查值，需要确保序列本身满足「二段性」：当选定一个端点（基准值）后，结合「一段满足 & 另一段不满足」的特性来实现“折半”的查找效果。

但本题求的是峰顶索引值，如果我们选定数组头部或者尾部元素，其实无法根据大小关系“直接”将数组分成两段。

但可以利用题目发现如下性质：由于 arr 数值各不相同，因此峰顶元素左侧必然满足严格单调递增，峰顶元素右侧必然不满足。

因此 以峰顶元素为分割点的 arr 数组，根据与 前一元素/后一元素 的大小关系，具有二段性：

峰顶元素左侧满足 `arr[i-1] < arr[i]` 性质，右侧不满足
峰顶元素右侧满足 `arr[i] > arr[i+1]` 性质，左侧不满足
因此我们可以选择任意条件，写出若干「二分」版本。

如果当前挑选的值，不满足条件，那么答案就在另一侧

### 代码

``` cpp
// https://github.com/fengwei2002/algorithm

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // 找出数组中的极大值点
        int ans = 0;
        // 二分查找
        int l = 1, r = arr.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (arr[mid - 1] < arr[mid]) l = mid; // mid 左侧的元素可以省略
            else r = mid - 1;
        }
        ans = r;

        return ans;
    }
};
```