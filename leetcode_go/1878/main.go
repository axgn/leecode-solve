package main

func getBiggestThree(grid [][]int) []int {
	row := len(grid)
	col := len(grid[0])
	diagonalAC := make([][]int, row+1)
	diagonalBD := make([][]int, row+1)
	for i := 0; i <= row; i++ {
		diagonalAC[i] = make([]int, col+1)
		diagonalBD[i] = make([]int, col+1)
	}

	for i, v := range grid {
		for j, v2 := range v {
			diagonalAC[i+1][j+1] = diagonalAC[i][j] + v2
			diagonalBD[i+1][j] = diagonalBD[i][j+1] + v2
		}
	}
	queryDiagonalAC := func(x, y, k int) int { return diagonalAC[x+k][y+k] - diagonalAC[x][y] }
	queryDiagonalBD := func(x, y, k int) int { return diagonalBD[x+k][y+1-k] - diagonalBD[x][y+1] }
	var x, y, z int
	update := func(v int) {
		if v > x {
			x, y, z = v, x, y
		} else if v < x && v > y {
			y, z = v, y
		} else if v < y && v > z {
			z = v
		}
	}

	for i, v := range grid {
		for j, v2 := range v {
			update(v2)
			mx := min(i, row-1-i, j, col-1-j)
			for k := 1; k <= mx; k++ {
				a := queryDiagonalAC(i-k, j, k)
				b := queryDiagonalAC(i, j-k, k)
				c := queryDiagonalBD(i-k+1, j-1, k-1)
				d := queryDiagonalBD(i, j+k, k+1)
				update(a + b + c + d)
			}
		}
	}

	ans := []int{x, y, z}
	for ans[len(ans)-1] == 0 {
		ans = ans[:len(ans)-1]
	}
	return ans
}

func main() {

}
