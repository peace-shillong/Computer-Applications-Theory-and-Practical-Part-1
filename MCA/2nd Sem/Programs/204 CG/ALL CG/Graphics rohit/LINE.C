#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
  int gd=DETECT,gm,x,y;
  int x1,y1,x2,y2;
  clrscr();
  printf("Enter x1:");
  scanf("%d",&x1);
   printf("Enter x2:");
  scanf("%d",&x2);
   printf("Enter y1:");
  scanf("%d",&y1);
   printf("Enter y2:");
  scanf("%d",&y2);
  initgraph(&gd,&gm,"C:\\TC\\BGI");
   for(x=x1;x<=x2;x++)
   {
      y=(x-x1)/(x1-x2)*(y1-y2)+y1;

   putpixel(x,y,RED);
   }getch();
   closegraph();


}