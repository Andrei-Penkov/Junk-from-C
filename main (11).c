
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
struct list
    {
      int inf; // поле данных
      struct list *next; // указатель на следующий элемент
      struct list *prev; // указатель на предыдущий элемент
    };

int main()
{
    struct list *F,*P,*T;
    struct list *F2,*P2,*T2;
    struct list *F3,*P3,*T3;
    int a,count=0,count2=0,count_help=0,help=0,help2=0,x;
    F=P=T=NULL;
    F2=P2=T2=NULL;
    F3=P3=T3=NULL;
    setlocale(0,"");
    printf("Вас привествует программа для склейки двух ваших списков.\n");
    printf("Программа склеит списки по правилу, первый элемент первого\n");
    printf("первый элемент второго, второй первого, второй второго и т.д.\n");
    printf("Список должен состоять из целых чисел!!!\n");
    while(1)
    {
        printf("Хотите ввести данные для первого списка? 1(да)/0(нет)\n");
        x=scanf("%d",&a); //нужна проверка
        if (x==0)
        {
            printf("Вы ввели некоректные данные, вводите только целые числа!\n");
            return 1;
        }
        if (a!=0 && a!=1)
        {
            printf("Вы ввели некоректные данные, вводите только целые числа!\n");
            return 1;
        }
        if (!a)
        {
            break;
        }
        T =(struct list *)malloc(sizeof(struct list));
        T->next=NULL;
        T->prev=NULL;
        printf("Введите данные для элемента\n");
        x=scanf("%d",&T->inf);    //нужна проверка
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
    while(1)
    {
        printf("Хотите ввести данные для второго списка? 1(да)/0(нет)\n");
        x=scanf("%d",&a); //нужна проверка
        if (x==0)
        {
            printf("Вы ввели некоректные данные, вводите только целые числа!\n");
            return 1;
        }
        if (a!=0 && a!=1)
        {
            printf("Вы ввели некоректные данные, вводите только целые числа!\n");
            return 1;
        }
        if (!a)
        {
            break;
        }
        T2 =(struct list *)malloc(sizeof(struct list));
        T2->next=NULL;
        T2->prev=NULL;
        printf("Введите данные для элемента\n");
        x=scanf("%d",&T2->inf);    //нужна проверка
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
        printf("Простите нельзя склеить того чего нет :(\n");
        return 0;
    }
    if (F2==NULL)
    {
        printf("Простите нельзя склеить того чего нет :(\n");
        return 0;
    }
    printf("Первый список\n");
    while(T!=NULL)
    {
        printf("%d ",T->inf);
        T=T->next;
    }
    printf("\nВторой список\n");
    T2=F2;
    while(T2!=NULL)
    {
        printf("%d ",T2->inf);
        T2=T2->next;
    }
    T=F;
    T2=F2;
    while(1)
    {
        T3 =(struct list *)malloc(sizeof(struct list));
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
    printf("\nРезультирующий список\n");
    T3=F3;
    while(T3!=NULL)
    {
        printf("%d ",T3->inf);
        T3=T3->next;
    }
    count -= count2;
    if (count<0)
        count*=-1;
    printf("\nОтстаточных элементов %d",count);
    return 0;
}
