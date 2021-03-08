// mul_Matrix.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 256
#define TYPE (int(*)[256])


int arr1[256][256], arr2[256][256], result[256][256];
int m1[256][256], m2[256][256], m3[256][256], m4[256][256], m5[256][256], m6[256][256], m7[256][256];
int tmp1[256][256], tmp2[256][256];

void simple_matrix(int arr1[256][256], int arr2[256][256], int result[256][256], int n)
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void alloc_matrix(int arr1[256][256], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        arr1 = new int[256][256];
    }
}
void add_matrix(int(*arr1)[256], int(*arr2)[256], int(*result)[256], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            result[i][j] = arr1[i][j] + arr2[i][j];

}
void sub_matrix(int(*arr1)[256], int(*arr2)[256], int(*result)[256], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            result[i][j] = arr1[i][j] - arr2[i][j];
}
void copy_matrix(int(*src)[256], int(*dest)[256], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dest[i][j] = src[i][j];
}
void strassen(int(*arr1)[256], int(*arr2)[256], int(*result)[256], int n)
{
    int i, j, k;

    if (n > 2)
    {
        // m1 구하기
        add_matrix(TYPE & arr1[0][0], TYPE & arr1[n / 2][n / 2], TYPE tmp1, n / 2);
        add_matrix(TYPE & arr2[0][0], TYPE & arr2[n / 2][n / 2], TYPE tmp2, n / 2);
        strassen(TYPE tmp1, TYPE tmp2, TYPE m1, n / 2);
        for (i = 0; i < n / 2; i++) {
            for (j = 0; j < n / 2; j++) {
                printf("%4d ", m1[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        // m2 구하기
        add_matrix(TYPE & arr1[n / 2][0], TYPE & arr1[n / 2][n / 2], TYPE tmp1, n / 2);
        strassen(TYPE tmp1, TYPE & arr2[0][0], TYPE m2, n / 2);
        // m3 구하기
        sub_matrix(TYPE & arr2[0][n / 2], TYPE & arr2[n / 2][n / 2], TYPE tmp2, n / 2);
        strassen(TYPE & arr1[0][0], TYPE tmp2, TYPE m3, n / 2);
        // m4 구하기
        sub_matrix(TYPE & arr2[n / 2][0], TYPE & arr2[0][0], TYPE tmp2, n / 2);
        strassen(TYPE & arr1[n / 2][n / 2], TYPE tmp2, TYPE m4, n / 2);
        for (i = 0; i < n / 2; i++) {
            for (j = 0; j < n / 2; j++) {
                printf("%4d ", m4[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        // m5 구하기
        add_matrix(TYPE & arr1[0][0], TYPE & arr1[0][n / 2], TYPE tmp1, n / 2);
        strassen(TYPE tmp1, TYPE & arr2[n / 2][n / 2], TYPE m5, n / 2);
        // m6 구하기
        sub_matrix(TYPE & arr1[n / 2][0], TYPE & arr1[0][0], TYPE tmp1, n / 2);
        add_matrix(TYPE & arr2[0][0], TYPE & arr2[0][n / 2], TYPE tmp2, n / 2);
        strassen(TYPE tmp1, TYPE tmp2, TYPE m6, n / 2);
        // m7 구하기
        sub_matrix(TYPE & arr1[0][n / 2], TYPE & arr1[n / 2][n / 2], TYPE tmp1, n / 2);
        add_matrix(TYPE & arr2[n / 2][0], TYPE & arr2[n / 2][n / 2], TYPE tmp2, n / 2);
        strassen(TYPE tmp1, TYPE tmp2, TYPE m7, n / 2);

        // c11 계산
        add_matrix(TYPE & m1[0][0],
            TYPE & m4[0][0], TYPE tmp1, n / 2);
        sub_matrix(TYPE tmp1,
            TYPE & m5[0][0], TYPE tmp1, n / 2);
        add_matrix(TYPE & tmp1,
            TYPE & m7, TYPE & result[0][0], n / 2);
        // c12 계산
        add_matrix(TYPE m3,
            TYPE m5, TYPE & result[0][n / 2], n / 2);
        // c21 계산
        add_matrix(TYPE m2,
            TYPE m4, TYPE & result[n / 2][0], n / 2);
        // c22 계산
        add_matrix(TYPE & m1[0][0],
            TYPE & m3[0][0], TYPE tmp1, n / 2);
        sub_matrix(TYPE tmp1,
            TYPE & m2[0][0], TYPE tmp1, n / 2);
        add_matrix(TYPE & tmp1,
            TYPE m6, TYPE tmp1, n / 2);
        copy_matrix(TYPE tmp1, TYPE & result[n / 2][n / 2], n / 2);
    }
    else { // n==2 즉 행렬이 작은 경우
        simple_matrix(TYPE arr1, TYPE arr2, TYPE result, 2);
    }
}

int main(int argc, char** argv)
{
    int i, j, k, input;

    /* if (argc != 2) {
         printf("Usage : mulMatrix [number]\n");
         return;
     }*/
    input = 4;
    srand((unsigned)time(NULL));

    //    input = atoi(argv[1]);


    for (i = 0; i < 256; i++)
    {
        for (j = 0; j < 256; j++) {
            arr1[i][j] = (rand() % 10) - 5;
            arr2[i][j] = (rand() % 10) - 5;
        }
    }// 행렬 만들기
    for (i = 0; i < input; i++) {
        for (j = 0; j < input; j++)
        {
            printf("%3d ", arr1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < input; i++) {
        for (j = 0; j < input; j++)
        {
            printf("%3d ", arr2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    strassen(arr1, arr2, result, input);

    for (i = 0; i < input; i++) {
        for (j = 0; j < input; j++)
        {
            printf("%3d ", result[i][j]);
        }
        printf("\n");
    }

}