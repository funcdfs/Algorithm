// https://github.com/unknwon/the-way-to-go_ZH_CN/blob/master/eBook/05.5.md
// 和 c++ 没有区别
package main

func main_BreakContinueGrammer() {
	for i := 0; i < 3; i++ {
		for j := 0; j < 10; j++ {
			if j > 5 {
				break
				// continue
			}
			print(j)
		}
		print("  ")
	}
}
