SRC = main.c \
			src/date.c \
			src/transaction.c \
			src/ui_functions.c




all : compile exec

compile :
	gcc $(SRC) -o main.out -Wall

exec :
	./main.out

clean :
	rm main
