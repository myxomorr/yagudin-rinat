#!/bin/bash

rm -rf bin
rm -rf obj
mkdir -p bin
mkdir -p obj
g++ -c src/BankAccount.cpp -o obj/BankAccount.o
g++ -c src/main.cpp -o obj/main.o
g++ -o bin/main obj/main.o obj/BankAccount.o