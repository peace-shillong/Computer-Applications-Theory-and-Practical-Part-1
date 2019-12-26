#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include<process.h>

void draw_line(float x1,float y1,float x2,float y2,int c);
void main()

{

	int n,i,j,k,gd,gm,dy,dx;
	int x,y,temp,c;
	int a[20][2],xi[20];
	float slope[20];
	clrscr();
	printf("\n\n\tEnter the no. of edges of polygon : ");
	scanf("%d",&n);
	if(n>10)
	{
		printf("\n Too many coordinates");
		exit(1);
	}
	printf("\n\n\tEnter the cordinates of polygon :\n\n\n ");

	for(i=0;i<n;i++)
	{
		printf("\tX%d Y%d : ",i,i);
		scanf("%d %d",&a[i][0],&a[i][1]);
	}
	printf("\n\tEnter color : ");
	scanf("%d",&c);

	a[n][0]=a[0][0];
	a[n][1]=a[0][1];


	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"c:\\tc\\bgi");


	//Draw polygon

	for(i=0;i<n;i++)
	{
	draw_line(a[i][0],a[i][1],a[i+1][0],a[i+1][1],c);
	}

	for(i=0;i<n;i++)
	{
	dy=a[i+1][1]-a[i][1];
	dx=a[i+1][0]-a[i][0];

	if(dy==0) slope[i]=1.0;
	if(dx==0) slope[i]=0.0;

	if((dy!=0)&&(dx!=0)) // calculate inverse slope
	{
		slope[i]=(float) dx/dy;
	}
	}

	for(y=0;y< 480;y++)
	{
		k=0;
		for(i=0;i<n;i++)
		{

			if( ((a[i][1]<=y)&&(a[i+1][1]>y))||
			      ((a[i][1]>y)&&(a[i+1][1]<=y)))
			{
				xi[k]=(int)(a[i][0]+slope[i]*(y-a[i][1]));
				k++;
			}
		}

		for(j=0;j<k-1;j++) // Arrange x-intersections in order
		for(i=0;i<k-1;i++)
		{
			if(xi[i]>xi[i+1])
			{
				temp=xi[i];
				xi[i]=xi[i+1];
				xi[i+1]=temp;
			}
		}
		for(i=0;i<k;i+=2)
		{
		      draw_line(xi[i],y,xi[i+1]+1,y,c);

		}

	}
	getch();
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
	else if(x1==x2)
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

}