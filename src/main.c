#include<stdio.h>
#include<stdlib.h>

int 
indexOf(int number, int elements[], int elements_number)
{
    for (int i = 0; i < elements_number; i++)
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
main(void) 
{
    int elements_number, elem, index_line, index_column, line_number, column_number;

    scanf("%i", &elements_number);
    int elements[elements_number];

    int relation_matrix[elements_number][elements_number];
    zeros(elements_number, relation_matrix);

    for (int i = 0; i < elements_number; i++) {
        scanf("%i", &elem);
        elements[i] = elem;
    }

    // Getting all matrix relations pairs
    while (scanf("%i %i", &line_number, &column_number)) {
        if (line_number == EOF) {
            break;
        }
        index_line = indexOf(line_number, elements, elements_number);
        index_column = indexOf(column_number, elements, elements_number);
        if (index_line == -1 || index_column == -1){
            printf("ERROR: Number does not exists in the set of elements");
            exit(1);
        }

        relation_matrix[index_line][index_column] = 1;
    }

    for (int i = 0; i < elements_number; i++) {
        for (int j = 0; j < elements_number; j++) {
            printf("%i ", relation_matrix[i][j]);
        }
        printf("\n");
    }
}