#include<stdio.h>
#include<stdlib.h>
#include "./relations/relations.c"

// index_of is a function that finds index of a element in a array
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

// zeros is a function that put zeros in every position in a matrix
void
zeros(int size, int matrix[size][size])
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = 0;
    
}

// complete_reflective_relation is a function that walks through the matrix and prints the tuples needed in order to have a reflective relation.
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

// complete_simetric_relation is a function that walks through the matrix and print the tuples that are needed in order to get a simetric relation
void
complete_simetric_relation(int size, int matrix[size][size], int elements[size])
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j] && !matrix[j][i]) {
                printf("(%i,%i); ", elements[j], elements[i]);
            }
        }
    }
    printf("\n");
}

// find_unreflective_reason is a function that walks through the matrix and print the tuples that makes the relation not unreflective.
void
find_unreflective_reason(int size, int matrix[size][size], int elements[size])
{
    for (int i = 0; i < size; i++) {
        if (matrix[i][i]) {
            printf("(%i,%i); ", elements[i], elements[i]);
        }
    }
    printf("\n");
}

void
find_antisimetric_reason(int size, int matrix[size][size], int elements[size])
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i; j < size; j++) {
            if (matrix[i][j] && (matrix[i][j] == matrix[j][i]) && i != j) {
                printf("(%i,%i) e (%i,%i); ", elements[i], elements[j], elements[j], elements[i]);
            }
        }
    }
    printf("\n");
}

void
find_transitive(int size, int matrix[size][size], int elements[size])
{
    int i, j, w;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j]) {
                for (w = 0; w < size; w++) {
                    if (matrix[j][w] && !matrix[i][w]) {
                        printf("(%i,%i); ", elements[i], elements[w]);
                    }
                }
                if (!matrix[i][i]) {
                    printf("(%i,%i); ", elements[i], elements[i]);
                    break;
                }
            }
        }
    }
    printf("\n");
}

void
print_transitive_closure(int size, int matrix[size][size], int elements[size])
{
    int i, j, w;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j]) {
                printf("(%i,%i); ", elements[i], elements[j]);
                
                for (w = 0; w < size; w++) {
                    if (matrix[j][w] && !matrix[i][w]) {
                        printf("(%i,%i); ", elements[i], elements[w]);
                    }
                }

                if (!matrix[i][i]) {
                    printf("(%i,%i); ", elements[i], elements[i]);
                    break;
                }
            }
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
    printf("2. Irreflexiva: ");
    if (is_unreflective(size, relation_matrix)) {
        printf("V\n");
    } else {
        printf("F\n");
        find_unreflective_reason(size, relation_matrix, elements);
    }
    printf("3. Simétrica: ");
    if (is_simetric(size, relation_matrix)) {
        printf("V\n");
    } else {
        printf("F\n");
        complete_simetric_relation(size, relation_matrix, elements);
    }
    printf("4. Anti-simétrica: ");
    if (is_antisimetric(size, relation_matrix)) {
        printf("V\n");
    } else {
        printf("F\n");
        find_antisimetric_reason(size, relation_matrix, elements);
    }
    printf("5. Assimétrica: ");
    if (is_unsimetric(size, relation_matrix)) {
        printf("V\n");
    } else {
        printf("F\n");
    }
    printf("6. Transitiva: ");
    if (is_transitive(size, relation_matrix)) {
        printf("V\n");
    } else {
        printf("F\n");
        find_transitive(size, relation_matrix, elements);
    }
    printf("Relação de equivalência: ");
    if (is_equivalence_relation(size, relation_matrix)) {
        printf("V\n");
    } else {
        printf("F\n");
    }
    printf("Relação de ordem parcial: ");
    if (is_parcial_order_relation(size, relation_matrix)) {
        printf("V\n");
    } else {
        printf("F\n");
    }
    printf("Fecho transitivo da relação: ");
    print_transitive_closure(size, relation_matrix, elements);
}