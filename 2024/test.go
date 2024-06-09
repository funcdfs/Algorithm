package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

var _in *bufio.Reader
var _out *bufio.Writer

// -------------------------------------------------------------






















// -------------------------------------------------------------


func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()

	// compressedString("")

	leftData, _ := io.ReadAll(_in)
	if s := strings.TrimSpace(string(leftData)); s != "" {
		panic("!!!!!!!DATA INPUT ERROR!!!!!!! \n\n" + s + "\n")
	}
}
