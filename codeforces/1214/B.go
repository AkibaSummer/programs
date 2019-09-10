package main

import "fmt"

func main() {
	var a, b, n int
	fmt.Scan(&a, &b, &n)
	var ans int
	for i := 0; i <= n; i++ {
		if i <= a && (n-i) <= b {
			ans++
		}
	}
	fmt.Println(ans)
}
