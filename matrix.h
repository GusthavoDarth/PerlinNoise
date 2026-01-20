typedef struct{
    int rows, cols;
    float** data;
}floatMatrix;

floatMatrix createFloatMatrix(int rows, int cols)
{
    floatMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = malloc(sizeof(float*) * rows);
    for(int i = 0; i < rows; ++i){
		matrix.data[i] = malloc(sizeof(float) * cols);
	}
	return matrix;
}

void seeFloatMatrix(floatMatrix matrix)
{
    for(int i = 0; i < matrix.rows; i++)
    {
        printf("\n");
        for(int j = 0; j < matrix.cols; j++)
        {
            printf("x:%dy:%dn:%1f ", i, j, matrix.data[i][j]);
        }

    }
}



int** intMatrix(int x, int y)
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


void seeIntMatrix(int** matrix, int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        printf("\n");
        for(int j = 0; j < y; j++)
        {
            printf("x:%d y:%d n:%d ", i, j, matrix[i][j]);
        }

    }
}


void freeMatrix(floatMatrix matrix) {
    if (matrix.data == NULL) return;
    
    for (int i = 0; i < matrix.rows; i++) 
    {
        free(matrix.data[i]);
    }
    free(matrix.data);
}