package main

func Rotation90(x int, y int, n int) (newx int, newy int) {
	c := n / 2
	if n%2 == 0 {
		newx = c - (y - c) - 1
		newy = (x - c) + c
	} else {
		newx = c - (y - c)
		newy = (x - c) + c
	}
	return
}

func compare(mat [][]int, target [][]int) bool {
	for i, row := range mat {
		for j, v := range row {
			if target[i][j] != v {
				return false
			}
		}
	}
	return true
}

func findRotation(mat [][]int, target [][]int) bool {
	if compare(mat, target) {
		return true
	}
	n := len(mat)
	mat2 := make([][]int, n)
	for i := range mat2 {
		mat2[i] = make([]int, n)
	}
	for k := 0; k < 3; k++ {
		for i, v := range mat {
			for j, v2 := range v {
				newx, newy := Rotation90(j, i, n)
				mat2[newy][newx] = v2
			}
		}
		mat, mat2 = mat2, mat
		if compare(mat, target) {
			return true
		}
	}
	return false
}

func main() {

}
