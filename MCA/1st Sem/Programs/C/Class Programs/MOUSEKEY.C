#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

union REGS  i,o;

void main()
{
	int gd=DETECT,gm;
	int button,x,y;

	initgraph(&gd,&gm,"C:\\TC\\bgi");

	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(50,50,50);
	floodfill(50,50,RED);

	setcolor(GREEN);
	setfillstyle(SOLID_FILL,GREEN);
	circle(160,50,50);
	floodfill(160,50,GREEN);

	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	circle(300,50,50);
	floodfill(300,50,BLUE);

	showmouseptr();
	while(!kbhit())
	{
		getmousepos(&button,&x,&y);
		gotoxy(5,3);

		(button==1)?printf("DOWN"):printf("UP");
		gotoxy(20,3);

		(button==2)?printf("DOWN"):printf("UP");
		gotoxy(65,3);

		printf("x=%d y=%d",x,y);

		if((x>0)||(x<100))&&((y>0)||(y<100))
		{
				setcolor(BLUE);
				setfillstyle(SOLID_FILL,BLUE);
				floodfill(50,50,BLUE);
		}


	}
	getch();
	closegraph();

}

 initmouse()
{
	i.x.ax=0;
	int86(0x33,&i,&o);
	return(o.x.ax);
}

 showmouseptr()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}

 getmousepos(int *button,int *x,int *y)
{
	i.x.ax=3;
	int86(0x33,&i,&o);

	*button=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
	return;
}
