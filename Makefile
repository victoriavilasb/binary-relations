PP = gcc
EXEC = ./binary_elements

binary_elements: src/main.c src/relations/relations.c
	${PP} src/main.c -o binary_elements

playground: src/cmd/playground.c
	${PP} src/cmd/playground.c -o playground

clean:
	rm -rf *o binary_elements