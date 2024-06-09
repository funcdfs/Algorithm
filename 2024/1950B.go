// created: 2024/5/31 15:41:10 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1950/problem/B

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
	for i := 0; i < 2*n; i++ {
		for j := 0; j < 2*n; j++ {
			if (i/2^j/2)&1 > 0 {
				fmt.Fprint(_out, ".")
			} else {
				fmt.Fprint(_out, "#")
			}
		}
		fmt.Fprintln(_out)
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
