#include<stdio.h>
#include<stdlib.h>
int winner=0,t;
char mat[6][7];
int keepcheck[7]={0,0,0,0,0,0,0};
void input1();
void input2();
void printmatrix();
int checkinvalidmove()
{
    if(keepcheck[t]>5)
    {
        system("clear");
        printf("Invalid Move\n");
        printmatrix();
        return 1;
    }
    return 0;
}
void printmatrix()
{
    printf("1 2 3 4 5 6 7\n");
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            printf("%c ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int checkrow()
{
    for(int i=5;i>=0;i--)
    {
        for(int j=0;j<=3;j++)
        {
            if(mat[i][j]==mat[i][j+1]&&mat[i][j]==mat[i][j+2]&&mat[i][j]==mat[i][j+3]&&mat[i][j]!='*')
            {
                if(mat[i][j]=='a') winner =1;
                if(mat[i][j]=='b') winner =2;
                return 1;
            }
        }
    }
    return 0;
}
int checkcol()
{
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(mat[i][j]==mat[i+1][j]&&mat[i][j]==mat[i+2][j]&&mat[i][j]==mat[i+3][j]&&mat[i][j]!='*')
            {
                if(mat[i][j]=='a') winner =1;
                if(mat[i][j]=='b') winner =2;
                return 1;
            }
        }
    }
    return 0;
}
int checkdia1()
{
    for(int i=5;i>=3;i--)
    {
        for(int j=6;j>=3;j--)
        {
            if(mat[i][j]==mat[i-1][j-1]&&mat[i][j]==mat[i-2][j-2]&&mat[i][j]==mat[i-3][j-3]&&mat[i][j]!='*')
            {
                if(mat[i][j]=='a') winner =1;
                if(mat[i][j]=='b') winner =2;
                return 1;
            }
        }
    }
    return 0;
}
int checkdia2()
{
    for(int i=5;i>=3;i--)
    {
        for(int j=0;j<=3;j++)
        {
            if(mat[i][j]==mat[i-1][j+1]&&mat[i][j]==mat[i-2][j+2]&&mat[i][j]==mat[i-3][j+3]&&mat[i][j]!='*')
            {
                if(mat[i][j]=='a') winner =1;
                if(mat[i][j]=='b') winner =2;
                return 1;
            }
        }
    }
    return 0;
}
void input1()
{
    printf("Player 1 turn (Enter a number from 1-7) ");
    int m;
    scanf("%d",&m);
    t=m-1;
    if(t>6||t<0)
    {
        system("clear");
        printf("Invalid Move\n");
        printmatrix();
        input1();
        return;
    }
    if(checkinvalidmove()==1) 
    {
        input1();
        return;
    }
    for(int i=5;i>=0;i--)
    {
        if(mat[i][t]=='*')
        {
            mat[i][t]='a';
            break;
        }
    }
    keepcheck[t]=keepcheck[t]+1;
    if(checkcol()||checkdia1()||checkrow()||checkdia2())
    {
        system("clear");
        printmatrix();
        printf("Player %d wins.\n",winner);
        return;
    }
    if(winner==0)
    {
        system("clear");
        printmatrix();
        input2();
    }
}
void input2()
{
    printf("Player 2 turn (Enter a number from 1-7) ");
    int m;
    scanf("%d",&m);
    t=m-1;
    if(t>6||t<0)
    {
        system("clear");
        printf("Invalid Move\n");
        printmatrix();
        input2();
    }
    if(checkinvalidmove()==1)
    {
        input2();
        return;
    }
    for(int i=5;i>=0;i--)
    {
        if(mat[i][t]=='*')
        {
            mat[i][t]='b';
            keepcheck[t]=keepcheck[t]+1;
            break;
        }
    }
    if(checkcol()||checkdia1()||checkrow()||checkdia2())
    {
        system("clear");
        printmatrix();
        printf("Player %d wins.\n",winner);
    }
    if(winner==0)
    {
        system("clear");
        printmatrix();
        input1();
    }
}
int main()
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            mat[i][j]='*';
        }
    }
    printf("Welcome to CONNECT-4 Game\n\n");
    printmatrix();
    input1();
    return 0;
}