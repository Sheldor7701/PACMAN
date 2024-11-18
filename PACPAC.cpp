# include "iGraphics.h"
#include<math.h>
#include<stdbool.h>
#include<bits/stdc++.h>
using namespace std;

int x=0,y=0,svk=1,svk1=1,svk2=1,svk3=1, move=0,Life=3,new_game=1,resume=0,high2=0,win=0,ghost_freeze=0, freeze_time=0;

double ghost_1_distance=50000,ghost_2_distance=50000,ghost_3_distance=50000,ghost_4_distance=50000;

double ghost_1_dik=0,ghost_2_dik=0,ghost_3_dik=0,ghost_4_dik=0,g_speed=250, morsi=1;

long long j=9, i=13, a=6, b=3,R=255,G=255,B=255;

long long point=0,start=-2,second=0,minute=0, food=189;

char score[7],time_out[10],high[10],sec[5],mnt[5];

bool change=0,scatter1=0,scatter2=0,scatter3=0,scatter4=0,gafraid=0,g1afraid=0,g2afraid=0,g3afraid=0,musicon=1;



int highscore[10];


char* brick1="block7.bmp";
char* brick2="block8.bmp";
char* brick3="block9.bmp";

struct pacman
{
    int i;
    int j;
    int x;
    int y;
};


    pacman ghost_1={1,17};
    pacman ghost_2={19,17};
    pacman ghost_3={19,1};
    pacman ghost_4={1,1};



void timechange()
{
    if(start==1)
        {
            second++;
            if(second==60)
            {
                minute++;
                second=0;
            }
        }
        itoa(second,sec,10);
        itoa(minute,mnt,10);
    if(ghost_freeze==1)
    {
        freeze_time++;
        if(freeze_time>=5)
        {
            ghost_freeze=0;
            freeze_time=0;
        }
    }
}

void scatter_mode()
{
    if(ghost_1.i==1 && ghost_1.j==17)
    {
        scatter1=0;
        gafraid=0;
    }
    if(ghost_2.i==19 && ghost_2.j==17)
    {
        scatter2=0;
        g1afraid=0;
    }
    if(ghost_3.i==19 && ghost_3.j==1)
    {
        scatter3=0;
        g2afraid=0;
    }
    if(ghost_4.i==1 && ghost_4.j==1)
    {
        scatter4=0;
        g3afraid=0;
    }
}


int maze_1[21][19]=
                {
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
                                0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0,
                                0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                                0, 3, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 3, 0,
                                0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
                                0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0,
                                -1, -1, -1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, -1, -1, -1,
                                0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0,
                                1, 1, 1, 1, 1, 1, 1, 0, 5, 0, 5, 0, 1, 1, 1, 1, 1, 1, 1,
                                0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0,
                                -1, -1, -1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, -1, -1, -1,
                                0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
                                0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0,
                                0, 3, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 3, 0,
                                0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
                                0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,


                };
    int maze_2[21][19];


void readmaze()
{
    int ax,ay;
    FILE* fp=NULL;
    fp = fopen("maze.txt","r+");

    fscanf(fp, "%d", &resume);

    for(ax=0;ax<21;ax++)
            for(ay=0;ay<19;ay++)
                fscanf(fp, "%d", &maze_2[ax][ay]);

    fscanf(fp, "%d", &point);
    fscanf(fp, "%d", &food);
    fscanf(fp, "%d", &Life);
    fscanf(fp, "%d", &second);
    fscanf(fp, "%d", &minute);

    for(x=0;x<10;x++)
            fscanf(fp, "%d", &highscore[x]);


    fclose(fp);
}

void writemaze()
{
    FILE* fp=NULL;
    fp= fopen("maze.txt","w+");

    fprintf(fp, "%d\n", resume);

    for(x=0;x<21;x++)
            {
                for(y=0;y<19;y++)
                    fprintf(fp, "%d\n", maze_2[x][y]);
            }
    fprintf(fp, "%d\n", point);
    fprintf(fp, "%d\n", food);
    fprintf(fp, "%d\n", Life);
    fprintf(fp, "%d\n", second);
    fprintf(fp, "%d\n", minute);

    for(x=0;x<10;x++)
            fprintf(fp, "%d\n", highscore[x]);

    fclose(fp);
}

void pac_new_game()
{
    ghost_1={1,17};
        ghost_2={19,17};
        ghost_3={19,1};
        ghost_4={1,1};
        i=13;
        j=9;

    for(x=0;x<21;x++)
        for(y=0;y<19;y++)
                    maze_2[x][y]=maze_1[x][y];

    Life=3;
    point=0;
    second=0;
    minute=0;
    scatter1=0;scatter2=0;scatter3=0;scatter4=0;gafraid=0;g1afraid=0;g2afraid=0;g3afraid=0;
    new_game=0;
    resume=1;
    food=189;
    high2=0;
    win=0;
    ghost_freeze=0;
}

void pac_start()
{
        ghost_1={1,17};
        ghost_2={19,17};
        ghost_3={19,1};
        ghost_4={1,1};
        i=13;
        j=9;
        scatter1=0;scatter2=0;scatter3=0;scatter4=0;gafraid=0;g1afraid=0;g2afraid=0;g3afraid=0;
}

void image_change()
{
    if(change==0)
        change=1;
    else
        change=0;
}


void death()
{
    if(scatter1==0 && ghost_freeze==0)
    {
    if(ghost_1.i==i && ghost_1.j==j)
    {
        Life--;
        start=0;
        morsi=1;

    }
    }
    if(scatter2==0 && ghost_freeze==0)
    {
    if(ghost_2.i==i && ghost_2.j==j)
    {
        Life--;
        start=0;
        morsi=1;
    }
    }
    if(scatter3==0 && ghost_freeze==0)
    {
    if(ghost_3.i==i && ghost_3.j==j)
    {
        Life--;
        start=0;
        morsi=1;
    }
    }
    if(scatter4==0 && ghost_freeze==0)
    {
    if(ghost_4.i==i && ghost_4.j==j)
    {
        Life--;
        start=0;
        morsi=1;
    }
    }

    if(scatter1==1 && ghost_1.i==i && ghost_1.j==j)
    {
        gafraid=1;
        point+=20;
    }
    if(scatter2==1 && ghost_2.i==i && ghost_2.j==j)
    {
        g1afraid=1;
        point+=20;
    }
    if(scatter3==1 && ghost_3.i==i && ghost_3.j==j)
    {
        g2afraid=1;
        point+=20;
    }
    if(scatter4==1 && ghost_4.i==i && ghost_4.j==j)
    {
        g3afraid=1;
        point+=20;
    }
}

void pacmove()
{
    if(start==1)
    {
    if(move==1 && maze_1[i-1][j])
        i--;
    else if(move==2 && maze_1[i][j+1])
        j++;
    else if(move==3 && maze_1[i+1][j])
        i++;
    else if(move==4 && maze_1[i][j-1])
        j--;
    else if(j==18 && move==2)
        j=0;
    else if(j==0 && move==4)
        j=18;
    }
}


void pacfunc()
    {
        if(maze_2[i][j]==1)
        {
            point+=10;

            food--;
            maze_2[i][j]=2;
        }

        if(maze_2[i][j]==3)
        {
            point+=50;
            itoa(point,score,10);

            scatter1=1;
            scatter2=1;
            scatter3=1;
            scatter4=1;
            food--;
            maze_2[i][j]=2;
        }
        if(maze_2[i][j]==5)
        {
            point+=30;
            itoa(point,score,10);

            ghost_freeze=1;
            food--;
            maze_2[i][j]=2;
        }

        if(move==0)
            iShowBMP(300+25*j,600-25*i,"Pac_rgt_2.bmp");
        if(move==1)
        {
            if(change==0)
            iShowBMP(300+25*j,600-25*i,"Pac_upp_2.bmp");
            else
            iShowBMP(300+25*j,600-25*i,"Pac_upp.bmp");
        }
        if(move==2)
        {
            if(change==0)
            iShowBMP(300+25*j,600-25*i,"Pac_rgt_2.bmp");
            else
            iShowBMP(300+25*j,600-25*i,"Pac_rgt.bmp");
        }
        if(move==3)
        {
            if(change==0)
            iShowBMP(300+25*j,600-25*i,"Pac_dwn_2.bmp");
            else
            iShowBMP(300+25*j,600-25*i,"Pac_dwn.bmp");
        }
        if(move==4)
        {
            if(change==0)
            iShowBMP(300+25*j,600-25*i,"Pac_lft_2.bmp");
            else
            iShowBMP(300+25*j,600-25*i,"Pac_lft.bmp");
        }
    }



void ghostrun()
{
if(start==1 && ghost_freeze==0)
{

    if(scatter1==0)
{
    ghost_1_dik=0;
    ghost_1_distance=500000;

if(svk==1)
{

    if(maze_1[ghost_1.i-1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i-1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=1;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j-1] )
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j-1;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=4;
            }

    }

    if(maze_1[ghost_1.i+1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i+1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=3;
            }
    }

    if(maze_1[ghost_1.i+1][ghost_1.j]&& ghost_1_dik==0 )
    {
        ghost_1.x=ghost_1.i+1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=3;
            }
    }

    if(ghost_1_dik==1)
        {ghost_1.i--;svk=1;}
    else if(ghost_1_dik==2)
        {ghost_1.j++;svk=2;}
    else if(ghost_1_dik==3)
        {ghost_1.i++;svk=3;}
    else if(ghost_1_dik==4)
        {ghost_1.j--;svk=4;}

}


else if(svk==2)
{

    if(maze_1[ghost_1.i-1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i-1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=1;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j+1])
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j+1;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=2;
            }
    }
    if(maze_1[ghost_1.i+1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i+1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=3;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j-1] && ghost_1_dik==0 )
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j-1;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=4;
            }

    }

    if(ghost_1_dik==1)
        {ghost_1.i--;svk=1;}
    else if(ghost_1_dik==2)
        {ghost_1.j++;svk=2;}
    else if(ghost_1_dik==3)
        {ghost_1.i++;svk=3;}
    else if(ghost_1_dik==4)
        {ghost_1.j--;svk=4;}

}


else if(svk==3)
{

    if(maze_1[ghost_1.i][ghost_1.j+1])
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j+1;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=2;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j-1] )
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j-1;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=4;
            }

    }
    if(maze_1[ghost_1.i+1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i+1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=3;
            }
    }

    if(maze_1[ghost_1.i-1][ghost_1.j] && ghost_1_dik==0)
    {
        ghost_1.x=ghost_1.i-1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=1;
            }
    }

    if(ghost_1_dik==1)
        {ghost_1.i--;svk=1;}
    else if(ghost_1_dik==2)
        {ghost_1.j++;svk=2;}
    else if(ghost_1_dik==3)
        {ghost_1.i++;svk=3;}
    else if(ghost_1_dik==4)
        {ghost_1.j--;svk=4;}

}

else if(svk==4)
{

    if(maze_1[ghost_1.i-1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i-1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=1;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j-1] )
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j-1;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=4;
            }

    }
    if(maze_1[ghost_1.i+1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i+1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=3;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j+1]&& ghost_1_dik==0 )
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j+1;

        if(ghost_1_distance>((ghost_1.x-i-4)*(ghost_1.x-i-4)+(ghost_1.y-j-4)*(ghost_1.y-j-4)))
            {
                ghost_1_distance = (ghost_1.x-i)*(ghost_1.x-i)+(ghost_1.y-j)*(ghost_1.y-j);
                ghost_1_dik=2;
            }
    }

    if(ghost_1_dik==1)
        {ghost_1.i--;svk=1;}
    else if(ghost_1_dik==2)
        {ghost_1.j++;svk=2;}
    else if(ghost_1_dik==3)
        {ghost_1.i++;svk=3;}
    else if(ghost_1_dik==4)
        {ghost_1.j--;svk=4;}

}
}

    else

        {
    ghost_1_dik=0;
    ghost_1_distance=500000;

    if(svk==2)
{

    if(maze_1[ghost_1.i-1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i-1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=1;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j+1])
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j+1;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=2;
            }
    }

    if(maze_1[ghost_1.i+1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i+1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=3;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j-1] && ghost_1_dik==0)
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j-1;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=4;
            }
    }

    if(ghost_1_dik==1)
        {ghost_1.i--;svk=1;}
    else if(ghost_1_dik==2)
        {ghost_1.j++;svk=2;}
    else if(ghost_1_dik==3)
        {ghost_1.i++;svk=3;}
    else if(ghost_1_dik==4)
        {ghost_1.j--;svk=4;}

}


else if(svk==1)
{

    if(maze_1[ghost_1.i-1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i-1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=1;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j+1])
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j+1;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=2;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j-1])
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j-1;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=4;
            }
    }

    if(maze_1[ghost_1.i+1][ghost_1.j] && ghost_1_dik==0)
    {
        ghost_1.x=ghost_1.i+1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=3;
            }
    }

    if(ghost_1_dik==1)
        {ghost_1.i--;svk=1;}
    else if(ghost_1_dik==2)
        {ghost_1.j++;svk=2;}
    else if(ghost_1_dik==3)
        {ghost_1.i++;svk=3;}
    else if(ghost_1_dik==4)
        {ghost_1.j--;svk=4;}

}


else if(svk==3)
{

    if(maze_1[ghost_1.i][ghost_1.j-1])
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j-1;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=4;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j+1])
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j+1;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=2;
            }
    }

    if(maze_1[ghost_1.i+1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i+1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=3;
            }
    }

    if(maze_1[ghost_1.i-1][ghost_1.j] && ghost_1_dik==0)
    {
        ghost_1.x=ghost_1.i-1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=1;
            }
    }

    if(ghost_1_dik==1)
        {ghost_1.i--;svk=1;}
    else if(ghost_1_dik==2)
        {ghost_1.j++;svk=2;}
    else if(ghost_1_dik==3)
        {ghost_1.i++;svk=3;}
    else if(ghost_1_dik==4)
        {ghost_1.j--;svk=4;}

}


else if(svk==4)
{

    if(maze_1[ghost_1.i-1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i-1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=1;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j-1] )
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j-1;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=4;
            }
    }

    if(maze_1[ghost_1.i+1][ghost_1.j])
    {
        ghost_1.x=ghost_1.i+1;ghost_1.y=ghost_1.j;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=3;
            }
    }

    if(maze_1[ghost_1.i][ghost_1.j+1] && ghost_1_dik==0)
    {
        ghost_1.x=ghost_1.i;ghost_1.y=ghost_1.j+1;

        if(ghost_1_distance>((ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17)))
            {
                ghost_1_distance = (ghost_1.x-1)*(ghost_1.x-1)+(ghost_1.y-17)*(ghost_1.y-17);
                ghost_1_dik=2;
            }
    }

    if(ghost_1_dik==1)
        {ghost_1.i--;svk=1;}
    else if(ghost_1_dik==2)
        {ghost_1.j++;svk=2;}
    else if(ghost_1_dik==3)
        {ghost_1.i++;svk=3;}
    else if(ghost_1_dik==4)
        {ghost_1.j--;svk=4;}

}

}
}
}


void ghostrun1()
{
    if(start==1 && ghost_freeze==0)
{
    if(scatter2==0)
    {
    ghost_2_dik=0;
    ghost_2_distance=500000;

    if(svk1==2)
{

    if(maze_1[ghost_2.i-1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i-1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=1;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j+1])
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j+1;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=2;
            }
    }

    if(maze_1[ghost_2.i+1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i+1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=3;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j-1] && ghost_2_dik==0)
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j-1;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=4;
            }
    }

    if(ghost_2_dik==1)
        {ghost_2.i--;svk1=1;}
    else if(ghost_2_dik==2)
        {ghost_2.j++;svk1=2;}
    else if(ghost_2_dik==3)
        {ghost_2.i++;svk1=3;}
    else if(ghost_2_dik==4)
        {ghost_2.j--;svk1=4;}

}


else if(svk1==1)
{

    if(maze_1[ghost_2.i-1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i-1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=1;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j+1])
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j+1;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=2;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j-1])
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j-1;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=4;
            }
    }

    if(maze_1[ghost_2.i+1][ghost_2.j] && ghost_2_dik==0)
    {
        ghost_2.x=ghost_2.i+1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=3;
            }
    }

    if(ghost_2_dik==1)
        {ghost_2.i--;svk1=1;}
    else if(ghost_2_dik==2)
        {ghost_2.j++;svk1=2;}
    else if(ghost_2_dik==3)
        {ghost_2.i++;svk1=3;}
    else if(ghost_2_dik==4)
        {ghost_2.j--;svk1=4;}

}


else if(svk1==3)
{

    if(maze_1[ghost_2.i][ghost_2.j-1])
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j-1;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=4;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j+1])
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j+1;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=2;
            }
    }

    if(maze_1[ghost_2.i+1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i+1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=3;
            }
    }

    if(maze_1[ghost_2.i-1][ghost_2.j] && ghost_2_dik==0)
    {
        ghost_2.x=ghost_2.i-1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=1;
            }
    }

    if(ghost_2_dik==1)
        {ghost_2.i--;svk1=1;}
    else if(ghost_2_dik==2)
        {ghost_2.j++;svk1=2;}
    else if(ghost_2_dik==3)
        {ghost_2.i++;svk1=3;}
    else if(ghost_2_dik==4)
        {ghost_2.j--;svk1=4;}

}


else if(svk1==4)
{

    if(maze_1[ghost_2.i-1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i-1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=1;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j-1] )
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j-1;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=4;
            }
    }

    if(maze_1[ghost_2.i+1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i+1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=3;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j+1] && ghost_2_dik==0)
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j+1;

        if(ghost_2_distance>((ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j)))
            {
                ghost_2_distance = (ghost_2.x-i)*(ghost_2.x-i)+(ghost_2.y-j)*(ghost_2.y-j);
                ghost_2_dik=2;
            }
    }

    if(ghost_2_dik==1)
        {ghost_2.i--;svk1=1;}
    else if(ghost_2_dik==2)
        {ghost_2.j++;svk1=2;}
    else if(ghost_2_dik==3)
        {ghost_2.i++;svk1=3;}
    else if(ghost_2_dik==4)
        {ghost_2.j--;svk1=4;}

}

}

    else
        {
    ghost_2_dik=0;
    ghost_2_distance=500000;

    if(svk1==2)
{

    if(maze_1[ghost_2.i-1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i-1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=1;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j+1])
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j+1;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=2;
            }
    }

    if(maze_1[ghost_2.i+1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i+1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=3;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j-1] && ghost_2_dik==0)
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j-1;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=4;
            }
    }

    if(ghost_2_dik==1)
        {ghost_2.i--;svk1=1;}
    else if(ghost_2_dik==2)
        {ghost_2.j++;svk1=2;}
    else if(ghost_2_dik==3)
        {ghost_2.i++;svk1=3;}
    else if(ghost_2_dik==4)
        {ghost_2.j--;svk1=4;}

}


else if(svk1==1)
{

    if(maze_1[ghost_2.i-1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i-1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=1;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j+1])
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j+1;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=2;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j-1])
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j-1;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=4;
            }
    }

    if(maze_1[ghost_2.i+1][ghost_2.j] && ghost_2_dik==0)
    {
        ghost_2.x=ghost_2.i+1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=3;
            }
    }

    if(ghost_2_dik==1)
        {ghost_2.i--;svk1=1;}
    else if(ghost_2_dik==2)
        {ghost_2.j++;svk1=2;}
    else if(ghost_2_dik==3)
        {ghost_2.i++;svk1=3;}
    else if(ghost_2_dik==4)
        {ghost_2.j--;svk1=4;}

}


else if(svk1==3)
{

    if(maze_1[ghost_2.i][ghost_2.j-1])
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j-1;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=4;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j+1])
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j+1;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=2;
            }
    }

    if(maze_1[ghost_2.i+1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i+1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=3;
            }
    }

    if(maze_1[ghost_2.i-1][ghost_2.j] && ghost_2_dik==0)
    {
        ghost_2.x=ghost_2.i-1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=1;
            }
    }

    if(ghost_2_dik==1)
        {ghost_2.i--;svk1=1;}
    else if(ghost_2_dik==2)
        {ghost_2.j++;svk1=2;}
    else if(ghost_2_dik==3)
        {ghost_2.i++;svk1=3;}
    else if(ghost_2_dik==4)
        {ghost_2.j--;svk1=4;}

}


else if(svk1==4)
{

    if(maze_1[ghost_2.i-1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i-1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=1;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j-1] )
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j-1;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=4;
            }
    }

    if(maze_1[ghost_2.i+1][ghost_2.j])
    {
        ghost_2.x=ghost_2.i+1;ghost_2.y=ghost_2.j;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=3;
            }
    }

    if(maze_1[ghost_2.i][ghost_2.j+1] && ghost_2_dik==0)
    {
        ghost_2.x=ghost_2.i;ghost_2.y=ghost_2.j+1;

        if(ghost_2_distance>((ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17)))
            {
                ghost_2_distance = (ghost_2.x-19)*(ghost_2.x-19)+(ghost_2.y-17)*(ghost_2.y-17);
                ghost_2_dik=2;
            }
    }

    if(ghost_2_dik==1)
        {ghost_2.i--;svk1=1;}
    else if(ghost_2_dik==2)
        {ghost_2.j++;svk1=2;}
    else if(ghost_2_dik==3)
        {ghost_2.i++;svk1=3;}
    else if(ghost_2_dik==4)
        {ghost_2.j--;svk1=4;}

}

}

}

}


void ghostrun2()
{
    if(start==1 && ghost_freeze==0)
{
    if(scatter3==0)
{
    ghost_3_dik=0;
    ghost_3_distance=500000;

if(svk2==1)
{

    if(maze_1[ghost_3.i-1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i-1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=1;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j-1] )
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j-1;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=4;
            }

    }

    if(maze_1[ghost_3.i+1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i+1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=3;
            }
    }

    if(maze_1[ghost_3.i+1][ghost_3.j]&& ghost_3_dik==0 )
    {
        ghost_3.x=ghost_3.i+1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=3;
            }
    }

    if(ghost_3_dik==1)
        {ghost_3.i--;svk2=1;}
    else if(ghost_3_dik==2)
        {ghost_3.j++;svk2=2;}
    else if(ghost_3_dik==3)
        {ghost_3.i++;svk2=3;}
    else if(ghost_3_dik==4)
        {ghost_3.j--;svk2=4;}

}


else if(svk2==2)
{

    if(maze_1[ghost_3.i-1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i-1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=1;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j+1])
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j+1;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=2;
            }
    }
    if(maze_1[ghost_3.i+1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i+1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=3;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j-1] && ghost_3_dik==0 )
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j-1;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=4;
            }

    }

    if(ghost_3_dik==1)
        {ghost_3.i--;svk2=1;}
    else if(ghost_3_dik==2)
        {ghost_3.j++;svk2=2;}
    else if(ghost_3_dik==3)
        {ghost_3.i++;svk2=3;}
    else if(ghost_3_dik==4)
        {ghost_3.j--;svk2=4;}

}


else if(svk2==3)
{

    if(maze_1[ghost_3.i][ghost_3.j+1])
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j+1;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=2;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j-1] )
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j-1;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=4;
            }

    }
    if(maze_1[ghost_3.i+1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i+1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=3;
            }
    }

    if(maze_1[ghost_3.i-1][ghost_3.j] && ghost_3_dik==0)
    {
        ghost_3.x=ghost_3.i-1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=1;
            }
    }

    if(ghost_3_dik==1)
        {ghost_3.i--;svk2=1;}
    else if(ghost_3_dik==2)
        {ghost_3.j++;svk2=2;}
    else if(ghost_3_dik==3)
        {ghost_3.i++;svk2=3;}
    else if(ghost_3_dik==4)
        {ghost_3.j--;svk2=4;}

}

else if(svk2==4)
{

    if(maze_1[ghost_3.i-1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i-1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=1;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j-1] )
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j-1;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=4;
            }

    }
    if(maze_1[ghost_3.i+1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i+1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=3;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j+1]&& ghost_3_dik==0 )
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j+1;

        if(ghost_3_distance>((ghost_3.x-i+4)*(ghost_3.x-i+4)+(ghost_3.y-j+4)*(ghost_3.y-j+4)))
            {
                ghost_3_distance = (ghost_3.x-i)*(ghost_3.x-i)+(ghost_3.y-j)*(ghost_3.y-j);
                ghost_3_dik=2;
            }
    }

    if(ghost_3_dik==1)
        {ghost_3.i--;svk2=1;}
    else if(ghost_3_dik==2)
        {ghost_3.j++;svk2=2;}
    else if(ghost_3_dik==3)
        {ghost_3.i++;svk2=3;}
    else if(ghost_3_dik==4)
        {ghost_3.j--;svk2=4;}

}

}

    else
        {
    ghost_3_dik=0;
    ghost_3_distance=500000;

    if(svk2==2)
{

    if(maze_1[ghost_3.i-1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i-1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=1;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j+1])
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j+1;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=2;
            }
    }

    if(maze_1[ghost_3.i+1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i+1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=3;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j-1] && ghost_3_dik==0)
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j-1;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=4;
            }
    }

    if(ghost_3_dik==1)
        {ghost_3.i--;svk2=1;}
    else if(ghost_3_dik==2)
        {ghost_3.j++;svk2=2;}
    else if(ghost_3_dik==3)
        {ghost_3.i++;svk2=3;}
    else if(ghost_3_dik==4)
        {ghost_3.j--;svk2=4;}

}


else if(svk2==1)
{

    if(maze_1[ghost_3.i-1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i-1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=1;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j+1])
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j+1;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=2;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j-1])
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j-1;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=4;
            }
    }

    if(maze_1[ghost_3.i+1][ghost_3.j] && ghost_3_dik==0)
    {
        ghost_3.x=ghost_3.i+1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=3;
            }
    }

    if(ghost_3_dik==1)
        {ghost_3.i--;svk2=1;}
    else if(ghost_3_dik==2)
        {ghost_3.j++;svk2=2;}
    else if(ghost_3_dik==3)
        {ghost_3.i++;svk2=3;}
    else if(ghost_3_dik==4)
        {ghost_3.j--;svk2=4;}

}


else if(svk2==3)
{

    if(maze_1[ghost_3.i][ghost_3.j-1])
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j-1;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=4;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j+1])
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j+1;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=2;
            }
    }

    if(maze_1[ghost_3.i+1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i+1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=3;
            }
    }

    if(maze_1[ghost_3.i-1][ghost_3.j] && ghost_3_dik==0)
    {
        ghost_3.x=ghost_3.i-1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=1;
            }
    }

    if(ghost_3_dik==1)
        {ghost_3.i--;svk2=1;}
    else if(ghost_3_dik==2)
        {ghost_3.j++;svk2=2;}
    else if(ghost_3_dik==3)
        {ghost_3.i++;svk2=3;}
    else if(ghost_3_dik==4)
        {ghost_3.j--;svk2=4;}

}


else if(svk2==4)
{

    if(maze_1[ghost_3.i-1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i-1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=1;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j-1] )
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j-1;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=4;
            }
    }

    if(maze_1[ghost_3.i+1][ghost_3.j])
    {
        ghost_3.x=ghost_3.i+1;ghost_3.y=ghost_3.j;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=3;
            }
    }

    if(maze_1[ghost_3.i][ghost_3.j+1] && ghost_3_dik==0)
    {
        ghost_3.x=ghost_3.i;ghost_3.y=ghost_3.j+1;

        if(ghost_3_distance>((ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1)))
            {
                ghost_3_distance = (ghost_3.x-19)*(ghost_3.x-19)+(ghost_3.y-1)*(ghost_3.y-1);
                ghost_3_dik=2;
            }
    }

    if(ghost_3_dik==1)
        {ghost_3.i--;svk2=1;}
    else if(ghost_3_dik==2)
        {ghost_3.j++;svk2=2;}
    else if(ghost_3_dik==3)
        {ghost_3.i++;svk2=3;}
    else if(ghost_3_dik==4)
        {ghost_3.j--;svk2=4;}

}

}

}

}



void ghostrun3()
{
    if(start==1 && ghost_freeze==0)
{
    if(scatter4==0)
    {
    ghost_4_dik=0;
    ghost_4_distance=500000;

    if(svk3==2)
{

    if(maze_1[ghost_4.i-1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i-1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=1;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j+1])
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j+1;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=2;
            }
    }

    if(maze_1[ghost_4.i+1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i+1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=3;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j-1] && ghost_4_dik==0)
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j-1;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=4;
            }
    }

    if(ghost_4_dik==1)
        {ghost_4.i--;svk3=1;}
    else if(ghost_4_dik==2)
        {ghost_4.j++;svk3=2;}
    else if(ghost_4_dik==3)
        {ghost_4.i++;svk3=3;}
    else if(ghost_4_dik==4)
        {ghost_4.j--;svk3=4;}

}


else if(svk3==1)
{

    if(maze_1[ghost_4.i-1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i-1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=1;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j+1])
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j+1;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=2;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j-1])
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j-1;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=4;
            }
    }

    if(maze_1[ghost_4.i+1][ghost_4.j] && ghost_4_dik==0)
    {
        ghost_4.x=ghost_4.i+1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=3;
            }
    }

    if(ghost_4_dik==1)
        {ghost_4.i--;svk3=1;}
    else if(ghost_4_dik==2)
        {ghost_4.j++;svk3=2;}
    else if(ghost_4_dik==3)
        {ghost_4.i++;svk3=3;}
    else if(ghost_4_dik==4)
        {ghost_4.j--;svk3=4;}

}


else if(svk3==3)
{

    if(maze_1[ghost_4.i][ghost_4.j-1])
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j-1;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=4;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j+1])
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j+1;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=2;
            }
    }

    if(maze_1[ghost_4.i+1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i+1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=3;
            }
    }

    if(maze_1[ghost_4.i-1][ghost_4.j] && ghost_4_dik==0)
    {
        ghost_4.x=ghost_4.i-1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=1;
            }
    }

    if(ghost_4_dik==1)
        {ghost_4.i--;svk3=1;}
    else if(ghost_4_dik==2)
        {ghost_4.j++;svk3=2;}
    else if(ghost_4_dik==3)
        {ghost_4.i++;svk3=3;}
    else if(ghost_4_dik==4)
        {ghost_4.j--;svk3=4;}

}


else if(svk3==4)
{

    if(maze_1[ghost_4.i-1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i-1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=1;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j-1] )
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j-1;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=4;
            }
    }

    if(maze_1[ghost_4.i+1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i+1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=3;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j+1] && ghost_4_dik==0)
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j+1;

        if(ghost_4_distance>((ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2)))
            {
                ghost_4_distance = (ghost_4.x-i-2)*(ghost_4.x-i-2)+(ghost_4.y-j-2)*(ghost_4.y-j-2);
                ghost_4_dik=2;
            }
    }

    if(ghost_4_dik==1)
        {ghost_4.i--;svk3=1;}
    else if(ghost_4_dik==2)
        {ghost_4.j++;svk3=2;}
    else if(ghost_4_dik==3)
        {ghost_4.i++;svk3=3;}
    else if(ghost_4_dik==4)
        {ghost_4.j--;svk3=4;}

}

}

    else
        {
    ghost_4_dik=0;
    ghost_4_distance=500000;

    if(svk3==2)
{

    if(maze_1[ghost_4.i-1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i-1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=1;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j+1])
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j+1;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=2;
            }
    }

    if(maze_1[ghost_4.i+1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i+1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=3;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j-1] && ghost_4_dik==0)
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j-1;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=4;
            }
    }

    if(ghost_4_dik==1)
        {ghost_4.i--;svk3=1;}
    else if(ghost_4_dik==2)
        {ghost_4.j++;svk3=2;}
    else if(ghost_4_dik==3)
        {ghost_4.i++;svk3=3;}
    else if(ghost_4_dik==4)
        {ghost_4.j--;svk3=4;}

}


else if(svk3==1)
{

    if(maze_1[ghost_4.i-1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i-1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=1;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j+1])
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j+1;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=2;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j-1])
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j-1;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=4;
            }
    }

    if(maze_1[ghost_4.i+1][ghost_4.j] && ghost_4_dik==0)
    {
        ghost_4.x=ghost_4.i+1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=3;
            }
    }

    if(ghost_4_dik==1)
        {ghost_4.i--;svk3=1;}
    else if(ghost_4_dik==2)
        {ghost_4.j++;svk3=2;}
    else if(ghost_4_dik==3)
        {ghost_4.i++;svk3=3;}
    else if(ghost_4_dik==4)
        {ghost_4.j--;svk3=4;}

}


else if(svk3==3)
{

    if(maze_1[ghost_4.i][ghost_4.j-1])
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j-1;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=4;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j+1])
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j+1;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=2;
            }
    }

    if(maze_1[ghost_4.i+1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i+1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=3;
            }
    }

    if(maze_1[ghost_4.i-1][ghost_4.j] && ghost_4_dik==0)
    {
        ghost_4.x=ghost_4.i-1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=1;
            }
    }

    if(ghost_4_dik==1)
        {ghost_4.i--;svk3=1;}
    else if(ghost_4_dik==2)
        {ghost_4.j++;svk3=2;}
    else if(ghost_4_dik==3)
        {ghost_4.i++;svk3=3;}
    else if(ghost_4_dik==4)
        {ghost_4.j--;svk3=4;}

}


else if(svk3==4)
{

    if(maze_1[ghost_4.i-1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i-1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=1;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j-1] )
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j-1;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=4;
            }
    }

    if(maze_1[ghost_4.i+1][ghost_4.j])
    {
        ghost_4.x=ghost_4.i+1;ghost_4.y=ghost_4.j;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=3;
            }
    }

    if(maze_1[ghost_4.i][ghost_4.j+1] && ghost_4_dik==0)
    {
        ghost_4.x=ghost_4.i;ghost_4.y=ghost_4.j+1;

        if(ghost_4_distance>((ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1)))
            {
                ghost_4_distance = (ghost_4.x-1)*(ghost_4.x-1)+(ghost_4.y-1)*(ghost_4.y-1);
                ghost_4_dik=2;
            }
    }

    if(ghost_4_dik==1)
        {ghost_4.i--;svk3=1;}
    else if(ghost_4_dik==2)
        {ghost_4.j++;svk3=2;}
    else if(ghost_4_dik==3)
        {ghost_4.i++;svk3=3;}
    else if(ghost_4_dik==4)
        {ghost_4.j--;svk3=4;}

}

}

}

}




/*
	function iDraw() is called again and again by the system.
*/

void iDraw()
{
    //place your drawing codes here
    iClear();

if(start==-1)
{
    iShowBMP(300,150,"menu.bmp");
}
else if(start==6)
{
    iSetColor(0,255,0);
    iShowBMP(100,50,"help.bmp");
    iText(120,570,"Use navigation keys to move PACMAN. Eating foods will give you",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(120,530,"10 points and esting stars will give you 50 points. Avoid ghosts and",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(120,490,"eat maximum foods to gather points. After eating a star ghosts will",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(120,450,"be scattered and run back to their corners, you can get some points",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(120,410,"by eating a scattered ghost before he reaches his corner.",GLUT_BITMAP_TIMES_ROMAN_24);

    iText(120,360,"If you eat a cherry you will get 30 points and the ghosts will be frozen.",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(120,320,"for 5 seconds. Frozen ghosts cannot eat pacman.",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(120,260,"You can pause the game anytime by clicking the 'Esc' button.",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(120,180,"BEST OF LUCK!",GLUT_BITMAP_TIMES_ROMAN_24);

}
else if(start==5)
{
    iSetColor(211,217,17);
    iText(120,700,"HIGHSCORES : ",GLUT_BITMAP_TIMES_ROMAN_24);
    for(int x=9, y=1;x>=0;x--,y++)
    {
        char a[10];
        itoa(y,a,10);
        itoa(highscore[x],high,10);
        iText(170,60*(x+1),a,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(195,60*(x+1),".",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(210,60*(x+1),high,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    iShowBMP(800,50,"return.bmp");
}
else if(start==0 || start==1)
{



    for(x=0;x<21;x++)
        for(y=0;y<19;y++)
    {
        if(maze_1[x][y]==0 && (x+y)%3==0)
        {
            iShowBMP(300+25*y,600-25*x,brick1);
        }
        else if(maze_1[x][y]==0 && (x+y)%3==1)
        {
            iShowBMP(300+25*y,600-25*x,brick2);
        }
        else if(maze_1[x][y]==0 && (x+y)%3==2)
        {
            iShowBMP(300+25*y,600-25*x,brick3);
        }

        else if(maze_2[x][y]==1)
        {
            iSetColor(255,255,255);
            iFilledCircle(312.5+25*y,612.5-25*x, 5, 1000);
        }
        else if(maze_2[x][y]==3)
        {
            iShowBMP(300+25*y,600-25*x,"food.bmp");
        }
        else if(maze_2[x][y]==5)
        {
            iShowBMP(300+25*y,600-25*x,"cherry.bmp");
        }
    }
    //pacman
        pacfunc();
    //ghost
    if(ghost_freeze==1)
    {
        iShowBMP(300+25*ghost_1.j,600-25*ghost_1.i, "frozen.bmp");
        iShowBMP(300+25*ghost_2.j,600-25*ghost_2.i, "frozen.bmp");
        iShowBMP(300+25*ghost_3.j,600-25*ghost_3.i, "frozen.bmp");
        iShowBMP(300+25*ghost_4.j,600-25*ghost_4.i, "frozen.bmp");
    }
    else
    {
    if(scatter1==0)
        iShowBMP(300+25*ghost_1.j,600-25*ghost_1.i, "blinky.bmp");
    else
    {
        if(gafraid==0)
        iShowBMP(300+25*ghost_1.j,600-25*ghost_1.i, "ghost.bmp");
        else
        iShowBMP(300+25*ghost_1.j,600-25*ghost_1.i, "afraid1.bmp");
    }

    if(scatter2==0)
        iShowBMP(300+25*ghost_2.j,600-25*ghost_2.i, "pinky_2.bmp");
    else
    {
        if(g1afraid==0)
        iShowBMP(300+25*ghost_2.j,600-25*ghost_2.i, "ghost.bmp");
        else
        iShowBMP(300+25*ghost_2.j,600-25*ghost_2.i, "afraid1.bmp");
    }

    if(scatter3==0)
        iShowBMP(300+25*ghost_3.j,600-25*ghost_3.i, "inky_2.bmp");
    else
    {
        if(g2afraid==0)
        iShowBMP(300+25*ghost_3.j,600-25*ghost_3.i, "ghost.bmp");
        else
        iShowBMP(300+25*ghost_3.j,600-25*ghost_3.i, "afraid1.bmp");
    }

    if(scatter4==0)
        iShowBMP(300+25*ghost_4.j,600-25*ghost_4.i, "clyde.bmp");
    else
    {
        if(g3afraid==0)
        iShowBMP(300+25*ghost_4.j,600-25*ghost_4.i, "ghost.bmp");
        else
        iShowBMP(300+25*ghost_4.j,600-25*ghost_4.i, "afraid1.bmp");
    }
    }
    //score
    itoa(point,score,10);
        iText(100,750,score,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(30,750,"Score : ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(680,750,"Life : ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(800,50,"press 'space_key' to turn music on/off", GLUT_BITMAP_TIMES_ROMAN_24);
        if(Life>2)
            iShowBMP(850,740,"life.bmp");
        if(Life>1)
            iShowBMP(800,740,"life.bmp");
        if(Life>0)
            iShowBMP(750,740,"life.bmp");


        iText(400,750,"Time : ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(470,750,mnt,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(490,750,":",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(510,750,sec,GLUT_BITMAP_TIMES_ROMAN_24);
}



else if(start==-2)
{
    iShowBMP(100,100,"images//start.bmp");
}

if(start==0)
    {
        iSetColor(0,G,0);
        iText(500,400,"Ready!",GLUT_BITMAP_TIMES_ROMAN_24);
        if(new_game==0)
            {
                if(morsi==1)
                {
                        pac_start();
                        morsi=0;
                }
            }
        else
            pac_new_game();
    }
if(start==-3)
{
    if(high2==1)
    {
        iShowBMP(350,200,"high.bmp");
    }
    else if(win==1)
    {
        iShowBMP(350,200,"win.bmp");
    }
    else
    {
    iShowBMP(350,200,"high_2.bmp");
    }
    iText(580,420,score,GLUT_BITMAP_TIMES_ROMAN_24);
}

if(Life<1)
        {
            if(point>highscore[0])
            {
                high2=1;
                highscore[0]=point;
                sort(highscore,highscore+10);
            }
            start=-3;
            resume=0;
            Life=3;
        }
if(food==0)
        {
            if(point>highscore[0])
            {
                high2=1;
                highscore[0]=point;
                sort(highscore,highscore+10);
            }
            start=-3;
            resume=0;
            Life=3;
            food=189;
            win=1;
        }


        death();
        scatter_mode();
        writemaze();

}



/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(start==-1)
    {
        if(mx>500 && mx<750 && my>520 && my<570)
        {new_game=1;
            start++;}

    }
    if(start==-1)
    {
        if(mx>500 && mx<750 && my>440 && my<490 && resume==1)
            {new_game=0;
            start++;}
    }
    if(start==-1)
    {
        if(mx>500 && mx<750 && my>370 && my<420)
            start=5;
    }
    if(start==-1)
    {
        if(mx>500 && mx<750 && my>300 && my<350)
            start=6;
    }
    if(start==-1)
    {
        if(mx>500 && mx<750 && my>230 && my<280)
            exit(0);
    }
    if(start==5)
    {
        if(mx>800 && mx<1000 && my>50 && my<100)
            start=-1;
    }
    if(start==6)
    {
        if(mx>350 && mx<490 && my>60 && my<120)
            start=-1;
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key&&start==-2)
    {
        start++;
    }
    if(key&&start==0)
    {
        start++;
    }
    if(key&&start==-3)
    {
        start=-1;
    }
    if(start==1 && key==27)
    {
        start=-1;
    }

    if(key==32)
    {
        if(musicon==1)
        {
         musicon=0;
         PlaySound(0,0,0);
        }
        else
        {
            musicon=1;
            PlaySound("pacman_beginning.wav", NULL, SND_LOOP | SND_ASYNC);
        }
    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(key&&start==-3)
    {
        start=-1;
    }
    if(key&&start==-2)
    {
        start++;
    }
    if(key&&start==0)
    {
        start++;
    }
    if(key == GLUT_KEY_UP)
    {
        move=1;
    }
    if(key == GLUT_KEY_DOWN)
    {
        move=3;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        move=2;
    }
    if(key == GLUT_KEY_LEFT)
    {
        move=4;
    }
    //place your codes for other keys here
}



int main()
{
    //place your own initialization codes her
    readmaze();
    if(musicon)
    {
        PlaySound("pacman_beginning.wav", NULL, SND_LOOP | SND_ASYNC);
    }
        iSetTimer(g_speed,ghostrun);
        iSetTimer(g_speed,ghostrun1);
        iSetTimer(g_speed,ghostrun2);
        iSetTimer(g_speed,ghostrun3);
        iSetTimer(200,death);
    iSetTimer(200,image_change);
    iSetTimer(200,pacmove);
    iSetTimer(1000,timechange);
    iInitialize(1200, 800, "Curves!");

    return 0;
}
