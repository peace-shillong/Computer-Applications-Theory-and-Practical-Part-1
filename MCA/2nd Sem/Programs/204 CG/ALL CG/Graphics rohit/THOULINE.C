#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
void main()
{

 int gd=DETECT,gm;
 int x,y,x1,y1,x2,y2,i;

 printf("\nEnter X1:");
 scanf("%d",&x1);
 printf("\nEnter X2:");
 scanf("%d",&x2);
 printf("\nEnter Y1:");
 scanf("%d",&y1);
 printf("\nEnter Y2:");
 scanf("%d",&y2);
 initgraph(&gd,&gm,"C:\\TC\\bgi");

 for(x=x1;x<=x2;x++)
 {

    float a,b,c;

    a=x-x1;
    b=x1-x2;
    c=y1-y2;

    y=(((a/b)*(c))+y1);
 }
 getch();
 closegraph();
}
