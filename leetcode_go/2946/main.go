package main

func areSimilar(mat [][]int, k int) bool {
	_, n := len(mat), len(mat[0])
	for i, row := range mat {
		if i%2 == 0 {
			for j, v := range row {
				if v != row[((j-k)%n+n)%n] {
					return false
				}
			}
		} else {
			for j, v := range row {
				if v != row[(j+k)%n] {
					return false
				}
			}
		}
	}
	return true
}
