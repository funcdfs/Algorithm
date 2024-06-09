// created: 2024/6/1 12:06:55 author:  https://github.com/funcdfs
// problem: https://atcoder.jp/contests/abc340/tasks/abc340_a

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	A, B, D := 0, 0, 0
	fmt.Fscan(_in, &A, &B, &D)
	for i := A; i <= B; i += D {
		fmt.Fprint(_out, i, " ")
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
