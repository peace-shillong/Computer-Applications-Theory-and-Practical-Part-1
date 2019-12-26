#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void color(int,int,int,int);
void curve1(float,float,float,float,float,float,float,float);
void main()
{

	int driver,mode,points[100],num,d[100],i;
	clrscr();
	driver = DETECT;
	initgraph(&driver,&mode,"c:\\tc\tc\bgi");
	printf("\t\t\t\t::::MANGO FRUIT::::");
	// setbkcolor("RED");
	//leave

	curve1(301,115,385,140,200,10,200,10);
	curve1(301,115,385,140,0,200,0,200);
	color(325,106,10,WHITE);
	color(360,122,10,WHITE);
	color(374,133,10,WHITE);
	//stick
	curve1(286,90,286,150,50,1,1,-30);
	curve1(295,90,295,150,50,1,1,-30);
	line(286,90,295,90);
	color(295,100,6,WHITE);
	//mango
       curve1(285,150,280,400,600,30,-50,-300);
       curve1(285,150,280,400,-500,10,200,200);
       color(290,290,14,WHITE);
       color(285,414,14,WHITE);
       color(300,150,14,WHITE);
       getch();
       closegraph();
}
void curve1(float x1,float y1,float x2,float y2,float dx1,float dx2,float dy1,float dy2)
{
	float u,xu,yu;
	for(u = 0.0;u<=1.0;u=u+0.001)
	{
		xu = x1*((2*u*u*u)-(3*u*u)+1)+x2*((-2*u*u*u)+(3*u*u))+dx1*((u*u*u)-(2*u*u)+u)+dx2*((u*u*u)-(u*u));
		yu = y1*((2*u*u*u)-(3*u*u)+1)+y2*((-2*u*u*u)+(3*u*u))+dy1*((u*u*u)-(2*u*u)+u)+dy2*((u*u*u)-(u*u));
		putpixel(xu,yu,WHITE);
	}
}
void color(int xc,int yc,int col,int bcolor)
{
	int i,j,colr1,colr2;
	i = xc;j = yc;
	colr2 = getpixel(i,j);
	colr1 = colr2;
	while(colr1!=bcolor)
	{
		while(colr2!=bcolor)
		{
			putpixel(i,j,col);
			i++;
			colr2 = getpixel(i,j);
		}
		j++;
		i = xc;
		colr1 = colr2 = getpixel(i,j);
	}
	i = xc;j = yc;
	colr1 = colr2 =  getpixel(i,j);
	while(colr1!=bcolor)
	{
		while(colr2!=bcolor)
		{
			putpixel(i,j,col);
			i--;
			colr2 = getpixel(i,j);
		}
		j--;
		i = xc;
		colr1 = colr2 = getpixel(i,j);
	}
	i = xc;j = yc;
	colr1 = colr2 = getpixel(i,j);
	while(colr1!=bcolor)
	{
		while(colr2!=bcolor)
		{
			putpixel(i,j,col);
			i++;
			colr2 = getpixel(i,j);
		}
		j--;
		i = xc;
		colr1 = colr2 = getpixel(i,j);
	}
	i = xc;j = yc;
	colr1 = colr2 = getpixel(i,j);
	while(colr1!=bcolor)
	{
		while(colr2!=bcolor)
		{
			putpixel(i,j,col);
			i--;
			colr2 = getpixel(i,j);
		}
		j++;
		i = xc;
		colr1 = colr2 = getpixel(i,j);
	}
}