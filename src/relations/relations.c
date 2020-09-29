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

int
is_unreflective(int size, int matrix[size][size])
{
    for (int i = 0; i < size; i++) {
        if (matrix[i][i]) {
            return 0;
        }
    }
    return 1;
}

int
is_simetric(int size, int matrix[size][size])
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (!(matrix[i][j] == matrix[j][i])) {
                return 0;
            }
        }
    }
    return 1;
}

int
is_antisimetric(int size, int matrix[size][size])
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j] == matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int
is_unsimetric(int size, int matrix[size][size])
{
    if (is_antisimetric(size, matrix) && is_unreflective(size, matrix)) {
        return 1;
    }
    return 0;
}

int
is_transictive(int size, int matrix[size][size])
{
    int i, j, w;
    for (i = 0; i < size; i++) {
        for (j = i; j < size; j++) {
            if (matrix[i][j] && !matrix[i][i]) {
                return 0;
            }

            if (matrix[i][j]) {
                for (w = j; w < size; w++) {
                    if (matrix[j][w] && !matrix[i][w]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int
is_equivalence_relation(int size, int matrix[size][size])
{
    if (is_simetric(size, matrix)
        && is_reflective(size, matrix)
        && is_transictive(size, matrix)
    ) {
        return 1;
    }
    return 0;
}

int
is_parcial_order_relation(int size, int matrix[size][size])
{
    if (is_antisimetric(size, matrix)
        && is_reflective(size, matrix)
        && is_transictive(size, matrix)
    ) {
        return 1;
    }
    return 0;
}