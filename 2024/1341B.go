package main

import "fmt"

func solve() {
	n, k := 0, 0
	fmt.Scan(&n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sum := make([]int, n+1)
	for i := 1; i+1 < n; i++ {
		sum[i+1] = sum[i]
		if a[i-1] < a[i] && a[i] > a[i+1] {
			sum[i+1]++
		}
	}
	sum[n] = sum[n-1]
	ans, left := 0, 0
	for i := 0; i+k <= n; i++ {
		s := sum[i+k] - sum[i]
		if sum[i+1] > sum[i] {
			s -= 1
		}
		if sum[i+k] > sum[i+k-1] {
			s -= 1
		}
		if s > ans {
			ans = s
			left = i
		}
	}
	fmt.Println(ans+1, left+1)
	return
}

func main() {
	TT := 0
	fmt.Scan(&TT)
	for TT > 0 {
		solve()
		TT--
	}
	return
}
