
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
struct list
    {
      int inf; // поле данных
      struct list *next; // указатель на следующий элемент
      struct list *prev; // указатель на предыдущий элемент
    };
struct list* Glue(struct list *First, struct list *First2) //функция склейки двух списков в третий результирующий
{
    struct list *T,*T2,*T3;
    struct list *P3,*F3;
    F3=NULL;
    int help=0,help2=0,count_help=0;
    T=First;
    T2=First2;
    while(1)
    {
        T3 =(struct list *)malloc(sizeof(struct list));
        if (T3==NULL)
        {
            return NULL;
        }
        T3->next=NULL;
        T3->prev=NULL;
        if (help==0 && help2==0)
        {
            if (count_help%2==0)
            {
                T3->inf=T->inf;
                T=T->next;   
            }
            else
            {
                T3->inf=T2->inf;
                T2=T2->next;
            }
        }
        if(help==1 && help2==1)
            break;
        if (help==1)
        {
            T3->inf=T2->inf;
            T2=T2->next;
        }

        if (help2==1)
        {
            T3->inf=T->inf;
            T=T->next;
        }
        
        if (F3==NULL)
        {
            F3=T3;
            P3=T3;
        }
        else
        {
            T3->prev=P3;
            P3->next=T3;
            P3=T3;
        }
        if(T==NULL)
            help=1;
        if(T2==NULL)
            help2=1;
        count_help++;
    }
    return F3;
}
void Output(struct list *F) //фунция вывода списка
{
    struct list *T;
    T=F;
    while(T!=NULL)
    {
        printf("%d ",T->inf);
        T=T->next;
    }
}
int main()
{
    struct list *F,*P,*T;
    struct list *F2,*P2,*T2;
    struct list *F3,*P3,*T3;
    int a,count=0,count2=0,x;
    F=P=T=NULL;
    F2=P2=T2=NULL;
    F3=P3=T3=NULL;
    setlocale(0,"");
    printf("Вас привествует программа для склейки двух ваших списков.\n");
    printf("Программа склеит списки по правилу, первый элемент первого\n");
    printf("первый элемент второго, второй первого, второй второго и т.д.\n");
    printf("Список должен состоять из целых чисел!!!\n");
    while(1)    //первый список
    {
        printf("Хотите ввести данные для первого списка? 1(да)/0(нет)\n");
        x=scanf("%d",&a); //проверка
        if (x==0)
        {
            printf("Вы ввели некоректные данные, вводите только целые числа!\n");
            return 1;
        }
        if (a!=0 && a!=1)
        {
            printf("Вы ввели некоректные данные!\n");
            return 1;
        }
        if (!a)
        {
            break;
        }
        T =(struct list *)malloc(sizeof(struct list));
        if (T==NULL)
        {
            printf("Простите, не удалось выделить память\n");
            free(F);
            return 1;
        }
        T->next=NULL;
        T->prev=NULL;
        printf("Введите данные для элемента\n");
        x=scanf("%d",&T->inf);    //проверка
        if (x==0)
        {
            printf("Вы ввели некоректные данные, вводите только целые числа!\n");
            return 1;
        }
        if (F==NULL)
        {
            F=T;
            P=T;
        }
        else
        {
            T->prev=P;
            P->next=T;
            P=T;
        }
        count++;
    }
    while(1)    //второй список
    {
        printf("Хотите ввести данные для второго списка? 1(да)/0(нет)\n");
        x=scanf("%d",&a); //проверка
        if (x==0)
        {
            printf("Вы ввели некоректные данные, вводите только целые числа!\n");
            return 1;
        }
        if (a!=0 && a!=1)
        {
            printf("Вы ввели некоректные данные!\n");
            return 1;
        }
        if (!a)
        {
            break;
        }
        T2 =(struct list *)malloc(sizeof(struct list));
        if (T2==NULL)
        {
            printf("Простите, не удалось выделить память\n");
            free(F);
            free(F2);
            return 1;
        }
        T2->next=NULL;
        T2->prev=NULL;
        printf("Введите данные для элемента\n");
        x=scanf("%d",&T2->inf);    //проверка
        if (x==0)
        {
            printf("Вы ввели некоректные данные, вводите только целые числа!\n");
            return 1;
        }
        if (F2==NULL)
        {
            F2=T2;
            P2=T2;
        }
        else
        {
            T2->prev=P2;
            P2->next=T2;
            P2=T2;
        }
        count2++;
    }
    T=F;
    if (F==NULL)
    {
        printf("Простите, но нельзя склеить того чего нет :(\n");
        return 0;
    }
    if (F2==NULL)
    {
        printf("Простите, но нельзя склеить того чего нет :(\n");
        return 0;
    }
    printf("Первый список\n");  //вывод первого
    Output(F);
    printf("\nВторой список\n");    //вывод второго
    Output(F2);
    F3=Glue(F, F2); //склейка
    if (F3==NULL)
    {
        printf("Простите, не удалось выделить память\n");
        free(F);
        free(F2);
        free(F3);
        return 1;
    }
    printf("\nРезультирующий список\n");    //вывод результирующего списка
    Output(F3);
    count -= count2;
    if (count<0)
        count*=-1;
    printf("\nОтстаточных элементов %d",count); //вывод лишних элементов
    free(F);    //освобождение задейственной памяти
    free(F2);
    free(F3);
    return 0;
}

