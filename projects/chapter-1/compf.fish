#!/usr/bin/env fish

mkdir -p out
cc $argv[1].c -o out/$argv[1]
cat test.txt | ./out/$argv[1]
