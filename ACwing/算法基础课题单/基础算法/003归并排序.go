package main

import "fmt"

func main() {
	n := 0
	fmt.Scanf("%d", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	tmp := make([]int, n)
	mergeSort(tmp, a, 0, n-1)
	for i := 0; i < n; i++ {
		fmt.Printf("%d ", a[i])
	}
}

func mergeSort(tmp, q []int, l, r int) {
	if l >= r {
		return
	}
	mid := (l + r) >> 1
	mergeSort(tmp, q, l, mid)
	mergeSort(tmp, q, mid+1, r)

	k, i, j := 0, l, mid+1
	for i <= mid && j <= r {
		if q[i] < q[j] {
			tmp[k] = q[i]
			k, i = k+1, i+1
		} else {
			tmp[k] = q[j]
			k, j = k+1, j+1
		}
	}

	for i <= mid {
		tmp[k] = q[i]
		k, i = k+1, i+1
	}
	for j <= r {
		tmp[k] = q[j]
		k, j = k+1, j+1
	}

	for i, j = l, 0; i <= r; i, j = i+1, j+1 {
		q[i] = tmp[j]
	}
}
