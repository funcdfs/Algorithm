// created: 2024/5/31 11:43:52 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1407/problem/B

package main

import (
	"bufio"
	"fmt"
	"os"
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
	pre := 0
	ans := make([]int, 0)
	for len(a) > 0 {
		maxIdx := 0
		for i, x := range a {
			if Gcd(pre, x) > Gcd(pre, a[maxIdx]) {
				maxIdx = i
			}
		}
		pre = Gcd(pre, a[maxIdx])
		ans = append(ans, a[maxIdx])
		a = append(a[:maxIdx], a[maxIdx+1:]...)
	}
	for i := range ans {
		fmt.Fprint(_out, ans[i], " ")
	}
	fmt.Fprintln(_out)

}

// --------------------------------------------------------------------------
// endregion solve
func Gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return Gcd(b, a%b)
}
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
}

// endregion main
