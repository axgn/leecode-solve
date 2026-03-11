package main

import (
	"errors"
	"fmt"
	"strconv"
	"strings"
)

func myatoi(s string) int {
	temp := 1
	result := 0
	for i := len(s) - 1; i >= 0; i-- {
		result += temp * int(s[i])
		temp *= 10
	}
	return result
}

func findsubs(s string, sub string) int {
	pos := -1
	for i := 0; i < len(s); i++ {
		if i+len(sub) > len(s) {
			break
		}
		for j := 0; j < len(sub); j++ {
			if s[i+j] != sub[j] {
				break
			}
			if j == len(sub)-1 {
				return i
			}
		}
	}
	return pos
}

func splittwo(s string, sep string) ([]string, error) {
	result := make([]string, 2)
	pos := findsubs(s, sep)
	if pos < 0 {
		return result, errors.New("can't get pos")
	}
	s1 := make([]byte, pos)
	for i := 0; i < pos; i++ {
		s1[i] = s[i]
	}
	s2 := make([]byte, len(s)-pos-len(sep))
	for i := pos + len(sep); i < len(s); i++ {
		s2[i-pos-len(sep)] = s[i]
	}

	result[0] = string(s1)
	result[1] = string(s2)

	return result, nil

}

func mysplit(s string, sep string) []string {
	result := []string{}
	temp, err := splittwo(s, sep)
	for err == nil {
		result = append(result, temp[0])
		var temp2 []string
		temp2, err = splittwo(temp[1], sep)
		if err == nil {
			temp = temp2
		} else {
			result = append(result, temp[1])
		}
	}
	return result
}

func compareVersion(version1 string, version2 string) int {
	result := 0
	ver1s := strings.Split(version1, ".")
	ver2s := strings.Split(version2, ".")
	maxlen := max(len(ver1s), len(ver2s))
	extend := func(ss []string, targetlen int, val string) []string {
		extra := make([]string, targetlen-len(ss))
		for i := range extra {
			extra[i] = val
		}
		return append(ss, extra...)
	}
	ver1s = extend(ver1s, maxlen, "0")
	ver2s = extend(ver2s, maxlen, "0")
	for i := 0; i < maxlen; i++ {
		v1, _ := strconv.Atoi(ver1s[i])
		v2, _ := strconv.Atoi(ver2s[i])

		if v1 > v2 {
			result = 1
			break
		} else if v1 < v2 {
			result = -1
			break
		}
	}
	return result
}

func main() {
	version1 := "1.11.11.11"
	// version2 := "1.10"
	fmt.Println(splittwo(version1, "."))
	fmt.Println(mysplit(version1, "."))

	// fmt.Println(compareVersion(version1, version2))

}
