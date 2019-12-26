#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int i,n;
int x[50],y[50];
void drawll(float ,float ,float ,float);
void polyd(int x[],int y[]);
void drawlle(float ,float ,float ,float);
void polyde(int x[],int y[]);
void translate(float x1,float y1)
{
	for(i=0;i<n;i++)
	{
		x[i]=x[i]+x1;
		y[i]=y[i]+y1;
	}
}
void main()
{
	int ch;
	int gd=DETECT,gm;
	float rot,tx,ty,sx,sy;
	clrscr();
	initgraph(&gd,&gm,"c:\\tc");
	printf("\n\t\tTRANSFORMATION");
	printf("\n\nEnter the number of vertices: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		 printf("\nEnter the value of x%d: ",i+1);
		 scanf("%d",&x[i]);
		 printf("\nEnter the value of y%d: ",i+1);
		 scanf("%d",&y[i]);
	}
	clrscr();
	polyd(x,y);
	printf("\n Please press enter");
	getch();
	clrscr();
printf("\nEnter the translation values:");
				printf("\n\ttx :");
				scanf("%f",&tx);
				printf("\n\tty :");
				scanf("%f",&ty);
				polyde(x,y);
				translate(tx,ty);

				polyd(x,y);
				getch();
}
void polyd(int x[],int y[])
{
		for(i=0;i<(n-1);i++)
		{
			drawll(x[i],y[i],x[i+1],y[i+1]);
		}
			drawll(x[n-1],y[n-1],x[0],y[0]);
}
void drawll(float x1,float y1,float x2,float y2)
{
	 float dx,dy,xi,yi,x,y,i,m;
	 dx=x2-x1;
	 dy=y2-y1;
	 if(abs(dx)>abs(dy))
		 m=abs(dx);
	 else
		 m=abs(dy);
	 xi=dx/m;
	 yi=dy/m;
	 x=x1;
	 y=y1;
	 for(i=1;i<m;i++)
	 {
		  x=x+xi;
		  y=y+yi;
		  putpixel(x,y,RED);
	 }
}
void polyde(int x[],int y[])
{
		for(i=0;i<(n-1);i++)
		{
			drawll(x[i],y[i],x[i+1],y[i+1]);
		}
			drawll(x[n-1],y[n-1],x[0],y[0]);
}
void drawlle(float x1,float y1,float x2,float y2)
{
	 float dx,dy,xi,yi,x,y,i,m;
	 dx=x2-x1;
	 dy=y2-y1;
	 if(abs(dx)>abs(dy))
		 m=abs(dx);
	 else
		 m=abs(dy);
	 xi=dx/m;
	 yi=dy/m;
	 x=x1;
	 y=y1;
	 for(i=1;i<m;i++)
	 {
		  x=x+xi;
		  y=y+yi;
		  putpixel(x,y,GREEN);
	 }
}



