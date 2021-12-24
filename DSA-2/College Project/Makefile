# execute: clear
# 	main.exe

clear: all
	del *.o main
	
all: dictionary.o
	gcc dictionary.o main.c -o main

dictionary.o: dictionary.h
	gcc -c dictionary.c
