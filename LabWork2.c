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
int main()
{
    int i, j, k, d, n, x; float** a, ** b, ** c;
    printf("Input the size of the square matrix\n");
    x = scanf("%d", &n);
    //Ввод размера квадратной матрицы
    if (x == 0)//Проверка на корректность данных
    {
        printf("Sorry but you input ancorrect data\n");
        return 0;
    }
    if (n > 20)
    {
        printf("Sorry but you input data bigger 20\n");
        return 0;
    }
    //Выделение динамической памяти под двумерные массивы
    a = (float**)malloc(n * sizeof(float*));
    for (i = 0; i < n; i++) {
        a[i] = (float*)malloc(n * sizeof(float));
    }
    b = (float**)malloc(n * sizeof(float*));
    for (i = 0; i < n; i++) {
        b[i] = (float*)malloc(n * sizeof(float));
    }
    c = (float**)malloc(n * sizeof(float*));
    for (i = 0; i < n; i++) {
        c[i] = (float*)malloc(n * sizeof(float));
    }
    //Ввод матрицы
    printf("Input matrix`s element\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            x = scanf("%f", &a[i][j]);
            if (x == 0)//Проверка на корректность данных
            {
                printf("Sorry but you input ancorrect data\n");
                //Очистка памяти, выделенную для матриц
                for (i = 0; i < n; i++)
                    free(a[i]);
                free(a);
                for (i = 0; i < n; i++)
                    free(b[i]);
                free(b);
                for (i = 0; i < n; i++)
                    free(c[i]);
                free(c);
                return 0;
            }
        }
    //Отражение матрицы относительно цетра
    for (i = 0, k = n - 1; i < n; i++, k--)
        for (j = 0, d = n - 1; j < n; j++, d--)
            b[i][j] = a[k][d];
    //Вывод матрицы А
    printf("Matrix A\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (j < n - 1)
                printf("%8.2f ", a[i][j]);
            else
            {
                printf("%8.2f", a[i][j]);
                printf("\n");
            }
        }
    //Вывод матрицы B для пользователя, так как затем её придется менять из-за ограничения по количеству массивов
    printf("Matrix B\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (j < n - 1)
                printf("%8.2f ", b[i][j]);
            else
            {
                printf("%8.2f", b[i][j]);
                printf("\n");
            }
        }
    //B + E
    for (i = 0; i < n; i++)
        b[i][i] ++;
    //Заполнение матрицы C нулями, чтобы было возможно перемножение двух матриц в дальнейшем
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            c[i][j] = 0;
    //Перемножение матриц и запись данных в матрицу C
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
    //C + E
    for (i = 0; i < n; i++)
        c[i][i] ++;
    //Вывод матрицы C для пользователя
    printf("Matrix C\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (j < n - 1)
                printf("%8.2f ", c[i][j]);
            else
            {
                printf("%8.2f", c[i][j]);
                printf("\n");
            }
        }
    //Очистка памяти, выделенную для матриц
    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);
    for (i = 0; i < n; i++)
        free(b[i]);
    free(b);
    for (i = 0; i < n; i++)
        free(c[i]);
    free(c);
    return 0;
}