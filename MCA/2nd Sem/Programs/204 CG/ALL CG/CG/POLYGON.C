
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void drawline(double x1,double y1,double x2,double y2 );
void draw(double x1,double y1,double x2,double y2);
void drawline(double x1,double y1,double x2,double y2)
{
	if((x2<x1)||(x2==x1 && y2<y1))
	draw(x2,y2,x1,y1);
	else
	draw(x1,y1,x2,y2);
}
void draw(double x1,double y1,double x2,double y2)
{
	double m,i,t;
	double a=y1;
	double b=x1;
	if(x1==x2)
	{
		for(i=y1;i<y2;i++)
		{
			putpixel(x1,i,RED);
		}
		return;
	}
	m=(y2-y1)/(x2-x1);
	if(m<=1)
	{
		for(i=x1;i<=x2;i++)
		{
			putpixel(i,a,RED);
			a=a+m;
		}
	}
	else if(m>1)
	{
		for(i=y1;i<=y2+1;i++)
		{
			putpixel(b,i,RED);
			b=b+(1/m);
		}
	}
}
void main()
{
	double x[5],y[5];
	int driver=DETECT,mode,i=0,n;
	initgraph(&driver,&mode,"");
	printf("\nEnter the no. of sides:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter %d the coordinate:\nx : ",i+1);
		scanf("%lf",&x[i]);
		printf("y : ");
		scanf("%lf",&y[i]);
	}
	clrscr();
	for(i=0;i<n-1;i++)
	{
		drawline(x[i],y[i],x[i+1],y[i+1]);
	}
	drawline(x[i],y[i],x[0],y[0]);
	getch();
	closegraph();
}
