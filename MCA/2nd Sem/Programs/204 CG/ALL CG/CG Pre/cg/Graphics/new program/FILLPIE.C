#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
void rec(int x,int y);
void circlemid(int x,int y,long int r);
void piedraw(double *,int);
void draw (int x1,int x2,int y1,int y2);
void main()
{
	int i,n,driver=DETECT, gm;
	double data[14],temp=0;
	double deg[14][2];
	clrscr();
	do
	{
		printf("Enter The Number Of Values :");
		scanf("%d",&n);
	}while(!(n>0&&n<15));

	for(i=0;i<n;i++)
	{
		printf("\nPlease Enter The Values %d : ",i+1);
		scanf("%lf",&data[i]);
	}
	for(i=0;i<n;i++)
		temp=data[i]+temp;
	for(i=0;i<n;i++)
	{
		deg[i][0]=((data[i]/temp)*360);
		deg[i][1]=i+1;
	}
	initgraph(&driver, &gm,"c:\\tc\\bgi");
	piedraw(&deg[0][0],n);
	getch();
	closegraph();
}
void circlemid(int x, int y, long int r)
{

	int i=0;
	double yi;
	do
	{
		yi= sqrt(r*r-i*i);
		putpixel(x+i,y+yi,15);
		putpixel(x+i,y-yi,15) ;
		putpixel(x+yi,y+i,15);
		putpixel(x+yi,y-i,15);
		putpixel(x-i,y+yi,15);
		putpixel(x-i,y-yi,15);
		putpixel(x-yi,y+i,15);
		putpixel(x-yi,y-i,15);
		i++;
	}while(i<=yi);
}

void piedraw(double *deg,int n)
{
	int x,y,xi,yi,m=0,t=0;
	int i;
	char *s1,*s2,*s3;
	y=getmaxy()/2;
	x=getmaxx()/2-50;
	circlemid(x,y,200);
	t=m;
	for(i=0;i<=n;i++)
	{
		xi=200*cos((3.14159*m)/180);
		yi=200*sin((3.14159*m)/180);
		if(i!=n)
			line(x,y,x+xi,y+yi);
		setfillstyle(1,*(deg+((i-1)*2)+1));
		t=t+((m-t)/2);
		xi=100*cos((3.14159*t)/180);
		yi=100*sin((3.14159*t)/180);
		floodfill(x+xi,y+yi,15);
		t=m;
		m=*(deg+(i*2))+m;

	}
	//outtextxy("The degrees Are=");
	//outtextxy
	x=510;
	y=50;
     //	s2="Input= ";
	for(i=0;i<n;i++)
	{
		rec(x,y);
		setfillstyle(1,*(deg+(i*2)+1));

		floodfill(x+3,y+3,15);
		ltoa((i+1),s1,10);
		outtextxy(x+15,y+2,s2);
		outtextxy(x+70,y+2,s1);
		y=y+12;
	}
}
void draw (int x1,int x2, int y1, int y2)
{
	float x,y,xinc,yinc,dx,dy;
	int k;
	int step;
	dx=x2-x1;
	dy=y2-y1;
	if(dy==0)
	{
	if(dx<0)
		for(k=x2;k<=x1;k++)
			putpixel(k,y1,10);
	else
		for(k=x1;k<=x2;k++)
			putpixel(k,y1,10);
	return;
	}
	if(abs(dx)>abs(dy))
		step=abs(dx);
	else
		step=abs(dy);
	xinc=dx/step;
	yinc=dy/step;
	x=x1;
	y=y1;
	putpixel(x,y,RED);
	for(k=1;k<=step;k++)
	{
		x=x+xinc;
		y=y+yinc;
		putpixel(x,y,WHITE);

	}
}

void rec(int x,int y)
{
    line(x,y,x+10,y);
    line(x,y,x,y+10);
    line(x+10,y,x+10,y+10);
    line(x,y+10,x+10,y+10);
}




