#!/usr/bin/env fish

mkdir -p out
cc $argv[1].c -o out/$argv[1]
echo "$argv[2]" | ./out/$argv[1]
