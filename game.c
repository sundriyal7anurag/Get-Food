#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int width=20,height=20;
int x,y,fruitX,fruitY,score,gameOver,flag;
int tailX[100],tailY[100];
int countTail=0;
void foodGeneration(){

    label1:
    fruitX=rand()%20;
    if(fruitX==0)goto label1;
    label2:
    fruitY=rand()%20;
    if(fruitY==0)goto label2;
}
void setup(){
    gameOver=0;
    x=width/2;
    y=height/2;
    label1:
    fruitX=rand()%20;
    if(fruitX==0)goto label1;
    label2:
    fruitY=rand()%20;
    if(fruitY==0)goto label2;
    foodGeneration();
    score=0;
}
void draw(){
    int i,j;
    system("cls");
    for(i=0;i<width;i++){
        for(j=0;j<height;j++){
                if(i==0||i==height-1||j==0||j==width-1){
                        printf("#");
                }
                else{
                        if(i==x&&j==y)
                            printf("O");
                        else if(i==fruitX&&j==fruitY)
                                printf("F");
                        else
                            printf(" ");
                }
        }
        printf("\n");
    }
}
void input()
{   char ch;
    if(kbhit()){
          switch(getch())
        {
        case 'a':
            flag=1;
             break;
        case 's':
            flag=2;
            break;
        case 'w':
            flag=3;
            break;
        case 'z':
            flag=4;
           break;
        case 'x':
            gameOver=1;
            break;

        }

    }
}
void MakeLogic(){
    switch(flag){
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    default:
        break;
    }
    if(x<0||x>width|| y<0||y>height)
        gameOver=1;
    if(x==fruitX &&y==fruitY){
        foodGeneration();
        score+=10;
        countTail++;
    }
}
int main()
{
    char out;
    do{
    int m,n;
        setup();
        while(!gameOver){
            draw();
            input();
            MakeLogic();
            for(m=0;m<100000;m++){
                for(n=0;n<1000;n++){

                }
            }
        }
        printf("Score=%d\n",score);
        printf("Press  P for try again  \nPress N  to quit");
        scanf("%c",&out);
    }while(out!='n');
}
