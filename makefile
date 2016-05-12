all : compile exec

compile :
	gcc -Wall main.c -o main.out

exec :
	./main.out

clean :
	rm main
