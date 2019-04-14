#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
void startgame();
// declaring variables keeping all of them global so that they can be used in all functions
//diff=9 suggests that we will be dividing random number by 9
int i,j,k=0,x,y,chk=0,win=0,u_pos_a[5][2],u_pos_b[4][2],u_pos_d[3][2],u_pos_c[2][2],a=0,b=0,c=0,d=0,probab,diff=9;
    char grid_u[10][10],grid_u_v[10][10],grid_c[10][10],grid_c_v[10][10],orin[2],tempstr[10],ch;
void readinstructions()
{
    system("clear");
    printf("Get ready, for a war has been declared. Its time for some naval warfare.\n");
    printf("1.You have to defeat your opponent by destroying all his war ships before he destroys yours.\n");
    printf("2.They battlefield is a 10x10 grid where you place your ships\n");
    printf("3.You can place your ships by entering its orientation, i.e horizontal or vertical. For horizontal orientation, type 'h' in the orientation option and type 'v' for vertical\n");
    printf("4.And its x y coordinates(both separated by a space) where x is the row number and y is the column number\n");
    printf("4.You have a fleet of 4 battle ships: aircraft carrier(5 units long), battleship(4 units long), destroyer(3 units long) and corvette(2 units long)\n");
    printf("5.After placing your ships, you can attack the enemy area. To attack a specific area, enter its x y coordinate(separated by a space)\n");
    printf("6.If your attack hits the enemy ship, it will be denoted by an 'H'. And you get an extra turn\n");
    printf("7.If your attack misses, it will be denoted by a '*' and your turn ends\n");
    printf("Enter u to go back to main menu \n");
    printf("Enter q to quit the game\n");
    char input;
    scanf(" %c",&input);
    if(input=='u') {
        system("clear");
        startgame();
    }
    if(input=='q')
    {
        system("clear");
        ch=ch+1;
        return;
    }
}
// delay function
void delay(clock_t a)
{
    clock_t start = clock();
    while(clock()-start<a);
}   
// displaying start screen
void startgame()
{
    system("clear");
    printf(BLU "\n\n\n\n\n\n                                 Welcome to BATTLESHIP Game\n\n\n\n\n\n"RESET);
    for(i=0;i<20;i++)
    printf(" ");
    printf("1 PLAY BATTLESHIPS\n\n");
    for(i=0;i<20;i++)
        printf(" ");
    printf("2 RULES\n\n");
    for(i=0;i<20;i++)
        printf(" ");
    printf("3 EXIT MATCH\n\n\n");
    printf("Dear human, Enter any option : ");
    scanf(" %c",&ch);
    if(ch==49)
    {
        return;
    }
    if(ch==50)
    {
        readinstructions();
        return;
    }
    if(ch==51)
    {
        system("clear");
        system("exit");
    }
}
// function of printing of matrix
void print_grid(char a[10][10])
{
    for(i=0;i<10;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
        {
            if(a[i][j]=='A') printf(CYN"%c ",a[i][j]);
            else if(a[i][j]=='B') printf(BLU"%c ",a[i][j]);
            else if(a[i][j]=='C') printf(YEL"%c ",a[i][j]);
            else if(a[i][j]=='D') printf(GRN"%c ",a[i][j]);
            else if(a[i][j]=='H'||a[i][j]=='*'){
                    printf(RED"%c ",a[i][j]);
            }                
            else {
                printf(RESET"");
                printf("%c ",a[i][j]);
            }
            printf(RESET"");
        }
            
        printf("\n");
    }
}
int main()
{
    //A:Aircraft carrier
    //B:Battleship
    //D:destroyer
    //C:corvette
    printf(BLU "\n\n\n\n\n\n                         Welcome to BATTLESHIP Game\n\n\n\n\n\n"RESET);
    delay(1500);
    system("clear");
    startgame();
    if(ch==51)
    {
        system("clear");
        return 0;
    }
    system("clear");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            grid_c[i][j]='.';
            grid_u[i][j]='.';
            grid_c_v[i][j]='.';
        }
    }
    print_grid(grid_u);
    
   /* placing Aircraft carrier*/
    for(;;)
    {
        printf("Aircraft Carrier:\n");
        printf("Select Orientation (h/v): ");
        scanf("%s",orin);
        printf("x and y coordinates: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"h")==0)
        {
            if(y>5 || y<0 || x>9 || x<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
            else
            {
                for(i=y;i<y+5;i++)
                {
                    grid_u[x][i]='A';
                    u_pos_a[k][0]=x;
                    u_pos_a[k][1]=i;
                    k++;
                }
                break;
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>5 || x<0 || y>9 || y<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
             else
            {
                for(i=x;i<x+5;i++)
                {
                    grid_u[i][y]='A';
                    u_pos_a[k][0]=i;
                    u_pos_a[k][1]=y;
                    k++;
                }
                break;
            }
        }
    }
    k=0;
    system("clear");
    print_grid(grid_u);
    
    /* placing B:Battleship*/
    for(;;)
    {
        chk=0;
        printf("Battleship:\n");
        printf("Select Orientation (h/v): ");
        scanf("%s",orin);
        printf("x and y coordinates: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"h")==0)
        {
            if(y>6 || y<0 || x>9 || x<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
            else
            {

                for(i=y;i<y+4;i++)
                {
                    if(grid_u[x][i]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+4;i++)
                    {
                        grid_u[x][i]='B';
                        u_pos_b[k][0]=x;
                        u_pos_b[k][1]=i;
                        k++;
                    }
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>6 || x<0 || y>9 || y<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
             else
            {
                 for(i=x;i<x+4;i++)
                {
                    if(grid_u[i][y]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                   for(i=x;i<x+4;i++)
                    {
                        grid_u[i][y]='B';
                        u_pos_b[k][0]=i;
                        u_pos_b[k][1]=y;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    k=0;
    system("clear");
    print_grid(grid_u);
    
    /*placing Destroyer*/
    for(;;)
    {
        chk=0;
        printf("Destroyer:\n");
        printf("Select Orientation (h/v): ");
        scanf("%s",orin);
        printf("x and y coordinates: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"h")==0)
        {
            if(y>7 || y<0 || x>9 || x<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
            else
            {
                for(i=y;i<y+3;i++)
                {
                    if(grid_u[x][i]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+3;i++)
                    {
                        grid_u[x][i]='D';
                        u_pos_d[k][0]=x;
                        u_pos_d[k][1]=i;
                        k++;
                    }
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>7 || x<0 || y>9 || y<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
             else
            {
                 for(i=x;i<x+3;i++)
                {
                    if(grid_u[i][y]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+3;i++)
                    {
                        grid_u[i][y]='D';
                        u_pos_d[k][0]=i;
                        u_pos_d[k][1]=y;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    k=0;
    system("clear");
    print_grid(grid_u);
    
    /*placing Corvette*/
    for(;;)
    {
        chk=0;
        printf("Corvette:\n");
        printf("Select Orientation (h/v): ");
        scanf("%s",orin);
        printf("x and y coordinates: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"h")==0)
        {
            if(y>8 || y<0 || x>9 || x<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
            else
            {
                for(i=y;i<y+2;i++)
                {
                    if(grid_u[x][i]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+2;i++)
                    {
                        grid_u[x][i]='C';
                        u_pos_c[k][0]=x;
                        u_pos_c[k][1]=i;
                        k++;
                    }
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>8 || x<0 || y>9 || y<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
             else
            {
                 for(i=x;i<x+2;i++)
                {
                    if(grid_u[i][y]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+2;i++)
                    {
                        grid_u[i][y]='C';
                        u_pos_c[k][0]=i;
                        u_pos_c[k][1]=y;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    system("clear");
    print_grid(grid_u);
    
    srand(time(NULL));
    /*computer placing Aircraft carrier */
    for(;;)
    {
        if(rand()%2 == 1)
            strcpy(orin,"h");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"h")==0)
        {
            if(y>5 || y<0 || x>9 || x<0)
            {
                continue;
            }
            else
            {
                for(i=y;i<y+5;i++)
                    grid_c[x][i]='A';
                break;
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>5 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                for(i=x;i<x+5;i++)
                    grid_c[i][y]='A';
                break;
            }
        }
    }
    /*computer placing B:Battleship */
    for(;;)
    {
        chk=0;
        if(rand()%2 == 1)
            strcpy(orin,"h");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"h")==0)
        {
            if(y>6 || y<0 || x>9 || x<0)
                continue;
            else
            {
                for(i=y;i<y+4;i++)
                {
                    if(grid_c[x][i]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+4;i++)
                        grid_c[x][i]='B';
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>6 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                 for(i=x;i<x+4;i++)
                {
                    if(grid_c[i][y]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+4;i++)
                        grid_c[i][y]='B';
                    break;
                }
            }
        }
    }
    /*Computer placing Destroyer*/
    for(;;)
    {
        chk=0;
        if(rand()%2 == 1)
            strcpy(orin,"h");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"h")==0)
        {
            if(y>7 || y<0 || x>9 || x<0)
            {
               continue;
            }
            else
            {
                for(i=y;i<y+3;i++)
                {
                    if(grid_c[x][i]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+3;i++)
                        grid_c[x][i]='D';
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>7 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                 for(i=x;i<x+3;i++)
                {
                    if(grid_c[i][y]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+3;i++)
                        grid_c[i][y]='D';
                    break;
                }
            }
        }
    }
    /*Computer placing Corvette */
    for(;;)
    {
        chk=0;
        if(rand()%2 == 1)
            strcpy(orin,"h");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"h")==0)
        {
            if(y>8 || y<0 || x>9 || x<0)
            {
                continue;
            }
            else
            {
                for(i=y;i<y+2;i++)
                {
                    if(grid_c[x][i]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+2;i++)
                        grid_c[x][i]='C';
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>8 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                 for(i=x;i<x+2;i++)
                {
                    if(grid_c[i][y]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+2;i++)
                        grid_c[i][y]='C';
                    break;
                }
            }
        }
    }
    // equating matrix to store its value for allowing computer to make changes
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            grid_u_v[i][j]=grid_u[i][j];
    }

    for(;;)
    {
        system("clear");
        print_grid(grid_c_v);
        printf("\n");
        print_grid(grid_u_v);

        for(;;)
        {
            printf("Enter x and y: ");// asking for row and column respectively to hit
            scanf("%d %d", &x,&y);
            if(x>9 || x<0 || y>9 || y<0 || grid_c_v[x][y]=='H' || grid_c_v[x][y]=='*')
            {
                printf("Invalid input. Try again\n");
                continue;
            }
            else
            {
                if(grid_c[x][y]=='A' || grid_c[x][y]=='B'||grid_c[x][y]=='C'||grid_c[x][y]=='D')
                {
                    if(grid_c_v[x][y]!='H')
                    {
                        grid_c_v[x][y]='H';
                        system("clear");
                        print_grid(grid_c_v);
                        printf("\n");
                        print_grid(grid_u_v);
                        
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<10;j++)
                            {
                                if(grid_c_v[i][j]=='H')
                                    win++;
                            }
                        }
                        if(win==14)
                        {
                            printf("\nYou win!\n");
                            break;
                        }
                        win=0;
                        continue;
                    }
                    else
                    {
                        printf("Invalid Input. Try again\n");
                        continue;
                    }
                }
                else
                {
                    grid_c_v[x][y]='*';
                    break;
                }
            }
        }
        if(win==14)
            break;
        for(;;)
        {
            // finding probab
            probab=rand()%diff;
            if(probab==diff-3&& a<5) // hitting at first ship
            {
                x=u_pos_a[a][0];
                y=u_pos_a[a][1];
                a++;
            }
            else if(probab==diff-2 && b<4) // hitting at second ship
            {
                x=u_pos_b[b][0];
                y=u_pos_b[b][1];
                b++;
            }
            else if(probab==diff-5 && d<3) // hitting at third ship
            {
                x=u_pos_d[d][0];
                y=u_pos_d[d][1];
                d++;
            }
            else if(probab==diff-6 && c<2) // hitting at fourth ship
            {
                x=u_pos_c[c][0];
                y=u_pos_c[c][1];
                c++;
            }
            else // cpu making a random move
            {
                x=rand()%10;
                y=rand()%10;
            }
            if(x>9 || x<0 || y>9 || y<0 || grid_u_v[x][y]=='H' || grid_u_v[x][y]=='*')
            {
                continue;
            }
            else
            {
                if(grid_u[x][y]=='A' || grid_u[x][y]=='B'||grid_u[x][y]=='C'||grid_u[x][y]=='D')
                {
                    if(grid_u_v[x][y]!='H')
                    {
                        grid_u_v[x][y]='H';
                        system("clear");
                        print_grid(grid_c_v);
                        printf("\n");
                        print_grid(grid_u_v);
                        delay(1000);
                        continue;
                    }
                    else
                        continue;
                }
                else
                {
                    grid_u_v[x][y]='*';
                    break;
                }
            }

        }
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(grid_c_v[i][j]=='H')
                    win++;
            }
        }
        if(win==14)// checking result
        {
            printf("\nYou win!\n");
            break;
        }
        win=0;
        // checking for our loss
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(grid_u_v[i][j]=='H')
                    win++;
            }
        }
        if(win==14)
        {
            printf("\nYou lose!\n");
            break;
        }
        win=0;
    }
    return 0;
}