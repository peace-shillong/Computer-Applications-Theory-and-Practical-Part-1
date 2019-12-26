#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void draw_line(float,float,float,float,int);

void main()
{

    int x[20],y[20],sides,i;
    int d=DETECT,gm,c;
    printf("\nEnter the number of coordinates:");
    scanf("%d",&sides);

    for(i=1;i<=sides;i++)
    {
	printf("\nEnter the coordinates of x%d and y%d:",i,i);
	scanf("%d %d",&x[i],&y[i]);

    }
    printf("\n\t\tEnter the color: ");
     scanf("%d",&c);
    initgraph(&d,&gm,"C:\\TC\\BGI");

    for(i=1;i<sides;i++)
    {
	draw_line(x[i],y[i],x[i+1],y[i+1],c);
    }
    draw_line(x[sides],y[sides],x[1],y[1],c);
    getch();
    closegraph();
}

void draw_line(float x1,float y1,float x2,float y2,int c)
{
   int x,y;
   if(x1<x2)
	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,c);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,c);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,c);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,c);
			}
		}

	}
	if(x1==x2 && y1==y2)
	{
	      x=x1;
	      y=y1;
	      putpixel(x,y,c);

	}
}