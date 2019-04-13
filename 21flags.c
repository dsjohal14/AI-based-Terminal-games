#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
int noflags=21;
void startgame();
void input_singleplayer();
void input_com();
char name1[20],name2[20];
void delay(int number_of_seconds) 
{ 
    int micro_seconds = 1000000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + micro_seconds);
}
void printgame()
{

    system("clear");
    for(int i=0;i<noflags;i++)
    {
        if(i<9)
            printf("%d  ",i+1);
        else
            printf("%d ",i+1);
    }
        printf("\n\n");
    for(int i=0;i<noflags;i++)
    {
        printf(GRN"|> ");
    } 
    printf("\n");
    for(int i=0;i<noflags;i++)
    {
        printf("|  ");
    }
    printf(RESET"\n\n\n");
}
void input_com()
{
    printgame();
    printf("\n\nWait ! , Computer is thinking ....\n");
    delay(1);
    if(noflags==1)
    {
        noflags=0;
        system("clear");
        printf(YEL"\n\n\n          Congratulations , You Win !\n\n\n"RESET);
        return;
    }
    if(noflags==17||noflags==13||noflags==9||noflags==5)
    {
        int rmvflags=abs(rand()%2)+1;
        noflags-=rmvflags;
        input_singleplayer();
        return;
    }
    if(noflags<21&&noflags>17)
    {
        noflags=17;
        input_singleplayer();
        return;
    }
    if(noflags<17&&noflags>13)
    {
        noflags=13;
        input_singleplayer();
        return;
    }
    if(noflags<13&&noflags>9)
    {
        noflags=9;
        input_singleplayer();
        return;
    }
    if(noflags<9&&noflags>5)
    {
        noflags=5;
        input_singleplayer();
        return;
    }
    if(noflags<5&&noflags>1)
    {
        noflags=1;
        input_singleplayer();
        return;
    }
}
void input_singleplayer()
{
    printgame();
    int rmvflags;
    printf("Your turn... Enter number of flags you want to remove(1-3) : ");
    scanf("%d",&rmvflags);
    if(rmvflags>3||noflags-rmvflags<0)
    {
        system("clear");
        input_singleplayer();
        return;
    }
    noflags-=rmvflags;
    if(noflags==0)
    {
        system("clear");
        printf(GRN"\n\n\n                      YOU LOSE"RESET);
        printf(RED"\n\n     Well played ,But you have been outsmarted by computer\n\n\n"RESET);
        return;
    }
    input_com();
}
void input_multiuser(int t)
{
    printgame();
    if(t==0)
        printf("%s's turn ...Enter number of flags you want to remove (1-3) :",name1);
    if(t==1)
        printf("%s's turn ...Enter number of flags you want to remove (1-3) :",name2);
    int out_flags;
    scanf("%d",&out_flags);
    if(noflags-out_flags<0||out_flags>3||out_flags<1)
    {
        printgame();
        printf("Invalid Move\n");
        input_multiuser(t);
        return;
    }
    noflags-=out_flags;
    if(noflags==0)
    {
        system("clear");
        if(t==0)
            printf("\n\n\n            Congratulations %s ,You Win\n\n\n",name2);
        if(t==1)
            printf("\n\n\n            Congratulations %s ,You Win\n\n\n",name1);  
        return;
    }
    if(t==0)
        input_multiuser(1);
    if(t==1)
        input_multiuser(0);
}
void read_instructions()
{
    system("clear");
    printf(GRN "\n\n\n                   ....        HOW TO PLAY        .... \n\n\n"RESET);
    printf("1 There are 21 flags. You must strategize to select one, two, or three flags to remove at a time. \nYou will be alternating turns with the computer/opponent. The object of the game is to make opponent \nremove (grab) the last flag.");
    printf("2 Player who picks up last flag loses.\n");
    printf("Enter u to go back to main menu \n");
    printf("Enter q to quit the game\n");
    char input;
    scanf(" %c",&input);
    if(input=='u') startgame();
    if(input=='q')
    {
        system("clear");
        system("exit");
    }
}
void startgame()
{
    printf(BLU "\n\n\n\n\n\n                         Welcome to 21 FLAGS Game\n\n\n\n\n\n"RESET);
    int option;
    printf("                1 PLAYER_1 vs PLAYER_2\n\n                2 PLAYER vs COMPUTER\n\n                3 READ INSTRUCTIONS\n\n                4 EXIT GAME\n\n       Dear human, please select any option : ");
    scanf("%d",&option);
    if(option==1)
    {
        system("clear");
        printf("        PLAYER 1 , ENTER YOUR NAME : ");
        scanf("%s",name1);
        printf("        PLAYER 2 , ENTER YOUR NAME : ");
        scanf("%s",name2);
        input_multiuser(0);
    }
    if(option==2)
    {
        system("clear");
        printf("        PLAYER , ENTER YOUR NAME : ");
        scanf("%s",name1);
        srand(time(0));
        int t=rand()%2;
        t=abs(t);
        if(t==1)
        {
            int rmvflags=abs(rand()%3);
            noflags-=rmvflags;
            input_singleplayer();
        }
        else
        {
            input_singleplayer();
        }
        
    }
    if(option==3)
    {
        read_instructions();
    }
    if(option==4)
    {
        system("clear");
        system("exit");
    }

}
int main()
{
    system("clear");
    int n=21;
    printf(BLU "\n\n\n\n\n\n                         Welcome to 21 FLAGS Game\n\n\n\n\n\n"RESET);
    delay(1);
    system("clear");
    startgame();
}