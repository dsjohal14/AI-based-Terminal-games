#include<stdio.h>
#include<math.h>
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
void start_game();
void inputuser1(); // Taking input in multiplayer
void inputuser2(); // Taking input in multiplayer
void startgame();
char undo_mat[6][7], temp[6][7] ,game[6][7];
void matsame(char a[6][7],char b[6][7]);
int winner=0,t,l;
int depth = 8;// Difficulty of game - more depth more difficulty 
int maxcolwin[7]={0,0,0,0,0,0,0};// array for storing chance of winning by making first move in that column
char name1[20],name2[20];
void printgame(char ma[6][7]);
void inputcpu();
void delay(int number_of_seconds) // delay function 
{ 
    int micro_seconds = 1000000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + micro_seconds);
} 
int checkresult(char ma[6][7])
{

    // checking along row
    for(int i=5;i>=0;i--)
    {
        for(int j=0;j<=3;j++)
        {
            if(ma[i][j]==ma[i][j+1]&&ma[i][j]==ma[i][j+2]&&ma[i][j]==ma[i][j+3]&&ma[i][j]!='.')
            {
                if(ma[i][j]=='X') winner =1;
                if(ma[i][j]=='O') winner =2;
                return 1;
            }
        }
    }

    // checking along col
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(ma[i][j]==ma[i+1][j]&&ma[i][j]==ma[i+2][j]&&ma[i][j]==ma[i+3][j]&&ma[i][j]!='.')
            {
                if(ma[i][j]=='X') winner =1;
                if(ma[i][j]=='O') winner =2;
                return 1;
            }
        }
    }
    for(int i=5;i>=3;i--)
    {
        for(int j=6;j>=3;j--)
        {
            if(ma[i][j]==ma[i-1][j-1]&&ma[i][j]==ma[i-2][j-2]&&ma[i][j]==ma[i-3][j-3]&&ma[i][j]!='.')
            {
                if(ma[i][j]=='X') winner =1;
                if(ma[i][j]=='O') winner =2;
                return 1;
            }
        }
    }

    // checking along diagonals
    for(int i=5;i>=3;i--)
    {
        for(int j=0;j<=3;j++)
        {
            if(ma[i][j]==ma[i-1][j+1]&&ma[i][j]==ma[i-2][j+2]&&ma[i][j]==ma[i-3][j+3]&&ma[i][j]!='.')
            {
                if(ma[i][j]=='X') winner =1;
                if(ma[i][j]=='O') winner =2;
                return 1;
            }
        }
    }

    // checking for tie
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(game[i][j]=='.') return 0;
        }
    }
    return 1;
}
int checkinvalidmove()
{
    if(t>6||t<0)
        return 1;
    return 0;
}

// printing game
void printgame(char ma[6][7])
{
    system("clear");
    printf("\n\n\n\n                     1 2 3 4 5 6 7\n");
    for(int i=0;i<6;i++)
    {
        printf("                     ");
        
        for(int j=0;j<7;j++)
        {
            if(checkresult(game));
            if(game[i][j] == 'X')
            {
                printf(BLU"%c ",ma[i][j]);
                printf(RESET);
            }
            else if (game[i][j] == 'O')
            {
                printf(RED"%c ",ma[i][j]);
                printf(RESET);
            }
            else
            {
                printf("%c ",ma[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// user input in single player
void inputuser()
{
    printgame(game);
    int flag=0;
    printf("        Your turn (Enter a number from 1-7) : ");
    char m;
    scanf("%c",&m);
    t=m-49;
    if(checkinvalidmove()==1) 
    {
        printgame(game);
        printf("Invalid Move\n");
        inputuser();
        return;
    }
    for(int i=5;i>=0;i--)
    {
        if(game[i][t]=='.')
        {
            game[i][t]='X';
            flag++;
            break;
        }
    }
    if(flag==0)
    {
        printgame(game);
        printf("Invalid Move\n");
        inputuser();
        return;
    }
    printgame(game);
    if(checkresult(game))
    {
        if(winner==0)
        {
            printf("Match ended in tie\n");
        }
        else printf("You win.\n");
        return;
    }
    inputcpu();
}
//Making first matrix same as second matrix
void matsame(char a[6][7],char b[6][7])
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            a[i][j]=b[i][j];
        }
    }
}

//deciding for computer move
void decide(int n,int m)
{
    int i,v;
    char f;
    if(m==1) f='O';
    else f='X';
    if(n==0) return;
    for(int j=0;j<7;j++)
    {
        int flag=0;
        if(n==depth) l=j;
        for(i=5;i>=0;i--)
        {
            if(temp[i][j]=='.')
            {
                temp[i][j]=f;
                flag++;
                v=i;
                break;
            }
        }
        if(flag==1)
        {
            if(checkresult(temp))
            {
                if(n!=6){
                    if(winner==2)
                    maxcolwin[l]=maxcolwin[l]+(int)pow(10,n);
                    if(winner==1)
                    maxcolwin[l]=maxcolwin[l]-(int)pow(10,n);
                }
                //if its about to win in two moves it has to wait
                else {
                    if(winner==2)
                    maxcolwin[l]=maxcolwin[l]+(int)pow(10,n-1);
                    if(winner==1)
                    maxcolwin[l]=maxcolwin[l]-(int)pow(10,n-1);
                }
            }
            int t=n-1;
            int z=-m;
            winner=0;
            decide(t,z);
            temp[v][j]='.';
        }
    }
}
void inputcpu()
{
    printf("Wait! ,computer is thinking....\n");
    for (int i=0;i<7;i++)
    {
        maxcolwin[i] = 0;
    }
    matsame(temp,game);
    decide(depth,1);
    for(int i=0; i<=6; i++){
        if(game[0][i]!='.') maxcolwin[i]-=pow(10,9);// if column is already filled
    }
    printf("\n");
    int max=maxcolwin[0];
    int k=0;
    for(int x=1;x<=6;x++)
    {
        if(max<=maxcolwin[x]) 
        {
            max=maxcolwin[x];
            k=x;
        }
    }
    for(int i=5;i>=0;i--)
    {
        if(game[i][k]=='.')
        {
            game[i][k]='O';
            break;
        }
    }
    printgame(game);
    if(checkresult(game))
    {
        if(winner==0)
            printf("Match ended in tie\n");
        else 
            printf("Computer Wins! , Better luck next time.\n");
        return;
    }
    inputuser();
}
void read_instructions()
{
    system("clear");
    char ch;
    printf("\n\n\n             ....        HOW TO PLAY        .... \n\n\n");          
    printf("1. The aim of the game is to connect 4 (x) or 4 (0) vertically or\n  horizontally or diagonally \n");
    printf("2. The player who connect 4 more than the other will be the winner\n");
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
//function for filling matrix game in multiplayer just to save space
int input_multi_player(char c)
{

    int flag=0;
    if(t>6||t<0)
    {
        system("clear");
        printgame(game);
        
        if(c=='X')inputuser1();
        else inputuser2();
        return 0;
    }

    matsame(undo_mat,game);
    for(int i=5;i>=0;i--)
    {
        if(game[i][t]=='.')
        {
            game[i][t]=c;
            flag++;
            break;
        }
    }
    if(flag==0)
     {
        system("clear");
        printgame(game);
        printf("Invalid Move\n");
        if(c=='X') inputuser1();
        else inputuser2();
        return 0;
    }
    if(checkresult(game))
    {
        system("clear");
        printgame(game);
        if(winner==0)
        {
            printf("MATCH ENDED IN TIE\n");
            return 0;
        }
        if(winner=1) printf("%s wins.\n",name1);
        else printf("%s wins.\n",name2);
        return 0;
    }
        system("clear");
    printgame(game);
    return 1;
}
void inputuser1()// user 1 input in multiplayer
{
    printgame(game);
    printf("%s's turn (Enter a number from 1-7) ",name1);
    char m;
    scanf("%c",&m);
    t=m-49;
    int result=input_multi_player('X');
    if(result) inputuser2();
}
void inputuser2()// user 2 input in multiplayer
{

    printgame(game);
    printf("%s's turn (Enter a number from 1-7) ",name2);
    char m;
    scanf("%c",&m);
    t=m-49;
    int result=input_multi_player('O');
    if(result) inputuser1();
}
//displaying the start screen
void startgame()
{
    system("clear");
    printf(BLU "\n\n\n\n\n\n                         Welcome to CONNECT-4 Game\n\n\n\n\n\n"RESET);
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
                game[i][j]='.';
                undo_mat[i][j]='.';
                temp[i][j]='.';
        }
    }
    int option;
    printf("                1 PLAYER_1 vs PLAYER_2\n\n                2 PLAYER vs COMPUTER\n\n                3 READ INSTRUCTIONS\n\n                4 EXIT GAME\n\n       Dear human, please select any option : ");
    scanf("%d",&option);
    if(option==1)
    {
        system("clear");
        printf("        PLAYER 1 , ENTER YOUR NAME : ");
        scanf("%s",name1);
        printf("\n        PLAYER 2 , ENTER YOUR NAME : ");
        scanf("%s",name2);
        printgame(game);
        inputuser1();
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
            int o=rand()%7;
            o=abs(o);
            game[5][o]='O';
        }
        printgame(game);
        inputuser();
    }
    if(option==3)  read_instructions();
    if(option==4)
    {
        system("clear");
        system("exit");
    }
}
int main()
{
    system("clear");
    printf(BLU "\n\n\n\n\n\n                         Welcome to CONNECT-4 Game\n\n\n\n\n\n"RESET);
    delay(1);
    startgame();
    return 0;
}