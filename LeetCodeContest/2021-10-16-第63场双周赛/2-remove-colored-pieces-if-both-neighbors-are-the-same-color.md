[题目链接](https://leetcode-cn.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/)  
[题解链接](https://leetcode-cn.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/solution/lc-fengwei2002-by-kycu-cc9q/)

https://github.com/fengwei2002/algorithm

### Problem B - 如果相邻两个颜色均相同则删除当前颜色

### 思路

一开始我没有发现方法或者说是特征
所以就直接大模拟


``` cpp 
class Solution {
   public:
    bool winnerOfGame(string colors) {
        
        bool ans = false;
        bool alice = false;
        bool bob = false;
        
        while (true) {
            alice = false;
            bob = false;
            
            for (int i = 0; i < colors.size(); i++) {
                alice = false, bob = false;
                if (i >= 2 && colors[i - 1] == 'A' && colors[i - 2] == colors[i - 1] && colors[i - 1] == colors[i]) {
                    colors = colors.substr(0, i - 2) + colors.substr(i - 1);
                    alice = true;
                    break;
                }
            }
            
            for (int i = 0; i < colors.size(); i++) {
                if (i >= 2 && colors[i - 1] == 'B'&& colors[i - 2] == colors[i - 1] && colors[i - 1] == colors[i]) {
                    colors = colors.substr(0, i - 2) + colors.substr(i - 1);
                    bob = true;
                    break;
                }
            }
            
            if (alice == false && bob == true) {
                ans = false;
                break;
            } else if (alice == true && bob == false) {
                ans = true;
                break;
            } else if (alice == false && bob == false) {
                ans = false;
                break;
            } else if (alice == true && bob == true) {
                continue;
            }
        }
        return ans;
    }
};

// alice 先手
```

![20211017122536-2021-10-17-12-25-41](https://raw.githubusercontent.com/fengwei2002/Pictures_02/master/images/20211017122536-2021-10-17-12-25-41.png)

两个人的操作互不影响，所以计算出 Alice 和 Bob 各自最多操作的次数即可。只要它的长度大于等于 3，我们就可以取出一个位置

### 代码

``` cpp
class Solution {
   public:
    bool winnerOfGame(string colors) {
        int cntAlice = 0, cntBob = 0;

        for(int i = 2; i < colors.size(); i++){
            if(colors.substr(i - 2, 3) == "AAA")
                cntAlice++;
            if(colors.substr(i - 2, 3) == "BBB")
                cntBob++;
        }
        return cntAlice > cntBob;
    }
};
```

``` go
func winnerOfGame(colors string) bool {
    cntALice := 0
    cntBob := 0;

    for i := 2; i < len(colors); i++ {
        if colors[i-2 : i+1] == "AAA" {
            cntALice++;
        } else if (colors[i-2 : i+1] == "BBB") {
            cntBob++;
        }
    }

    return cntALice > cntBob
}
```