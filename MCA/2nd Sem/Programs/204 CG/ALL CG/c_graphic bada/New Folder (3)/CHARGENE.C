#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
      int gd,gm;
      int i;
      gd=DETECT;
      clrscr();
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      getch();
      closegraph();
}