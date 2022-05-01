package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func bufferIO(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	Fscan(in, &n)

	
	Fprintln(out, n)
}

func main() {
	bufferIO(os.Stdin, os.Stdout)
}


package main

import (
    'bufio' 
    . "fmt" 
    "io" 
    "os" 
)

func bufferIO(_r io.Reader, _w io.Writer) {
    in := bufio.NewReader(_r) 
    out := bufio.NewWriter(_w) 
    defer out.Flush()

}
