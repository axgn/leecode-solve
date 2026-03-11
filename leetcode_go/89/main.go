package main

import (
	"fmt"
	"math"
	"time"
)

func grayCode1(n int) []int {
	result := []int{0, 1}
	if n > 1 {
		result = grayCode(n - 1)
		val := 1 << (n - 1)
		for i := len(result) - 1; i >= 0; i-- {
			result = append(result, result[i]+val)
		}
	}
	return result
}

func grayCode(n int) []int {
	size := 1 << n
	res := make([]int, size)

	for i := 0; i < size; i++ {
		res[i] = i ^ (i >> 1)
	}

	return res
}

func grayCode2(n int) []int {
	result := []int{0, 1}
	if n > 1 {
		result = grayCode(n - 1)
		val := int(math.Pow(float64(2), float64(n-1)))
		for i := len(result) - 1; i >= 0; i-- {
			result = append(result, result[i]+val)
		}
	}
	return result
}

func test(fun func(int) []int) {
	n := 27

	start := time.Now()
	result := fun(n)
	fmt.Println(len(result))
	elapsed := time.Since(start)
	fmt.Println("time:", elapsed)
	// fmt.Println(result)
}

func main() {
	test(grayCode)
	test(grayCode1)
	test(grayCode2)
}
