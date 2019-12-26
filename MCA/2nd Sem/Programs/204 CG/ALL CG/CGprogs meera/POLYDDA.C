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
		drawline(x[i],y[i],xx[i],yy[i]);
	}
	getch();
	closegraph();
}
void drawline(int x1,int y1,int x2,int y2)
{
	int i,m=0,x,y,dx,dy;
	dx=x2-x1;dy=y2-y1;
	x = x1; y = y1;
	//outtextxy(x1,y1,"F");
	//outtextxy(x2,y2,"L");
	if(dx!=0)
	{
		m = dy/dx;
	}
	if(y2<y1&&x2>x1)
	{
		if(m<=1||m>=-1)
		{
			dx = 1;
			for(i=x1;i<=x2;i++)
			{
				putpixel(x,y,WHITE);
				x = x+dx;
				y = m+y;
			}
		}
		else if(abs(m)<=5 || abs(m)>1)
		{
			dy = 1;
			for(i=y1;i<=y2;i++)
			{
				putpixel(x,y,WHITE);
				x = (1/m)+x;
				y = y-dy;
			}
		}
		if(dx==0 && dy!=0)
		{
			if(y2<y1)
			{
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,WHITE);
					y = y-1;
				}
			}
		}
		else
		{
			outtext("Other cases");
			return;
		}
	}
	if(m==0)
	{
		if(dx==0 && dy!=0)
		{
			if(y2<y1)
			{
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,WHITE);
					y = y-1;
				}
			}
			else
			{
				for(i=y1;i<=y2;i++)
				{
					putpixel(x,y,WHITE);
					y = y+1;
				}
			}
		}
		else if(dx!=0&&dy==0)
		{
			if(x2<x1)
			{
				//x = x2;y = y2;
				for(i=x2;i<=x1;i++)
				{
					putpixel(x,y,WHITE);
					x = x-1;
				}
			}
			else
			{
				for(i=x1;i<=x2;i++)
				{
					putpixel(x,y,WHITE);
					x = x+1;
				}
			}
		}
		else
		{
			outtext("Polygon not possible");
			return;
		}
	}
	else if(m<=1||m>=-1)
	{
		dx = 1;
		if(x2<x1)
		{
			//x = x2;y = y2;
			for(i=x2;i<=x1;i++)
			{
				putpixel(x,y,WHITE);
				x= x+dx;
				y = y+m;
			}
		}
		else
		{
			for(i=x1;i<=x2;i++)
			{
				putpixel(x,y,WHITE);
				x = x+dx;
				y = m+y;
			}
		}
	}
	else if(abs(m)<=5 || abs(m)>1)
	{
		dy = 1;
		if(x2<x1)
		{
			x = x2;y = y2;
			for(i=x2;i<=x1;i++)
			{
				dy = 1;
				putpixel(x,y,WHITE);
				y = y + dy;
				x = (1/m)+x;
			}
		}
		else
		{
			for(i=x1;i<=x2;i++)
			{
				putpixel(x,y,WHITE);
				x = (1/m)+x;
				y = y+dy;
			}
		}
	}
	else
	{
		outtext("Other cases");
		return;
	}
}