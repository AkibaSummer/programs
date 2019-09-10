package main

import (
	"fmt"
)

func main() {
	var n, d, e int
	fmt.Scan(&n, &d, &e)
	ans := 1 << 30
	for i := 0; i <= n; i = i + e*5 {
		nn := (n - i) % d
		if nn < ans {
			ans = nn
		}
	}
	fmt.Println(ans)
}
