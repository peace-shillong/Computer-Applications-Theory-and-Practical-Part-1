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
	initgraph(&driver,&mode,"Z:\\tc\tc\bgi");
       /*	curve1(250,150,150,170,10,10,10,30);
	curve1(250,170,150,190,10,10,10,30);
	curve1(200,175,200,240,1,1,3,3);
	curve1(208,175,208,240,1,1,3,3);
	curve1(200,239,208,239,1,1,1,1);
	curve1(250,150,250,170,1,1,1,1);
	curve1(150,170,150,190,1,1,1,1);
	color(201,160,GREEN,WHITE);
	color(205,180,GREEN,WHITE);*/
	//leave
    curve1(308,100,350,110,10,10,10,100);
    //curve1(208,200,240,210,10,40,40,40);
	curve1(308,100,350,110,100,100,200,100);
      /*	color(220,210,10,WHITE);
	color(250,205,10,WHITE);
	color(250,208,10,WHITE);
	color(209,205,10,WHITE);*/
	//putpixel(209,205,RED);

	//mango
       //	curve1(190,390,208,220,30,1,-400,-300);
       //	curve1(190,390,208,220,30,1,200,200);
	curve1(285,120,280,400,400,1,-400,-300);
	curve1(285,120,280,400,-500,1,200,200);
	//color(285,400,14,WHITE);
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