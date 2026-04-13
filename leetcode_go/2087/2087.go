package main

func minCost(startPos []int, homePos []int, rowCosts []int, colCosts []int) int {
	ans := 0
	travel := func(start int, end int, arr []int) {
		if end > start {
			for i := start + 1; i <= end; i++ {
				ans += arr[i]
			}
		} else {
			for i := start - 1; i >= end; i-- {
				ans += arr[i]
			}
		}
	}
	travel(startPos[0], homePos[0], rowCosts)
	travel(startPos[1], homePos[1], colCosts)
	return ans
}
