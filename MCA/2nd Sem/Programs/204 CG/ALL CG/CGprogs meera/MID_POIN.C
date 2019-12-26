#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define f(x,y,r) x*x+y*y-r*r
void drawcircle(int,int,int);
void color(int,int,int,int);
void main()
{
	int driver,mode,xc,yc,r;
	clrscr();
	driver = DETECT;
	printf("\n\n\tEnter the centre point:");
	scanf("%d %d",&xc,&yc);
	printf("\n\n\tEnter the radius:");
	scanf("%d",&r);
	initgraph(&driver,&mode,"Z:\\tc\tc\bgi");
	drawcircle(xc,yc,r);
	color(xc,yc,YELLOW,WHITE);
	getch();
	closegraph();
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
		colr1 = getpixel(i,j);
		colr2 = getpixel(i,j);
	}
	i = xc;j = yc;
	colr1 =  getpixel(i,j);
	colr2 =  getpixel(i,j);
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
	colr1 = getpixel(i,j);
	colr2 = getpixel(i,j);
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
void drawcircle(int xc,int yc,int r)
{
	 int x,y,i;
	 float pk;
	 x = 0;y = r;
	 //pk = f(x+1,y-(1/2),r);
	 pk = 1-r;
	 //pk = 5/4-r;
	 while(x<y)
	 {
		if(pk<0)
		{
			pk = pk+(2*x)+3;
			y = y;
		}
		else
		{
			pk = pk+(2*x)-(2*y)+5;
			y  = y - 1;
		}
		x = x+1;
		putpixel(x+xc,y+yc,WHITE);
		putpixel(y+xc,x+yc,WHITE);
		putpixel(y+xc,-x+yc,WHITE);
		putpixel(x+xc,yc-y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc-y,yc-x,WHITE);
		putpixel(xc-y,x+yc,WHITE);
		putpixel(xc-x,y+yc,WHITE);
	 }
	 putpixel(xc+r,yc,WHITE);
	 putpixel(xc-r,yc,WHITE);
	 putpixel(xc,yc-r,WHITE);
	 putpixel(xc,yc+r,WHITE);

}