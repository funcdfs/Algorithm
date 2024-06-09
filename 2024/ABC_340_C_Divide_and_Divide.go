// created: 2024/6/1 12:15:34 author:  https://github.com/funcdfs
// problem: https://www.luogu.com.cn/problem/AT_abc340_c

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	N := int64(0)
	fmt.Fscan(_in, &N)
	hs := make(map[int64]int64)
	
	var dfs func(int64) int64
	dfs = func(x int64) int64 {
		if x < 2 {
			return 0
		}
		if val, ok := hs[x]; ok == true {
			return val
		}
		t := dfs(x/2) + dfs((x+1)/2) + x
		hs[x] = t
		return t
	}
	ans := dfs(N)
	fmt.Fprintln(_out, ans)
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
