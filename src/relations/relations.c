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
            return 1;
        }
    }
    return 0;
}