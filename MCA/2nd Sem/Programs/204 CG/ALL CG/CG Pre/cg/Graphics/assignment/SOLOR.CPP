#include<conio.h>
#include<dos.h>
//#include<d:\mydocs\sem2\cg\draw.h>
#include<Z:\draw.h>
void rotate(int *xp,int *yp,int xf,int yf,float *theta)
{
	float x1,y1,thta[8];
	for(int i=0;i<8;i++)
	{
		thta[i]=6.28*(theta[i]/360);
		x1=ROUND((float)(xf+(xp[i]-xf)*cos(thta[i])-(yp[i]-yf)*sin(thta[i])));
		y1=ROUND((float)(yf+(xp[i]-xf)*sin(thta[i])+(yp[i]-yf)*cos(thta[i])));
		xp[i]=ROUND(x1);yp[i]=ROUND(y1);
	}
}
void main()
{
	int gd =DETECT,mode;
	initgraph(&gd,&mode,"c:\\tc\\bgi");
	int x=getmaxx()/2,y=getmaxy()/2;
	circle(x,y,20);

	int xp[]={x-30,x-50,x-70,x-100,x-130,x-160,x-180,x-200};
	int yp[]={y,y,y,y,y,y,y,y};
	int orbit[]={x-30,x-50,x-70,x-100,x-130,x-160,x-180,x-200};
	int size[]={3,5,8,10,8,5,5,4};
	float theta[]={8,4,3,4,3,4,3.5,1};
	//for(int i=0;i<8;i++)
	  //	circle(x,y,x-xp[i]);
	for(int i=0;i<8;i++)
	{
		circle(xp[i],yp[i],size[i]);
		setcolor(i);
	}
	while(!kbhit())
	{
		setcolor(BLACK);
		for(i=0;i<8;i++)
		{
			circle(x,y,x-orbit[i]);

		}
		for(i=0;i<8;i++)
		{      // fldfil(xp[i],yp[i],BLACK);
			circle(xp[i],yp[i],size[i]);
		}
		setcolor(WHITE);
		rotate(xp,yp,x,y,theta);
		for(i=0;i<8;i++)
		{
			circle(xp[i],yp[i],size[i]);
			setcolor(i+1);

		}
		for(i=0;i<8;i++)
			circle(x,y,x-orbit[i]);
		delay(100);
	}
	getch();
}