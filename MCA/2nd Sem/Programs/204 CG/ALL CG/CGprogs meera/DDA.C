#include<conio.h>
#include<graphics.h>
#include<math.h>
void main(void)
{
	int driver,mode,m=0,dx,dy,x1,y1,x2,y2,x,y,i;
	clrscr();
	driver = DETECT;
	printf("\n\n\tEnter starting point:");
	scanf("%d %d",&x1,&y1);
	printf("\n\n\tEnter ending point:");
	scanf("%d %d",&x2,&y2);
	initgraph(&driver,&mode,"Z:\\tc\tc\bgi");
	dy = y2-y1;
	dx = x2-x1;
	outtextxy(x1,y1,"(x1,y1)");
	outtextxy(x2,y2,"(x2,y2)");
	if(dx!=0)
	{
		m = dy/dx;
	}
	x = x1;y = y1;
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
		else
		{
			outtext("Other cases");
			return;
		}
	}
	//case1
	if(m==0)
	{
		if(dx==0 && dy!=0)
		{
			if(y2<y1)
			{
				//x = x2;y = y2;
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
					y=y+1;
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
					x=x+1;
				}
			}
		}
		else
		{
			outtextxy(50,50,"can't draw");
			getch();
			closegraph();
			exit(0);
		}
	}
	//case2
	else if(abs(m)>0||abs(m)<=1)
	{
		if(x2<x1)
		{
			x = x2;y = y2;
			for(i=x2;i<=x1;i++)
			{
				dx = 1;
				putpixel(x,y,WHITE);
				x= x+dx;
				y = y+m;
			}
		}
		else
		{
			for(i=x1;i<=x2;i++)
			{
				dx = 1;
				putpixel(x,y,WHITE);
				x= x+dx;
				y = y+m;
			}
		}

	}
	//case3
	else if(abs(m)>1||abs(m)<=5)
	{
		dy = 1;
		if(x2<x1)
		{
			x = x2;y = y2;
			for(i=x2;i<=x1;i++)
			{
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
				y = y + dy;
				x = (1/m)+x;
			}
		}
	}
	else
	{
		getch();
		closegraph();
		printf("\n\n\tYou have not consider other cases:");
	}
	getch();
	closegraph();
}