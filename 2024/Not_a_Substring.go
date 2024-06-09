// created: 2024/6/3 23:11:49 author:  https://github.com/funcdfs
// problem: https://vjudge.net/problem/CodeForces-1860A#author=GPT_zh

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// region solve ----------------------------------------------------
func solve(_case int, _in *bufio.Reader, _out *bufio.Writer) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)

	ss := ""
	fmt.Fscan(_in, &ss)
	s := []byte(ss)

	check := func() bool {
		if ss == "()" {
			return false
		}
		fmt.Fprintln(_out, "YES")
		alt := true
		for i := 1; i < len(s); i++ {
			if s[i] == s[i-1] {
				alt = false
			}
		}
		ans := make([]byte, 2*len(s))
		if alt == true {
			ans = append([]byte(strings.Repeat("(", len(s))), []byte(strings.Repeat(")", len(s)))...)
			fmt.Fprintln(_out, string(ans))
		} else {
			ans = []byte(strings.Repeat("()", len(s)))
			fmt.Fprintln(_out, string(ans))
		}
		return true
	}
	if check() == true {
	} else {
		fmt.Fprintln(_out, "NO")
	}

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

 */
