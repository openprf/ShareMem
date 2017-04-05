#!/bin/sh

gcc -fPIC -c  main.c
gcc -shared -o libsharemem.so  main.o