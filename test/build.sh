#!/bin/sh
cp ../lib/sharemem.h sharemem.h
cp ../lib/libsharemem.so libsharemem.so
gcc -c  main.c
gcc main.o -L. -lsharemem  -o ShareMemTest