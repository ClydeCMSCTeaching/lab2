#ifndef LAB3_MATRIX_H
#define LAB3_MATRIX_H

/*
 * create a dynamically allocated arr (need malloc)
 * such that the rows (i.e. first index) is length rows and the second index
 * (cols) are length cols.
 * set all values in the array to be equal to value
 */
int** matrixInit(int rows, int cols, int value);

/*
 * get the min value in the array
 */
int matrixMin(int **arr, int rows, int cols, int value);

/*
 * get the max value in the array
 */
int matrixMax(int **arr, int rows, int cols, int value);


/*
 * print the array to screen
 * the array has rows rows and cols cols
 * make sure to check the array for a min/max element
 * to see how many digits you need spacing
 * (i.e. if you assume 1 space between numbers, the rows will be unequal width and it won't look good)
 */
void matrixPrint(int **arr, int rows, int cols);

/*
 * free both arr and all the memory it consumes
 * recall: for every malloc statement you want a free statement somewhere!
 */
void matrixDestroy(int **arr, int length1);

#endif //LAB3_MATRIX_H
