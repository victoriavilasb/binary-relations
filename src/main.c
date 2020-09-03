#include<stdio.h>
#include<stdlib.h>

int 
index_of(int number, int elements[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (elements[i] == number) {
            return i;
        }
    }
    return -1;
}

void
zeros(int size, int matrix[size][size])
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = 0;
    
}

int
is_reflective(int size, int matrix[size][size])
{
    for (int i = 0; i < size; i++) {
        if (!matrix[i][i]) {
            return 0;
        }
    }
    return 1;
}

void
complete_reflective_relation(int size, int matrix[size][size], int elements[size])
{
    for (int i = 0; i < size; i++) {
        if (!matrix[i][i]) {
            printf("(%i,%i); ", elements[i], elements[i]);
        }
    }
    printf("\n");
}

int
main(void) 
{
    int size, elem, index_line, index_column, line_number, column_number;

    scanf("%i", &size);
    int elements[size];

    int relation_matrix[size][size];
    zeros(size, relation_matrix);

    for (int i = 0; i < size; i++) {
        scanf("%i", &elem);
        elements[i] = elem;
    }

    // Getting all matrix relations pairs
    while (scanf("%i %i", &line_number, &column_number)) {
        if (line_number == EOF) {
            break;
        }
        index_line = index_of(line_number, elements, size);
        index_column = index_of(column_number, elements, size);
        if (index_line == -1 || index_column == -1){
            printf("ERROR: Number does not exists in the set of elements");
            exit(1);
        }

        relation_matrix[index_line][index_column] = 1;
    }

    printf("Propriedades\n");
    printf("1. Reflexiva: ");
    if (is_reflective(size, relation_matrix)) {
        printf("V\n");
    } else {
        printf("F\n");
        complete_reflective_relation(size, relation_matrix, elements);
    }
}