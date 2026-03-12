package main

func numberOfStableArrays(zero int, one int, limit int) int {
	const MOD int64 = 1e9 + 7
	dp := make([][][2]int64, zero+1)
	for i := range dp {
		dp[i] = make([][2]int64, one+1)
	}
	for i := 1; i < zero+1; i++ {
		if i <= limit {
			dp[i][0][0] = 1
		}
	}
	for i := 1; i < one+1; i++ {
		if i <= limit {
			dp[0][i][1] = 1
		}
	}
	for i := 1; i < zero+1; i++ {
		for j := 1; j < one+1; j++ {
			temp1 := i - limit - 1
			if temp1 >= 0 {
				dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] + (MOD - dp[temp1][j][1])) % MOD
			} else {
				dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD
			}
			temp1 = j - limit - 1
			if temp1 >= 0 {
				dp[i][j][1] = (dp[i][j-1][1] + dp[i][j-1][0] + (MOD - dp[i][temp1][0])) % MOD
			} else {
				dp[i][j][1] = (dp[i][j-1][1] + dp[i][j-1][0]) % MOD
			}
		}
	}
	return int((dp[zero][one][0] + dp[zero][one][1]) % MOD)
}

func main() {

}
