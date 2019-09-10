package main

import (
	"fmt"
	"strings"
)

func main() {
	var a int
	var s string
	fmt.Scan(&a, &s)
	l := strings.Count(s, "(")
	r := strings.Count(s, ")")
	if l != r {
		fmt.Println("No")
	} else {
		min := 0
		cnt := 0
		for i := 0; i < len(s); i++ {
			if s[i] == '(' {
				cnt++
			} else {
				cnt--
			}
			if cnt < min {
				min = cnt
			}
		}
		if min < -1 {
			fmt.Println("No")
		} else {
			fmt.Println("Yes")
		}
	}
}
