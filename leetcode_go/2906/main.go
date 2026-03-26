package main

func constructProductMatrix(grid [][]int) [][]int {
	const MOD int = 12345
	n, m := len(grid), len(grid[0])
	p := make([][]int, n)
	pre := 1
	for i, row := range grid {
		p[i] = make([]int, m)
		for j, x := range row {
			p[i][j] = pre
			pre = (pre * x) % MOD
		}
	}
	post := 1
	for i := n - 1; i >= 0; i-- {
		for j := m - 1; j >= 0; j-- {
			p[i][j] = (p[i][j] * post) % MOD
			post = (post * grid[i][j]) % MOD
		}
	}
	return p
}
