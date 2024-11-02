/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#define L 20
#define H 30*20+20
int main()
{
    char str[L*H], ch, *str_new[L*H], *str_help[L];
    char* token;
    int i=0,world=0,k,n,count=0,x,j;
    setlocale(0,"");
    printf("Введите предложение\n");
    scanf("%c",&ch);
    while(1)
    {
        while((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
        {
            str[i]=ch;
            i++;
            world++;
            if(world>L)
            {
                printf("Слово слишком большое");
                return 0;
            }
            if (i>L*H-1)
            {
                printf("Строка переполнена");
                return 0;
            }
            scanf("%c",&ch);
        }
        world=0;
        if (ch!='.'&&ch!='!'&&ch!='?'&&ch!=' ')
        {
            printf("Это не буква и не пробел. Меняй");
            return 1;
        }
        if (ch==' ' && i!=0)
        {
            str[i]=' ';
            i++;
            if (i>L*H-1)
            {
                printf("Строка переполнена");
                return 0;
            }
        }
        while(ch==' ')
            scanf("%c",&ch);
        if(ch=='.'||ch=='!'||ch=='?')
        {
            str[i]='\0';
            break;
        }
    }
    printf("%s\n",str);
    printf("Введите номера слов, которые хотите поменять местами\n");
    x=scanf("%d\n",&k);
    k--;
    if(x==0)
    {
        printf("Вводите только целые числа");
        return 1;
    }
    if(k<0)
    {
        printf("Вводите положительные числа");
        return 1;
    }
    x=scanf("%d",&n);
    n--;
    if(x==0)
    {
        printf("Вводите только целые числа");
        return 1;
    }
    if(n<0)
    {
        printf("Вводите положительные числа");
        return 1;
    }
    token = strtok (str, " ");
    i=0;
    while (token != NULL)
    {
        str_new[i]=strdup(token);
        i++;
        count++;
        token = strtok (NULL, " ");
    }
    if(k>count||n>count)
    {
        printf("Таких номеров слов нет\n");
        return 0;
    }
    str_help[0]=str_new[k];
    str_new[k]=str_new[n];
    str_new[n]=str_help[0];
    for(i=0;i<count;i++)
    {
        for(j=0;j<L;j++)
        {
            printf("%c",str_new[i][j]);
        }
        printf(" ");
    }
    return 0;
}
