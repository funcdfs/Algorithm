package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	$0
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