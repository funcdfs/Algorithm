package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	s := ""
	fmt.Fscan(_in, &s)
	hs := make(map[byte]int)
	cnt := 0
	for i := 0; i < len(s); i++ {
		hs[s[i]] += 1
		if hs[s[i]] == 2 {
			cnt += 2
			for k := range hs {
				delete(hs, k)
			}
		}
	}
	fmt.Fprintln(_out, len(s)-cnt)
}

func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()

	var TT int
	for fmt.Fscan(_in, &TT); TT > 0; TT-- {
		solve(_in, _out)
	}
}
