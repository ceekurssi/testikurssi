SRC_FILES=main.c frankCard.c cashRegister.c money.c

all: main

main: $(SRC_FILES)
	gcc -g -Wall -Wextra -pedantic -std=c99 -o $@ $(SRC_FILES) -lm

clean:
	rm -f main

run: main
	# Running our main function from file main.c
	./main
