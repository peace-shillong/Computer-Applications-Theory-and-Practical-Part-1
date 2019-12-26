#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{

 int gd=DETECT,gm;
 int x1,y1,x2,y2,i;
 float x,y;

 printf("\nEnter the first coordinates X1 and Y1:");
 scanf("%d %d",&x1,&y1);
printf("\nEnter the last coordinates X2 and Y2:");
scanf("%d %d",&x2,&y2);
 initgraph(&gd,&gm,"C:\\TC\\bgi");

 for(x=x1;x<=x2;x++)
 {  float a,b,c;
    a=x-x1;
    b=x1-x2;
    c=y1-y2;

    y=(((a/b)*(c))+y1);

    putpixel(x,y,RED);

 }
 getch();
 closegraph();

}









