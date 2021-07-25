#include <stdio.h>
#include <string.h>
#include<math.h>
#include <stdlib.h>
#define s 5
//path finding program using A*Algorithm
//s is the size of the map we will blocking then borders later ,map is provided in the output for your reference
void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}
void green() {
  printf("\033[0;32m");
}
void cyan (){
  printf("\033[0;36m");
}
void purple() {
  printf("\033[0;35m");
}

void reset () {
  printf("\033[0m");
}
void banner ()
{red();
  char a[] = {
   " ########  #######  ##       ##        ######      ###    ######## ########\n    ##    ##     ## ##       ##       ##    ##    ## ##      ##    ##       \n    ##    ##     ## ##       ##       ##         ##   ##     ##    ##       \n    ##    ##     ## ##       ##       ##   #### ##     ##    ##    ######   \n    ##    ##     ## ##       ##       ##    ##  #########    ##    ##       \n    ##    ##     ## ##       ##       ##    ##  ##     ##    ##    ##       \n    ##     #######  ######## ########  ######   ##     ##    ##    ######## "
  };//this has BANNER of our program
  printf ("%s", a);
  reset();cyan();
  printf (" \n\t\t\t<by ARAVIND,ANURAG,DEEPAK,ARJUN>\n");reset();
}
void print(int space[][s])
{int i,j;
 for(i=0;i<s;i++)
     {

        {for(j=0;j<s;j++){
            if(space[i][j]==-1)
                {red();
            printf("\t[]",space[i][j]);reset();
            }
            else if(space[i][j]==2)
            {
                purple();
            printf("\to",space[i][j]);reset();
            }
            else
            {
                yellow();
            printf("\t*",space[i][j]);reset();
            }
            }
        }
        printf("\n");}
}
int f(int x1,int y1,int x2,int y2,int st1,int st2)
{
  int x=(x1 - x2)*(x1 - x2);int x3=(st1)*(st1) + (st2)*(st2);
    int y=(y1 - y2)*(y1 - y2);
    int dis= (sqrt(x+y))+ (sqrt(x3));
    return(dis);
}

int main ()
{
  banner ();
  int space[s][s],g[2]={2,2},st[2]={0,0},pos[2]={1,1},i,j,fin=0,pass=0,block;
  int k=0;
    int score[8][3];

int min=score[3][2];
    //space[1][1]=-1;
        for(i=0;i<s;i++)
        for(j=0;j<s;j++)
                space[i][j]=-1;
    for(i=1;i<s-1;i++)
        for(j=1;j<s-1;j++)
                space[i][j]=0;
    print(space);
    printf("\n enter the start point of ");
    scanf("%d%d",&st[0],&st[1]);
    if(space[st[0]][st[1]]==-1 || st[0]>s|| st[1]>s)
    goto end;
    pos[0]=st[0];pos[1]=st[1];
    space[pos[0]][pos[1]]=2;
    printf("\nenter the end point of ");
    scanf("%d%d",&g[0],&g[1]);
    if(space[g[0]][g[1]]==-1 || g[0]>s|| g[1]>s)
    goto end;

    printf("give me number of block to be entered : ");
    scanf("%d",&block);
    while(block>0){
    printf("\n enter the coordinates of block : ");
    scanf("%d%d",&i,&j);
    if(space[i][j]==-1 || space[i][j]== 2 || i==g[0] && j==g[1]){
    printf("\n ERROR IT IS A EXISTING BLOCK!!! \n\t\t(remember [] are blocks and * is the space)\n");
    print(space);continue;}
    space[i][j]=-1;block--;print(space);printf("\n\n");}

    //making every other cells as 0 except blocks and start and made the border
//space[pos[0]][pos[1]]=-1;
    while (1)

    {print(space);printf("\n goal is (%d,%d) and posistion is (%d,%d) \n",g[0],g[1],pos[0],pos[1]);

    space[pos[0]][pos[1]]=2;

     int  score[8][3] = {
{pos[0]+1,pos[1],f(pos[0]+1,pos[1],g[0],g[1],st[0],st[1])},
{pos[0]-1,pos[1],f(pos[0]-1,pos[1],g[0],g[1],st[0],st[1])},
{pos[0],pos[1]+1,f(pos[0],pos[1]+1,g[0],g[1],st[0],st[1])},
{pos[0],pos[1]-1,f(pos[0],pos[1]-1,g[0],g[1],st[0],st[1])},
{pos[0]+1,pos[1]+1,f(pos[0]+1,pos[1]+1,g[0],g[1],st[0],st[1])},
{pos[0]-1,pos[1]-1,f(pos[0]-1,pos[1]-1,g[0],g[1],st[0],st[1])},
{pos[0]-1,pos[1]+1,f(pos[0]-1,pos[1]+1,g[0],g[1],st[0],st[1])},
{pos[0]+1,pos[1]-1,f(pos[0]+1,pos[1]-1,g[0],g[1],st[0],st[1])}};
min=score[3][2];
//printf("\n g is (%d,%d) and p is (%d,%d) ",g[0],g[1],pos[0],pos[1]);
//successor
        while(k<8)
        {

            i=score[k][0];
            j=score[k][1];
            if(i==g[0] && j==g[1])
            {
                pos[0]=i;pos[1]=j;break;
            }

//printf("\ni,j = (%d,%d) && min =%d\n",i,j,min);
            if(score[k][2]<=min && space[i][j]!=-1 && space[i][j]!=2 && i>0 &&i<s&&j>0 &&j<s )
            {
               min=score[k][2];
                //printf("\n min is=%d",min);
                st[0]=pos[0];st[1]=pos[1];
                pos[0]=score[k][0];
                pos[1]=score[k][1];

                pass=1;

            }
            //IMPROVE THE CODE WITH BACK TRACKING
          else if(pass!=1 &&  k==8)
             {
                 space[pos[0]][pos[1]]=2;space[st[0]][st[1]]=0;pos[0]=st[0];pos[1]=pos[1];
                 printf("\npath has been blocked once at(%d,%d) \n",pos[0],pos[1]);

             }
            k++;
}


k=0;
            //printf("\n g is (%d,%d) and p is (%d,%d) \n",g[0],g[1],pos[0],pos[1]);
            printf("\n goal is (%d,%d) and posistion is (%d,%d) \n",g[0],g[1],pos[0],pos[1]);
            if(pos[0]==g[0] &&pos[1]==g[1])
                break;
    }

     space[pos[0]][pos[1]]=2;printf("\n");

print(space);
            printf("\ngoal reached\n");
        for(i=0;i<s;i++)
        {for(j=0;j<s;j++)
        if(space[i][j]==2)
            fin++;
            printf("\n");
            }
            printf("\nnumber of blocks used =%d\n",fin);
end:
yellow();
printf("\n program ENDS HERE 0=0");reset();
/*
1:create a 2d space with blocks
step2:calculate the f for neighbor,then decide the successor
 and make the parent to closed state and repeat till the end
*/
}







