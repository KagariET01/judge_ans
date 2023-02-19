@echo off
SET problem=Compass
gcc -std=gnu11 -O2 -pipe -static -s -o %problem% grader.c %problem%.c -lm
