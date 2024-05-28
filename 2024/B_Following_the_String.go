package main

import (
	"bufio"
	"fmt"
	"os"
)

var _in *bufio.Reader
var _out *bufio.Writer

func solve() {
	
}

func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	TT := 0
	fmt.Fscan(_in, &TT)
	for ; TT > 0; TT-- {
		solve()
	}
}

func max(nums ...int) int {
	maxNum := nums[0]
	for _, num := range nums {
		if num > maxNum {
			maxNum = num
		}
	}
	return maxNum
}
func min(nums ...int) int {
	minVal := nums[0]
	for _, num := range nums {
		if num > minVal {
			minVal = num
		}
	}
	return minVal
}

