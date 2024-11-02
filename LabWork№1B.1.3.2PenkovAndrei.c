// ������������ ������ �1
//�������: B1.3(2)
//�������� �������: ������� ������ 
//������: ��-11��
//����: 14.10.2022

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//�� �������� ������������ ������ � � � ���������� ���������� ����� ���� ��
//��� ���, ���� ���������� �������� ���������� ����� ���� �� ������ ������ � 
//���������� ������ ���� ����������� ����������� ��������, ���, ����� ��������
//������� ������������ ���������� ����������� ������ �� �������� �����������
//� ��� ������������� ������������ ������� ���������� � �������.
//(������ ���� �������� �� ��������������� �)
//��� ������ ��������� ����� �������
//x-x^2/3!+x^5/5!-x^7/7!...
//��������� ����� ������� �������� ��������: x,e,����� ����,������ ��������
//�������(� ������ ������ sin(x)),���������� �������� ���������� ������������
//����� ����, � ����� �������� �������� ����������� ����� � ������� sin(x).

int main()
{
    double x, e, sum, pred, azm, mod, raz;
    //���������� (sum- ����� ����;pred-���������� �������; 
    //azm-�������, ������� ���������� ������; 
    //mod-������ ���������� �������� ����; raz-�������� ����� ���� ''
    //� ������ ����)
    int n, i, error;
    //(n-���������� ��� �������� �������� ���������� ������������ ����������� �������� ����)
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
    if (error == 0)//�������� �� ������������ �����
    {
        printf("Sorry but your input uncorrect data\n");
        return 0;
    }
    error = scanf("%lf", &e);
    if (error == 0)//�������� �� ������������ �����
    {
        printf("Sorry but your input uncorrect data\n");
        return 0;
    }
    if (x > 700)//�������� �� �������� ������� 700, ������� � ������-�� 700+ ����� �� ���������� �� ����������� ���� double
    {
        printf("Better not enter data bigger 700");
        return 0;
    }
    if (e <= 0)//�������� �� ���������������
    {
        printf("Your input data lower zero or zero\n");
        return 0;
    }
    sum = x;//������ ������� ���� ������ �
    pred = x;//������� ���� ������������ � ������ ��� ���������� ������������
    n = 1;
    if (x > 0)//���������� ������ ������� �������� ����, ����� ������ ����
        mod = x;//��� �� ���, ���� ������ �������� ������ �
    else
        mod = -x;
    while (mod > e)//���� ���������� ��������� ����(������� �� �������)
    {
        azm = (-1) * pred * ((x * x) / ((n + 1) * (n + 2)));//���������� �������� ����

        //(��� ��� ������� ������ B1.3(2), ��������� ��� � ������������
        //����� + � - ����� ����������� ����, � ������ ���������� �� -1
        //��� �� ������� �������������� ������� ��-�� ����, ��� ������� ����
        //������ ����� ������������� �� ���������� �� -1 
        //(�-�������������, � ���� � ���� �� �������������, �� ���� 
        //���� �� ��������) ������� ���������� �� -1
        //�� ������� ������� � ���������� �������� ����)

        if (azm > 0)//���������� ���������� �������� ����� ��������
            mod = azm;
        else
            mod = -azm;
        sum += azm;//���������� ����� ����
        pred = azm;//������ ������� � ������, ��� �������� ���������� ����������
        n += 2;//���������� n ��� ���������� ���������� � ��������� ��������
    }
    raz = sum - sin(x);//���������� �������� ����� � ������
    printf("x = %lf\n", x);//����� ����������� ������, �� ������� ������
    printf("e = %lf\n", e);
    printf("Sum = %lf\n", sum);
    printf("Sin(x) = %lf\n", sin(x));
    printf("The absolute value of the last element = %lf\n", mod);
    printf("Sum - Sin(x) = %lf\n", raz);
    return 0;
}