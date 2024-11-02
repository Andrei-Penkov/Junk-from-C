#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define PI 3.14

 //Приведение икса к нормальному значению
double trigo(double xx)
{
    if (xx > PI)
        while (xx>PI)
            xx -=PI;
    if (xx < -PI)
        while (xx< -PI)
            xx += PI;
    return xx;
}


//Функция нахождение сумму ряда
double sum_r9da(double azm_cop, double pred_cop, double xx, double *mod, double sum_cop, double ee)
{
    int n = 1;
    pred_cop = xx;
    azm_cop = xx;
    sum_cop = pred_cop;
    while (*mod > ee)
    {
        azm_cop = (-1) * (pred_cop) * (((xx) * (xx)) / ((n + 1) * (n + 2)));

        if (azm_cop > 0)
            *mod = azm_cop;
        else
            *mod = -azm_cop;
        sum_cop += azm_cop;
        pred_cop = azm_cop;
        n += 2;
    }
    return sum_cop;
}



int main()
{
    double x, e, pred, azm, mod, raz, sum, x_norm;

    int n, i, error;
    
    printf("Good morning\n");
    printf("This program was made by Andrei Penkov\n");
    printf("Group IT-11, date 14.10.2022\n");
    printf("Number Lab work - B.1.3(2)\n");
    printf("This program calculates the sum of a number of elements\n");
    printf("based on the data that your input(x and e) while element > e.\n");
    printf("And calculates sin(x) and  sum - sin(x).\n");
    printf("Number e must > 0\n");
    printf("\n");
    printf("Please input real numbers x and e\n");
    error = scanf("%lf", &x);
    if (error == 0)
    {
        printf("Sorry but you input ancorrect data, please input only numbers\n");
        return 0;
    }
    error = scanf("%lf", &e);
    if (error == 0)
    {
        printf("Sorry but you input ancorrect data, please input only numbers\n");
        return 0;
    }
    if (e <= 0)
    {
        printf("Your input data lower zero or zero\n");
        return 0;
    }
    x_norm = trigo(x);
    n = 1;
    if (x_norm > 0)
        mod = x_norm;
    else
        mod = -x_norm;
    sum = sum_r9da(azm, pred, x_norm, &mod, sum, e);
    raz = sum - sin(x_norm);
    printf("x = %lf\n", x_norm);
    printf("e = %lf\n", e);
    printf("Sum = %lf\n", sum);
    printf("Sin(x) = %lf\n", sin(x_norm));
    printf("The absolute value of the last element = %lf\n", mod);
    printf("Sum - Sin(x) = %lf\n", raz);
    return 0;
}