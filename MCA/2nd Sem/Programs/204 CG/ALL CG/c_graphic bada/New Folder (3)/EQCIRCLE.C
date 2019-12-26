#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void drawcircle(float,float,float);
void main()
{
      int gd,gm;
      float xc,yc,r;
      gd=DETECT;
      clrscr();
      printf("\n\t Enter the centre(xc and yc): ");
      scanf("%f %f",&xc,&yc);
      printf("\n\t Enter the radius: ");
      scanf("%f",&r);
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      drawcircle(xc,yc,r);
      getch();
      closegraph();
}
void drawcircle(float xc,float yc,float r)
{
	float minx,maxx,y=0;
	int i;
	minx=xc-r;
	maxx=xc+r;
	for(i=minx;i<maxx;i++)
	{
	     y=sqrt((r*r)-((i-xc)*(i-xc)))+yc;
	     putpixel(i,y,WHITE);
	     y=-sqrt((r*r)-((i-xc)*(i-xc)))+yc;
	     putpixel(i,y,WHITE);
	}
}



