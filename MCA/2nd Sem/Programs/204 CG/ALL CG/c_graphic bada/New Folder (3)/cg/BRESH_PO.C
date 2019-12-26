#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void draw_poly(float ,float ,float ,float );
void main()
{

    int x[10],y[10],n,i;
    int gd=DETECT,gm;
    printf("\nEnter the number of points:");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
	printf("\nEnter the coordinates of x%d and y%d:",i,i);
	scanf("%d %d",&x[i],&y[i]);

    }

    initgraph(&gd,&gm,"c:\\tc\\bgi");
    for(i=1;i<n;i++)
    {
	draw_poly(x[i],y[i],x[i+1],y[i+1]);

    }
    draw_poly(x[n],y[n],x[1],y[1]);
    getch();
    closegraph();
}

void draw_poly(float x1,float y1,float x2,float y2)
{
   int x,y;

   if(x1<x2)
   {
	for(x=x1;x<x2;x++)
	{
		y=y1+(((x-x1)*(y1-y2))/(x1-x2));
		putpixel(x,y,GREEN);
	}
   }
   else if(x1>x2)
   {
	for(x=x2;x<x1;x++)
	{
		y=y1+(((x-x1)*(y1-y2))/(x1-x2));
		putpixel(x,y,GREEN);
	}
   }
   else
   {
	x=x1;
	if(y1<y2)
	{
		for(y=y1;y<y2;y++)
		{
			putpixel(x,y,GREEN);
		}
	}
	else
	{
		for(y=y2;y<y1;y--)
		{
			putpixel(x,y,GREEN);
		}
	}
    }

    if((x1==x2) && y1==y2)
    {
	  x=x1;
	  y=y1;
	  putpixel(x,y,GREEN);
    }
}