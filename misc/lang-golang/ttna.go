// #region main
package main; import ("bufio"; "fmt"; "os";); var _in, _out = new(bufio.Reader), new(bufio.Writer);
func main() { _in = bufio.NewReader(os.Stdin); _out = bufio.NewWriter(os.Stdout); defer _out.Flush(); testCaseCnt := input[int](); for i := 0; i < testCaseCnt; i++ { solve(i + 1); } }
func input[T any]() T { var value T; fmt.Fscan(_in, &value); return value }; func println[T any](x ...T) { print(" ", "\n", x...) };
func inputSlice[T any](length int) []T { data := make([]T, length); for i := 0; i < length; i++ { data[i] = input[T](); }; return data; }
func print[T any](sep, end string, x ...T) { for i := range x { fmt.Fprint(_out, x[i]); if i == len(x)-1 { fmt.Fprint(_out, end); } else { fmt.Fprint(_out, sep); } } }
// #endregion main

// ---------------------------------------------------------------

func solve(_case int) {

	n := input[int]()
	a := inputSlice[int](n) 
	
	
}

// ---------------------------------------------------------------