// created: 2024/6/1 12:26:37 author:  https://github.com/funcdfs
// problem: https://www.luogu.com.cn/problem/AT_abc340_d

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	N := 0
	fmt.Fscan(_in, &N)
	X, A, B := make([]int, N-1), make([]int, N-1), make([]int, N-1)
	for i := 0; i < N-1; i++ {
		fmt.Fscan(_in, &X[i], &A[i], &B[i])
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
