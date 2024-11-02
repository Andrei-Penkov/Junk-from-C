//������������ ������ �2
//�������� ������� ������
//������ ��-11��
//���� 27.10.2022


//������� B.2.4.1.3
//�������� ���������� ������� � ������������ � ������
//��������� ������� � ��� ��� � = A * (B + E) + �, ��� � ��� ��������� �������

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h>
int main()
{
    int i, j, k, d, n, x; float** a, ** b, ** c;
    printf("Input the size of the square matrix\n");
    x = scanf("%d", &n);
    //���� ������� ���������� �������
    if (x == 0)//�������� �� ������������ ������
    {
        printf("Sorry but you input ancorrect data\n");
        return 0;
    }
    if (n > 20)
    {
        printf("Sorry but you input data bigger 20\n");
        return 0;
    }
    //��������� ������������ ������ ��� ��������� �������
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
    //���� �������
    printf("Input matrix`s element\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            x = scanf("%f", &a[i][j]);
            if (x == 0)//�������� �� ������������ ������
            {
                printf("Sorry but you input ancorrect data\n");
                //������� ������, ���������� ��� ������
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
    //��������� ������� ������������ �����
    for (i = 0, k = n - 1; i < n; i++, k--)
        for (j = 0, d = n - 1; j < n; j++, d--)
            b[i][j] = a[k][d];
    //����� ������� �
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
    //����� ������� B ��� ������������, ��� ��� ����� � �������� ������ ��-�� ����������� �� ���������� ��������
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
    //���������� ������� C ������, ����� ���� �������� ������������ ���� ������ � ����������
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            c[i][j] = 0;
    //������������ ������ � ������ ������ � ������� C
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
    //C + E
    for (i = 0; i < n; i++)
        c[i][i] ++;
    //����� ������� C ��� ������������
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
    //������� ������, ���������� ��� ������
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