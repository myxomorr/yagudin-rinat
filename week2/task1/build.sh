#!/bin/bash

rm -rf bin
rm -rf obj
mkdir -p bin
mkdir -p obj
g++ -c src/task1.cpp -o obj/task1.o
g++ -c src/main.cpp -o obj/main.o
g++ -o bin/main obj/main.o obj/task1.o