#include<conio.h>
#include<graphics.h>
#include<math.h>
#define MAX 20
void drawline(int,int,int,int);
void main(void)
{
	int driver=DETECT,mode;
	int i,sides,x[MAX],y[MAX],xx[MAX],yy[MAX],first=0;
	clrscr();
	printf("\n\n\tEnter the number of sides you want in the polygon:");
	scanf("%d",&sides);
	sides=sides-1;
	for(i=0;i<=sides;i++)
	{
		if(i==sides)
		{
			x[i]=x[0];y[i]=y[0];
			xx[i]=xx[i-1];yy[i]=yy[i-1];
			break;
		}
		if(first==0)
		{
			printf("\n\n\tEnter the starting coordinate point of side %d:",i+1);
			scanf("%d %d",&x[i],&y[i]);
			first = 1;
		}
		else
		{
			x[i] = xx[i-1]; y[i] = yy[i-1];
		}
		printf("\n\n\tEnter the ending coordinate point of side %d:",i+1);
		scanf("%d %d",&xx[i],&yy[i]);
	}
	initgraph(&driver,&mode,"c:\\turboc3\\bgi");
	for(i=0;i<=sides;i++)
	{
		outtextxy(x[i],y[i],"a");
		outtextxy(xx[i],yy[i],"a");
		drawline(x[i],y[i],xx[i],yy[i]);
	}
	getch();
	closegraph();
}
void drawline(int x1,int y1,int x2,int y2)
{
	int d1,d2,x,y,dx,dy,pk,i,xs,ck,c1,c2,ys;
	float m=0;
	dx = abs(x2-x1); dy = abs(y2-y1);
	x = x1;y = y1;
	if(dx!=0)
	{
		m = (float)dy/(float)dx;
	}
	//case when slop is 0
	if(m==0)
	{
		if(x1==x2)
		{
			if(y1<y2)
			{
				for(i=y1;i<=y2;i++)
				{
					putpixel(x,y,WHITE);
					y = y+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,WHITE);
					y = y+1;
				}
			}
		}
		else
		{
			if(x1<x2)
			{
				for(i=x1;i<=x2;i++)
				{
					putpixel(x,y,WHITE);
					x= x+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=x2;i<=x1;i++)
				{
					putpixel(x,y,WHITE);
					x= x+1;
				}
			}
		}
	}
	//case when m is -ve and more than -1
	else if(-1<=m && m<0)
	{
		pk = (2*dy)-dx;
		//ck = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		if(x1<x2)
		{
			x = x1;y = y1;xs = x2;ys = y2;
		}
		else
		{
			x = x2;y= y2;xs=x1;ys = y1;
		}
		while(x<xs)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk = pk+(2*dy);
				//ck = ck-dy*x1;
				if(y>ys)
					y = y-1;
				else
					y = y+1;
			}
			else
			{
				pk = pk+(2*(dy-dx));
				//ck = ck-dy*x1-3*dx*dy;
			}
			x  = x+1;
		}
	}
	//case when m is +ve and less than 1
	else if(0<m&&m<=1)
	{
		pk = (2*dy)-dx;
		if(x1<x2)
		{
			x = x1;y = y1,xs = x2;ys = y2;
		}
		else
		{
			x = x2;y= y2;xs = x1;ys = y1;
		}
		while(x<xs)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk = pk+(2*dy);
			}
			else
			{
				pk = pk+(2*(dy-dx));
				if(y<ys)
					y = y+1;
				else
					y = y-1;
			}
			x  = x+1;
		}
	}
	//case when slop is >1 and +ve
	else if(m>1)
	{

		//ck = -dy*x1-2*dx*y1-2*dy*x1-2*dy-3*dx*dy;
		pk = (2*dy)-dx;
		if(y1<y2)
		{
			x= x1;y = y1;ys = y2;xs = x2;
		}
		else
		{
			x = x2;y = y2;ys = y1;xs = x1;
		}
		while(y<ys)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				//ck = ck-dy*x1;
				pk = pk+(2*dx);
				x = x;
			}
			else
			{
				//ck = ck-dy*x1-3*dx*dy;
				pk = pk+(2*(dx-dy));
				if(x<xs)
					x = x+1;
				else
					x = x-1;
			}
			y = y+1;
		}
	}
	//case when slop is >1 and -ve
	else if(m<-1)
	{

		ck = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		//pk = (2*dy)-dx;
		if(y1<y2)
		{
			x = x1;y = y1;ys = y2;xs = x2;
		}
		else
		{
			x = x2;y = y2;ys = y1;xs = x1;
		}
		while(y<ys)
		{
			putpixel(x,y,WHITE);
			if(ck<0)
			{
				ck = ck-(dy*x1);
				//pk = pk+(2*dx);
				if(x>xs)
					x = x-1;
				else
					x = x+1;
			}
			else
			{
				ck = ck-(dy*x1)-(3*dx*dy);
				//pk = pk+2*(dx-dy);
				x = x;
			}
			y = y+1;
		}
	}

}