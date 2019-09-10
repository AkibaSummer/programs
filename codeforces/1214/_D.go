package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	stdin := os.Stdin
	reader := bufio.NewReaderSize(stdin, 1024*1024)
	var n, m int
	// fmt.Scan(&n, &m)
	fmt.Fscanf(reader, "%d%d\n", &n, &m)
	maps := make([][]byte, n)
	for i := 0; i < n; i++ {
		maps[i] = make([]byte, m)
		fmt.Fscanf(reader, "%s\n", &maps[i])
		// fmt.Scan(&maps[i])
	}
	maps[n-1][m-1] = '0'
	for i := n - 1; i >= 0; i-- {
		for j := m - 1; j >= 0; j-- {
			if i != n-1 && maps[i][j] != '#' && maps[i+1][j] == '0' {
				maps[i][j] = '0'
			}

			if j != m-1 && maps[i][j] != '#' && maps[i][j+1] == '0' {
				maps[i][j] = '0'
			}
		}
	}
	dp := make([][]float64, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]float64, m)
	}
	dp[0][0] = 100000
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if maps[i][j] != '0' {
				continue
			}
			if i == n-1 && j == m-1 {
				continue
			}
			// fmt.Println(dp)
			if i == n-1 || maps[i+1][j] != '0' {
				dp[i][j+1] += dp[i][j]
			} else if j == m-1 || maps[i][j+1] != '0' {
				dp[i+1][j] += dp[i][j]
			} else {
				dp[i+1][j] += dp[i][j] / 2
				dp[i][j+1] += dp[i][j] / 2
			}
		}
	}
	flag := false
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if i == 0 && j == 0 {
				continue
			}
			if i == n-1 && j == m-1 {
				continue
			}
			if math.Abs(dp[i][j]-100000) < 1e-10 {
				flag = true
			}
		}
	}
	// fmt.Println(dp)
	if maps[0][0] != '0' {
		fmt.Println(0)
	} else if flag {
		fmt.Println(1)
	} else {
		fmt.Println(2)
	}
}
