package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	for i := 2; i < n; i++ {
		if n%i == 0 {
			fmt.Printf("%d%d\n", i, n/i)
			return
		}
	}
}
