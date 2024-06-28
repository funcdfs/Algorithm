// #region import
package main
import ( "bufio"; "fmt"; "log"; "os"; )
// #endregion import

// solve -------------------------------------------------------------

func solve() {
	
	s := scan[[]byte]()
	ans := make([]byte, 0, len(s))
	for i := 0; i < len(s); i++ {
		if s[i] == '|' {
			i += 1
			for s[i] != '|' {
				i += 1
			}
		} else {
			ans = append(ans, s[i])
		}
	}
	println(string(ans))

}

// solve -------------------------------------------------------------

// #region main
func main() { _in = bufio.NewReader(os.Stdin); _out = bufio.NewWriter(os.Stdout); defer _out.Flush(); log.SetFlags(log.Lshortfile); solve(); }
var _in, _out = new(bufio.Reader), new(bufio.Writer)
func scan[T any]() T { var value T; fmt.Fscan(_in, &value); return value; }
func scanSlice[T any](length int) []T { data := make([]T, length); for i := 0; i < length; i++ { data[i] = scan[T](); }; return data }
func print[T any](sep, end string, x ...T) { for i := range x { fmt.Fprint(_out, x[i]);  if i == len(x)-1 { fmt.Fprint(_out, end); } else { fmt.Fprint(_out, sep); } } }
func println[T any](x ...T) { print(" ", "\n", x...); }
// #endregion main
