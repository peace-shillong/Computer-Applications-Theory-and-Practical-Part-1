#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
#include<process.h>
#define ROUND(a) ((int)(a+0.5))

void line_eq(int x1,int y1,int x2,int y2,int c)
{
	int x,y;
	if((abs(x1-x2)/abs(y2-y1))>=1)
		for(x=x1;x<=x2;x++)
		{
			y=(((x-x1)*(y1-y2))/(x1-x2))+y1;
			putpixel(x,y,c);
		}
	else
		for(x=x1;x>=x2;x--)
		{
			y=(((x-x1)*(y1-y2))/(x1-x2))+y1;
			putpixel(x,y,c);
		}
}
void line_dda(int x1,int y1,int x2,int y2,int c)        //DDA Line Algorithm
{
	int dx,dy,k,steps;
	float ddx,ddy,x=x1,y=y1;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	ddx=dx/(float)steps;
	ddy=dy/(float)steps;
	//putpixel(ROUND(x),ROUND(y),c);
	for(k=0;k<=steps;k++)
	{
		putpixel(ROUND(x),ROUND(y),c);
		x+=ddx;
		y+=ddy;
		//putpixel(ROUND(x),ROUND(y),c);
	}
}
void polygn(int s,int *poly,int c)
{
	int i,k,x1,x=poly[0],y1,y=poly[1],x2,y2;
	x2=x;
	y2=y;
	for(i=1,k=2;i<s;i++)
	{
		x1=poly[k++];
		y1=poly[k++];
		line_dda(x,y,x1,y1,c);
		x=x1;
		y=y1;
	}
	line_dda(x,y,x2,y2,c);

}

void circl(int x1,int y1,int r)
{
	int x,y;
	for(x=x1-r;x<=x1+r;x++)
	{
		y=y1+sqrt(r*r-pow((x1-x),2));
		putpixel(x,y,WHITE);
		y=y1-sqrt(r*r-pow((x1-x),2));
		putpixel(x,y,WHITE);
	}
	for(y=y1-r;y<=y1+r;y++)
	{
		x=x1+sqrt(r*r-pow((y1-y),2));
		putpixel(x,y,WHITE);
		x=x1-sqrt(r*r-pow((y1-y),2));
		putpixel(x,y,WHITE);
	}
}
void bres(int x1, int y1, int x2, int y2,int c)
{
	int dx, dy, x=x1,y=y1,s1,s2,swap=0,p,temp,i;
	s1=(x2-x1);
	s2=(y2-y1);
	dx=abs(s1);
	dy=abs(s2);
	swap=0;
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		swap=1;
	}
	p=(2*dy)-dx;
	for(i=0;i<dx;i++)
	{
		putpixel(x,y,c);
		while(p>=0)
		{
			p=p-2*dx;
			if(swap)
				x+=s1;
			else
				y+=s2;

			p=p+2*dy;
			if(swap)
				y+=s2;
			else
				x+=s1;
		}
	}
}

void rotatehand(int &x,int &y,int xf,int yf,float theta,int color)
{
	line_dda(x,y,xf,yf,BLACK);
	theta=6.28*(theta/360);
	float x1=ROUND((float)(xf+(x-xf)*cos(theta)-(y-yf)*sin(theta)));
	float y1=ROUND((float)(yf+(x-xf)*sin(theta)+(y-yf)*cos(theta)));
	x=ROUND(x1);y=ROUND(y1);
	line_dda(x,y,xf,yf,color);
}
void rotatependulum(int &x,int &y,int xf,int yf,float theta)
{
	theta=6.28*(theta/360);
	float x1=ROUND((float)(xf+(x-xf)*cos(theta)-(y-yf)*sin(theta)));
	float y1=ROUND((float)(yf+(x-xf)*sin(theta)+(y-yf)*cos(theta)));
	x=ROUND(x1);y=ROUND(y1);
}

void main()
{
	int min[]={250,150,250,90},sec[]={250,150,250,80},hr[]={250,150,250,100},pendlm[]={250,240,250,380};
	int gd=DETECT,mode;
	char *str;
	struct time t;
	gettime(&t);
	initgraph(&gd,&mode,"c:\\tc\\bgi");

	//setcolor(YELLOW);
	//circle(250,240,30);
	//setcolor(YELLOW);
	//circle(250,150,85);
	circle(250,150,50);
	circle(250,150,90);

	line(175,201,175,430);
	line(325,201,325,430);
	//line(185,250,312,250);//_
	//line(185,265,312,265);//_
	line(175,430,325,430);
	line(170,190,170,440);
	line(330,190,330,440);
	line(170,440,330,440);
	//circle(250,80,2);
	outtextxy(245,85,"12");

	outtextxy(305,148,"3");
	outtextxy(250,210,"6");
	outtextxy(185,148,"9");


	int xc=250,yc=400,s=1,i,j;
	line_dda(hr[0],hr[1],hr[2],hr[3],BLACK);		//hr hand
	{
		int theta=(int)t.ti_hour;
		if(theta>12) theta-=12;
		theta*=30;
		rotatehand(hr[2],hr[3],250,150,theta,WHITE);
	}
	line_dda(min[0],min[1],min[2],min[3],BLACK);             //min hand
	rotatehand(min[2],min[3],250,150,((int)t.ti_min*6),CYAN);

	line_dda(sec[0],sec[1],sec[2],sec[3],RED);		//sec hand
	rotatehand(sec[2],sec[3],250,150,((int)t.ti_sec*6),RED);


	while(!kbhit())
	{
		rotatehand(sec[2],sec[3],250,150,6,RED);
		if(((abs(sec[2]-250)<=5))&&(sec[3]<150))
			rotatehand(min[2],min[3],250,150,6,CYAN);
		else
			line_dda(min[0],min[1],min[2],min[3],CYAN);
		if(((abs(min[2]-250)<=5))&&(min[3]<150))
			rotatehand(hr[2],hr[3],250,150,6,WHITE);
		else
			line_dda(hr[0],hr[1],hr[2],hr[3],WHITE);
		for(j=1;j<=2;j++)
		for(i=1;i<=10;i++)
		{
			if(xc<200||xc>300)
			{
				s*=-1;sound(8000);delay(10);nosound();}
				setcolor(BLACK);
				circle(xc,yc,20);
				rotatependulum(xc,yc,250,240,s*2);
				setcolor(WHITE);
				circle(xc,yc,20);
				line_dda(pendlm[0],pendlm[1],pendlm[2],pendlm[3],BLACK);
				rotatependulum(pendlm[0],pendlm[1],250,240,s*2);
				rotatependulum(pendlm[2],pendlm[3],250,240,s*2);
				line_dda(pendlm[0],pendlm[1],pendlm[2],pendlm[3],WHITE);
				delay(50);
			}

		}
	getch();
}



