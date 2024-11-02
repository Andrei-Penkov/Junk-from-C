//Лабораторная работа №2
//Выполнил Пеньков Андрей
//Группа ИТ-11бо
//Дата 27.10.2022


//Задание B.2.4.1.3
//Отразить квадратную матрицы А относительно её центра
//Построить матрицу С так что С = A * (B + E) + Е, где Е это единичная матрица

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h>
void FreeData(float **m, int nn)
{
    int i;
    for (i = 0; i < nn; i++)
        free(m[i]);
    free(m);
}
int Check(float **m, int nn)
{
    int i;
    if (m == NULL)
    {
        return 1;
    }
    for (i=0;i<nn;i++)
        if (m[i] == NULL)
        {
            return 1;
        }
}
void Stdout(float **m, int nn)
    {
        int i,j;
        for (i = 0; i < nn; i++)
            for (j = 0; j < nn; j++)
            {
                if (j < nn - 1)
                    printf("%8.2f ", m[i][j]);
                else
                {
                    printf("%8.2f", m[i][j]);
                    printf("\n");
                }
            }
    }
int main()
{
    int i, j, k, d, n, x; float** a, ** b, ** c;
    printf("Input the size of the square matrix\n");
    x = scanf("%d", &n);
    //Ввод размера квадратной матрицы
    if (x == 0)//Проверка на корректность данных
    {
        printf("Sorry but you input ancorrect data, please input only numbers\n");
        return 0;
    }
    if (n > 20)
    {
        printf("Sorry but you input data bigger 20\n");
        return 0;
    }
    if (n <= 0)
    {
        printf("Sorry but you input data bigger 20\n");
        return 0;
    }
    // Выделение динамической памяти под двумерные массивы
    a = (float**)malloc(n * sizeof(float*));
    for (i = 0; i < n; i++) 
        a[i] = (float*)malloc(n * sizeof(float));
    
    b = (float**)malloc(n * sizeof(float*));
    for (i = 0; i < n; i++) 
        b[i] = (float*)malloc(n * sizeof(float));
    
    c = (float**)malloc(n * sizeof(float*));
    for (i = 0; i < n; i++) 
        c[i] = (float*)malloc(n * sizeof(float));
    //Проверка что память выделилась
    x = Check(a,n);
    if (x == 1)
        {
            printf("Sorry, but the program could not allocate memory for the array\n");
            return 1;
        }
    x = Check(b,n);
    if (x == 1)
        {
            printf("Sorry, but the program could not allocate memory for the array\n");
            return 1;
        }
    x = Check(c,n);
    if (x == 1)
        {
            printf("Sorry, but the program could not allocate memory for the array\n");
            return 1;
        }
    //Ввод матрицы
    printf("Input matrix`s element\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            x = scanf("%f", &a[i][j]);
            if (x == 0)//Проверка на корректность данных
            {
                printf("Sorry but you input ancorrect data, please input only numbers\n");
                //Очистка памяти, выделенную для матриц
                FreeData(a,n);
                FreeData(b,n);
                FreeData(c,n);
            }
        }
    //Отражение матрицы относительно цетра
    for (i = 0, k = n - 1; i < n; i++, k--)
        for (j = 0, d = n - 1; j < n; j++, d--)
            b[i][j] = a[k][d];
    // Вывод матрицы А
    printf("Matrix A\n");
    // Stdout(a, n);
    //Вывод матрицы B 
    printf("Matrix B\n");
    Stdout(b, n);
    //Заполнение матрицы C нулями, чтобы было возможно перемножение двух матриц в дальнейшем
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            c[i][j] = 0;
    //Перемножение матриц(A и (B + E)) и запись данных в матрицу C
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
            {
                if (j==k)
                    c[i][j] += a[i][k] * (b[k][j] + 1);
                else
                    c[i][j] += a[i][k] * b[k][j];
            }
    //C + E
    for (i = 0; i < n; i++)
        c[i][i] ++;
    //Вывод матрицы C 
    printf("Matrix C\n");
    Stdout(c, n);
    //Очистка памяти, выделенную для матриц
    FreeData(a,n);
    FreeData(b,n);
    FreeData(c,n);
    return 0;
}

