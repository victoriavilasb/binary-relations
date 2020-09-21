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
            if (!(matrix[i][j] && matrix[j][i])) {
                return 0;
            }
        }
    }
    return 1;
}