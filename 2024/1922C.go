// created: 2024/6/1 12:38:52 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1922/problem/C

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

// region solve
// --------------------------------------------------------------------------
func solve(_case int, _in *bufio.Reader, _out *bufio.Writer) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)
	n := 0
	fmt.Fscan(_in, &n)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(_in, &a[i])
	}

	l, r := make([]int, n), make([]int, n)
	for i := 1; i < n; i++ {
		if i == n-1 || a[i+1]-a[i] > a[i]-a[i-1] {
			l[i] = l[i-1] + 1
		} else {
			l[i] = l[i-1] + a[i] - a[i-1]
		}
	}
	r[n-1] = 0 // from left to right 
	for i := n - 2; i >= 0; i-- {
		if i == 0 || a[i]-a[i-1] > a[i+1]-a[i] {
			r[i] = r[i+1] + 1
		} else {
			r[i] = r[i+1] + a[i+1] - a[i]
		}
	}

	m := 0
	fmt.Fscan(_in, &m)
	for query := 0; query < m; query += 1 {
		x, y := 0, 0
		fmt.Fscan(_in, &x, &y)
		// calc money from x to y
		x, y = x-1, y-1
		ans := 0
		if x < y {
			ans = r[x] - r[y]
		} else {
			ans = l[x] - l[y]
		}
		fmt.Fprintln(_out, ans)
	}
}

// --------------------------------------------------------------------------
// endregion solve

func preProcess() {

}

// region main
func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	preProcess()
	var testCaseCnt int
	fmt.Fscan(_in, &testCaseCnt)
	for i := 1; i <= testCaseCnt; i++ {
		solve(i, _in, _out)
	}
	leftData, _ := io.ReadAll(_in)
	if s := strings.TrimSpace(string(leftData)); s != "" {
		panic("!!!!!!!DATA INPUT ERROR!!!!!!! \n\n" + s + "\n")
	}
}

// endregion main

/*
### [1922C - 最接近的城市](/contest/1922/problem/C "教育准则第 161 轮（评定为第 2 组）")

重要提示：如果只允许移动到相邻的城市，答案不会改变。答案是正确的，因为如果你移动到一个不相邻的城市，你可以在不增加成本的情况下将通往该城市的路径分成几部分。因此，从 $x$ 到 $y$ 的最短路径（考虑 $x &lt; y$ 的情况）是：从城市 $x$ 移动到城市 $x+1$ ，如果可能的话，需要花费 $1$ 个硬币；如果不可能，则需要花费 $a_{x+1} - a_x$ 个硬币。然后从城市 $x+1$ 到城市 $x+2$ ，如果可能，换取 $1$ 枚硬币；如果不可能，换取 $a_{x+2} - a_{x+1}$ 枚硬币。以此类推，直到我们到达城市 $y$ 。

现在我们来计算两个数组： $l$ 和 $r$ 。 $r_i$ 等于从城市 $1$ （从左到右）到达城市 $i$ 所需的最少金币数， $l_i$ 等于从城市 $n$ （从右到左）到达城市 $i$ 所需的最少金币数。这两个数组都可以预先计算，就像计算前缀和数组一样。例如， $r_1 = 0$ 、 $r_2 = dist(1, 2)$ 、 $r_3 = r_2 + dist(2, 3)$ 、 $r_4 = r_3 + dist(3, 4)$ 等。这里， $dist(s, t)$ 表示两个相邻城市 $s$ 和 $t$ 之间最便宜的旅行方式。

那么，两个城市 $x$ 和 $y$ 之间最便宜的交通方式的计算方法与计算前缀和数组的子数组上的和的方法相同。有两种情况

- 如果是 $x &lt; y$ ，那么答案就是 $r_y - r_x$ ；
- 如果为 $x &gt; y$ ，则答案为 $l_y - l_x$ ；
*/
