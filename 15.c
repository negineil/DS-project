#include <stdio.h>
#include <stdlib.h>

struct Triplet {
    int row;
    int col;
    int value;
};

struct SparseMatrix {
    int rows;
    int cols;
    int num_nonzero;
    struct Triplet* data;
};

struct SparseMatrix* createSparseMatrix(int rows, int cols, int num_nonzero) {
    struct SparseMatrix* matrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->num_nonzero = num_nonzero;
    matrix->data = (struct Triplet*)malloc(num_nonzero * sizeof(struct Triplet));
    if (matrix->data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return matrix;
}

struct SparseMatrix* addSparseMatrices(struct SparseMatrix* A, struct SparseMatrix* B) {
    if (A->rows != B->rows || A->cols != B->cols) {
        printf("Matrix dimensions do not match for addition\n");
        exit(1);
    }

    int result_num_nonzero = A->num_nonzero + B->num_nonzero;
    struct SparseMatrix* result = createSparseMatrix(A->rows, A->cols, result_num_nonzero);

    int i = 0, j = 0, k = 0;
    while (i < A->num_nonzero && j < B->num_nonzero) {
        if (A->data[i].row < B->data[j].row || (A->data[i].row == B->data[j].row && A->data[i].col < B->data[j].col)) {
            result->data[k++] = A->data[i++];
        } else if (A->data[i].row > B->data[j].row || (A->data[i].row == B->data[j].row && A->data[i].col > B->data[j].col)) {
            result->data[k++] = B->data[j++];
        } else {
            result->data[k] = A->data[i];
            result->data[k++].value += B->data[j++].value;
        }
    }

    while (i < A->num_nonzero)
        result->data[k++] = A->data[i++];
    while (j < B->num_nonzero)
        result->data[k++] = B->data[j++];

    result->num_nonzero = k;
    return result;
}

struct SparseMatrix* multiplySparseMatrices(struct SparseMatrix* A, struct SparseMatrix* B) {
    if (A->cols != B->rows) {
        printf("Matrix dimensions do not match for multiplication\n");
        exit(1);
    }

    struct SparseMatrix* result = createSparseMatrix(A->rows, B->cols, 0);
    int max_nonzero_per_row = A->cols; 

    int* temp_result = (int*)calloc(B->cols, sizeof(int));
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++)
            temp_result[j] = 0;

        int temp_nonzero_count = 0;
        for (int j = 0; j < A->num_nonzero; j++) {
            if (A->data[j].row == i) {
                for (int k = 0; k < B->num_nonzero; k++) {
                    if (B->data[k].row == A->data[j].col)
                        temp_result[B->data[k].col] += A->data[j].value * B->data[k].value;
                }
            }
        }

        for (int j = 0; j < B->cols; j++) {
            if (temp_result[j] != 0) {
                result->data[result->num_nonzero].row = i;
                result->data[result->num_nonzero].col = j;
                result->data[result->num_nonzero].value = temp_result[j];
                result->num_nonzero++;
            }
        }
    }

    free(temp_result);
    return result;
}

void printSparseMatrix(struct SparseMatrix* matrix) {
    printf("Rows: %d, Cols: %d, Non-zero elements: %d\n", matrix->rows, matrix->cols, matrix->num_nonzero);
    printf("Data:\n");
    for (int i = 0; i < matrix->num_nonzero; i++) {
        printf("(%d, %d, %d)\n", matrix->data[i].row, matrix->data[i].col, matrix->data[i].value);
    }
}

int main() {

    struct SparseMatrix* A = createSparseMatrix(3, 3, 3);
    A->data[0].row = 0; A->data[0].col = 0; A->data[0].value = 1;
    A->data[1].row = 1; A->data[1].col = 1; A->data[1].value = 2;
    A->data[2].row = 2; A->data[2].col = 2; A->data[2].value = 3;

    struct SparseMatrix* B = createSparseMatrix(3, 3, 3);
    B->data[0].row = 0; B->data[0].col = 0; B->data[0].value = 4;
    B->data[1].row = 1; B->data[1].col = 1; B->data[1].value = 5;
    B->data[2].row = 2; B->data[2].col = 2; B->data[2].value = 6;

    struct SparseMatrix* sum = addSparseMatrices(A, B);
    struct SparseMatrix* product = multiplySparseMatrices(A, B);

    printf("Matrix A:\n");
    printSparseMatrix(A);
    printf("\nMatrix B:\n");
    printSparseMatrix(B);
    printf("\nMatrix A + B:\n");
    printSparseMatrix(sum);
    printf("\nMatrix A * B:\n");
    printSparseMatrix(product);

    free(A->data);
    free(A);
    free(B->data);
    free(B);
    free(sum->data);
    free(sum);
    free(product->data);
    free(product);

    return 0;
}
