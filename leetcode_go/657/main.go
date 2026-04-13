package main

func judgeCircle(moves string) bool {
	x, y := 0, 0
	n := len(moves)
	move := map[byte]func(){'R': func() { x += 1 }, 'L': func() { x -= 1 }, 'U': func() { y += 1 }, 'D': func() { y -= 1 }}
	for i := 0; i < n; i++ {
		move[moves[i]]()
	}
	return x == 0 && y == 0
}
