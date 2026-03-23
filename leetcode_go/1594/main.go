package main

func maxProductPath(grid [][]int) int {
	const MOD int64 = 1e9 + 7
	dp := make([][][2]int, len(grid))
	for i := range dp {
		dp[i] = make([][2]int, len(grid[0]))
	}
	return 1
}
