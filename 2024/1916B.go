// created: 2024/6/3 22:43:58 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1916/problem/B

package main

import (
	"bufio"
	"fmt"
	"os"
)

// region solve ----------------------------------------------------
func solve(_case int, _in *bufio.Reader, _out *bufio.Writer) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)

	a, b := 0, 0
	fmt.Fscan(_in, &a, &b)
	ans := a * b / Gcd(a, b)
	if ans != b {
		fmt.Fprintln(_out, ans)
	} else {
		k := b / a // a * k == b . a is second large value
		fmt.Fprintln(_out, ans*k)
	}
}

func Gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return Gcd(b, a%b)
}

// endregion solve --------------------------------------------------

func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	// preProcess()
	var testCaseCnt int
	fmt.Fscan(_in, &testCaseCnt)
	for i := 1; i <= testCaseCnt; i++ {
		solve(i, _in, _out)
	}
}

/*
![](https://raw.githubusercontent.com/psychonaut1f/b/main/img21/202406032306431.png)
 */
