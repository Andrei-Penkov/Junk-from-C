#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define L 21
#define H 30

void Glue(char str_help[1][L], char matr[H][L], int k, int n)
{
    int j=0;
    while(matr[k][j]!='\0')
    {
        str_help[0][j]=matr[k][j];
        j++;
    }
    str_help[0][j]='\0';
    j=0;
    while(matr[n][j]!='\0')
    {
        matr[k][j]=matr[n][j];
        j++;
    }
    matr[k][j]='\0';
    j=0;
    while(str_help[0][j]!='\0')
    {
        matr[n][j]=str_help[0][j];
        j++;
    }
    matr[n][j]='\0';
}

int main()
{
    char matr[H][L], ch, str_help[1][L];
    int i=0, j=0, letter=0, word=0,k,n,x;
    printf("Введите предложение\n");
    scanf("%c",&ch);
    while(1)
    {
        while((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
        {
            matr[i][j]=ch;
            j+=1;
            letter++;
            if (letter>L-1)
            {
                printf("Слишком много букв в слове");
                return 0;
            }
            scanf("%c",&ch);
        }
        if((ch==' '||ch=='.')&&(j!=0))
        {
            matr[i][j]='\0';
            word+=1;
            i++;
            letter=0;
            j=0;     
        }
        if (word>H)
        {
            printf("Слишком много слов");
            return 0;
        }
        while(ch==' ')
            scanf("%c",&ch);
        if(ch=='.'||ch=='!'||ch=='?')
        {
            break;
        }
        if (!((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')))
        {
            printf("Неизвестный символ");
            return 1;
        }
    }
    printf("Количество слов %d\n",word);
    if(matr[0][0]==0)
    {
        printf("Вы забыли ввести предложение");
        return 0;
    }
    printf("Enter the numbers of the words you want to swap\n");
    x=scanf("%d\n",&k);
    k--;
    if(x==0)
    {
        printf("Enter only integers");
        return 1;
    }
    if(k<0)
    {
        printf("Numbering from 1 and not from 0");
        return 1;
    }
    x=scanf("%d",&n);
    n--;
    if(x==0)
    {
        printf("Enter only integers");
        return 1;
    }
    if(n<0)
    {
        printf("Numbering from 1 and not from 0");
        return 1;
    }
    if(k>word-1||n>word-1)
    {
        printf("Такакого номера нет");
        return 1;
    }
    Glue(str_help,matr,k,n);
    for(i=0;i<word;i++)
        printf("%s ",matr[i]);
    return 0;
}


