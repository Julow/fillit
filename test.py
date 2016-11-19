#!/usr/bin/env python3
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/19 11:09:17 by jaguillo          #+#    #+#              #
#    Updated: 2016/11/19 14:57:48 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random, subprocess, time

N = 17

SHOW_SOLUTIONS = True

PIECES = [
	"#...\n#...\n#...\n#...",
	"####\n....\n....\n....",
	"#...\n##..\n.#..\n....",
	".##.\n##..\n....\n....",
	".#..\n##..\n#...\n....",
	"##..\n.##.\n....\n....",
	"##..\n##..\n....\n....",
	".#..\n###.\n....\n....",
	"#...\n##..\n#...\n....",
	"###.\n..#.\n....\n....",
	"#...\n###.\n....\n....",
	"..#.\n###.\n....\n....",
	".#..\n.#..\n##..\n....",
	"###.\n#...\n....\n....",
	"#...\n#...\n##..\n....",
	"##..\n#...\n#...\n....",
	"##..\n.#..\n.#..\n....",
	"###.\n.#..\n....\n....",
	".#..\n##..\n.#..\n...."
]

def rand_tetri(tetri_count):
	return "\n\n".join([random.choice(PIECES) for _ in range(tetri_count)])

def test(tetris, hide_stdout=False):
	p = subprocess.Popen(["./fillit"], stdin=subprocess.PIPE,
		stdout=subprocess.DEVNULL if hide_stdout else None)

	p.stdin.write(bytes(tetris + "\n", 'UTF-8'))

	start = time.time()

	p.stdin.close()
	p.wait()

	end = time.time()

	return (end - start) * 1000

sum_time = 0
max_time = 0
count = 0

for i in range(100):
	tetris = rand_tetri(N)
	if SHOW_SOLUTIONS:
		t = test(tetris)
		print(" -> run #%d t=%fms\n" % (i, t))
	else:
		t = test(tetris, True)
	if t > 500:
		print(tetris)
	max_time = max(t, max_time)
	sum_time += t
	count += 1

print("%d samples; avg=%fms max=%fms" % (count, sum_time / count, max_time))
