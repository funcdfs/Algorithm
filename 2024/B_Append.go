// created: 2024/6/1 12:09:11 author:  https://github.com/funcdfs
// problem: https://atcoder.jp/contests/abc340/tasks/abc340_b

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	Q := 0
	fmt.Fscan(_in, &Q)
	vec := make([]int, 0)
	for tt := 0; tt < Q; tt++ {
		x := 0
		fmt.Fscan(_in, &x)
		if x == 1 {
			a := 0
			fmt.Fscan(_in, &a)
			vec = append(vec, a)
		} else if x == 2 {
			k := 0
			fmt.Fscan(_in, &k)
			fmt.Fprintln(_out, vec[len(vec)-k])
		}
	}
}

func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()

	solve(_in, _out)
	leftData, _ := io.ReadAll(_in)
	if s := strings.TrimSpace(string(leftData)); s != "" {
		panic("!!!!!!!DATA INPUT ERROR!!!!!!! \n\n" + s + "\n")
	}
}
