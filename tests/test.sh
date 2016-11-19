#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    lol.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 16:01:06 by ccompera          #+#    #+#              #
#    Updated: 2016/11/19 18:30:36 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

function gen_maps
{
	if ! [[ "$#" -eq 3 ]]
	then
		echo "Usage:"
		echo "	$0 tetri_count map_count dst_dir"
		exit 1
	fi

	TETRI_COUNT=$1
	MAP_COUNT=$2
	DST_DIR=$3

	python3 << EOF
import random, os

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

for i in range($MAP_COUNT):
	f_name = "$DST_DIR/%d_%03d" % ($TETRI_COUNT, i)
	if os.path.isfile(f_name):
		continue
	with open(f_name, "w") as f:
		print("\n\n".join([random.choice(PIECES) for _ in range($TETRI_COUNT)]), file=f)

EOF
}

function diff_maps
{
	if ! [[ "$#" -eq 2 ]]
	then
		echo "Usage:"
		echo "\t$0 a_dir b_dir"
		exit 1
	fi

	A_DIR=$1
	B_DIR=$2

	for file in `ls $A_DIR`
	do
		if ! diff -q "$A_DIR/$file" "$B_DIR/$file" 1>/dev/null
		then
			echo "# $file"
			diff -y "$A_DIR/$file" "$B_DIR/$file"
			echo
		fi
	done
}

function test_maps
{
	python3 - "$@" << EOF

import sys, os, subprocess, time

if len(sys.argv) < 3:
	print("Not enough argument\n"
		+ "Usage:\n"
		+ "\t%s output_dir fillit [maps...]" % sys.argv[0], file=sys.stderr)

output_dir = sys.argv[1]
fillit = sys.argv[2]
maps = sys.argv[3:]

sum_time = 0
max_time = 0
count = 0

for m in maps:
	start = time.time()
	output_file = "%s/%s" % (output_dir, os.path.basename(m))
	p = subprocess.Popen([fillit, m], stdout=open(output_file, "w"))
	p.wait()
	end = time.time()
	t = (end - start) * 1000
	sum_time += t
	max_time = max(t, max_time)
	count += 1

print("%s:" % fillit)
print(" -> %d runs; avg=%fms max=%fms" % (count, sum_time / count, max_time))

EOF
}

if [[ $# < 1 ]]
then
	echo "Usage:"
	echo "\t$0 a_fillit [b_fillit]"
	exit 1
fi

A_FILLIT=$1

BASE_DIR="/tmp/fillit_test"
A_DIR="$BASE_DIR/a"
B_DIR="$BASE_DIR/b"
INPUT_DIR="$BASE_DIR/inputs"

mkdir -p "$A_DIR" "$B_DIR" "$INPUT_DIR"

gen_maps 17 999 "$INPUT_DIR"

MAPS=$INPUT_DIR/17_*

test_maps "$A_DIR" "$A_FILLIT" $MAPS

shift
if [[ $# > 0 ]]
then
	B_FILLIT=$1

	if [[ "$B_FILLIT" != "" ]]
	then
		test_maps "$B_DIR" "$B_FILLIT" $MAPS
	fi
	diff_maps "$A_DIR" "$B_DIR"
fi
