PP = gcc
EXEC = ./binary_elements

binary_relations: src/main.c src/relations/relations.c
	${PP} src/main.c -o binary_relations

clean:
	rm -rf *o binary_relations

run:
	./binary_relations