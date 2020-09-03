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