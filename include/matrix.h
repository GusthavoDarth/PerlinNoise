#include <stdlib.h>
typedef struct{
    int rows, cols;
    float** data;
}floatMatrix;

floatMatrix createFloatMatrix(int rows, int cols)
{
    floatMatrix matrix = {0};
    matrix.rows = rows;
    matrix.cols = cols;

    matrix.data = malloc(sizeof(float*) * rows);
    if(matrix.data == NULL)
    {
        matrix.rows = 0;
        matrix.cols = 0;
        return matrix;
    }
    for(int i = 0; i < rows; i++){
		matrix.data[i] = malloc(sizeof(float) * cols);
		if(matrix.data[i] == NULL)
		{
		    for(int j = 0; j < i; j++)
		    {
		        free(matrix.data[j]);
		    }
		    free(matrix.data);
		    matrix.rows = 0;
		    matrix.cols = 0;
		    return matrix;
		}
	}
	return matrix;
}

void freeMatrix(floatMatrix matrix) {
    if(matrix.data == NULL) return;

    for(int i = 0; i < matrix.rows; i++)
    {
        free(matrix.data[i]);
    }
    free(matrix.data);
}
