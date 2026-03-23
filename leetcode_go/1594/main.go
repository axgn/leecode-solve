package main

func maxProductPath(grid [][]int) int {
	const MOD int64 = 1e9 + 7
	m, n := len(grid), len(grid[0])
	dp := make([][][2]int, m)
	for i := range dp {
		dp[i] = make([][2]int, n)
	}
	dp[0][0] = [2]int{grid[0][0], grid[0][0]}
	for i := 1; i < m; i++ {
		temp := grid[i][0]
		mn := dp[i-1][0][0]
		mx := dp[i-1][0][1]
		a, b := mn*temp, mx*temp
		dp[i][0] = [2]int{min(a, b), max(a, b)}
	}
	for j := 1; j < n; j++ {
		temp := grid[0][j]
		mn := dp[0][j-1][0]
		mx := dp[0][j-1][1]
		a, b := mn*temp, mx*temp
		dp[0][j] = [2]int{min(a, b), max(a, b)}
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			temp := grid[i][j]
			mn := dp[i][j-1][0]
			mx := dp[i][j-1][1]
			mn2 := dp[i-1][j][0]
			mx2 := dp[i-1][j][1]
			a, b, c, d := mn*temp, mx*temp, mn2*temp, mx2*temp
			dp[i][j] = [2]int{min(a, b, c, d), max(a, b, c, d)}
		}
	}
	ans := dp[m-1][n-1][1]
	if ans < 0 {
		return -1
	}
	return ans % int(MOD)
}
