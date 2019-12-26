#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void main()
{
 int driver=DETECT, mode;
 int x,y,x1,y1,x2,y2;
 clrscr();
 initgraph(&driver, &mode, "c:\\tc\\bgi");

 printf("Enter the value of x1:");
 scanf("%d",&x1);
 printf("Enter the value of y1:");
 scanf("%d",&y1);
 printf("Enter the value of x2:");
 scanf("%d",&x2);
 printf("Enter the value of y2:");
 scanf("%d",&y2);
 clrscr();
for(x=x1;x<=y2;x++)
{
		float a,b,c;
		a=x-x1;
		b=y1-y2;
		c=x1-x2;
		y=((a)*(b)+y1)/(c);
		putpixel(x,y,GREEN);

}
  getch();
  closegraph();

}