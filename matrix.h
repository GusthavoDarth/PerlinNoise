int** initMatrix(int x, int y)
{
    int** matrix = malloc(sizeof(int*)*x);
    for(int i = 0; i < x; ++i){
		matrix[i] = malloc(sizeof(int)*y);
	}
    for(int i = 0; i < x; ++i){
		for(int j = 0; j < y; ++j){
			matrix[i][j] = rand()%255;
		}
	}
	return matrix;
}

void seeMatrix(int** matrix, int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            printf("x:%d y:%d n:%d \n", i, j, matrix[i][j]);
        }

    }
}

void freeMatrix(int** matrix, int x) {
    if (matrix == NULL) return;
    
    for (int i = 0; i < x; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);
}