#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>



	void linedda(int,int,int,int);
	void main()
	{
		int x1,y1,x2,y2;

		int gd=DETECT,gm;
			clrscr();
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		printf("\n\tEnter the first coordinates x1 and y1:");
		scanf("%d %d",&x1,&y1);
		printf("\n\tEnter the last coordinates x2 and y2:");
		scanf("%d %d",&x2,&y2);
		linedda(x1,y1,x2,y2);
		getch();
	 }
	 void linedda(int x1,int y1,int x2,int y2)
	 {
		float  x,y,xinc,yinc,dx,dy;
		int k,step;
		dx=x2-x1;
		dy=y2-y1;
		if(abs(dx)>abs(dy))
		step=abs(dx);
		else
		step=abs(dy);
		xinc=dx/step;
		yinc=dy/step;
		x=x1;
		y=y1;
		putpixel(x,y,WHITE);

		for(k=1;k<=step;k++)
		{

		       x=x+xinc;
		       y=y+yinc;
		       putpixel(x,y,WHITE);

		}

	 }





