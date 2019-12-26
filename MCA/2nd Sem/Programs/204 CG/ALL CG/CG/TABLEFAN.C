#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
void ddaline(float,float,float,float,int c);
void clockcircle(float xc,float yc,float r,int c);
union REGS in,out;
void elipse();
void rotation(float z[]);
void erase(float z[]);
float a[8],b[8],c[8],d[8];
//void color(float a,float b,float cy);
//void erasecolor(float a, float b,float cy);
int n=6;
int xx,yy,button;
void main()
{
	int gd=DETECT,gm,i;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	clockcircle(300,150,100,WHITE);
	//from here
	//
	clockcircle(300,150,20,15);
	clockcircle(300,150,40,15);
	clockcircle(300,150,60,15);
	clockcircle(300,150,80,15);
	clockcircle(300,150,101,15);
	ddaline(300,150,360,70,15);
	ddaline(300,150,360,230,15);
	ddaline(300,150,240,70,15);
	ddaline(300,150,240,230,15);
	//
	//till here
       /*	ddaline(300,150,275,59,15);
	ddaline(300,150,325,59,15);
	ddaline(275,59,325,59,15);*/
	a[0]=300;a[1]=150;a[2]=275;a[3]=59;a[4]=325;a[5]=59;a[6]=300;a[7]=150;
	b[0]=300;b[1]=150;b[2]=390;b[3]=125;b[4]=390;b[5]=175;b[6]=300;b[7]=150;
	c[0]=300;c[1]=150;c[2]=325;c[3]=240;c[4]=275;c[5]=240;c[6]=300;c[7]=150;
	d[0]=300;d[1]=150;d[2]=210;d[3]=175;d[4]=210;d[5]=125;d[6]=300;d[7]=150;
/*	ddaline(300,150,390,125,15);
	ddaline(300,150,390,175,15);
	ddaline(390,125,390,175,15);
	ddaline(300,150,325,240,15);
	ddaline(300,150,275,240,15);
	ddaline(275,240,325,240,15);
	ddaline(300,150,210,125,15);
	ddaline(300,150,210,175,15);
	ddaline(210,125,210,175,15);*/
	ddaline(250,330,280,248,15);
	ddaline(250,330,350,330,15);
       //	ddaline(200,380,400,380,15);   //
	//ddaline(400,380,350,330,15); //

	ddaline(350,330,320,248,15);  //
	elipse();
	for(i=0;i<5;i++)
	{
		setcolor(RED);
		circle(300,280,i);
		setcolor(BLUE);
		circle(300,295,i);
	}
	//ddaline();
	//ddaline();
	//getch();
	while(!kbhit())
	{
		clockcircle(300,150,20,15);
		clockcircle(300,150,40,15);
		clockcircle(300,150,60,15);
		clockcircle(300,150,80,15);
		ddaline(300,150,360,70,15);
		ddaline(300,150,360,230,15);
		ddaline(300,150,240,70,15);
		ddaline(300,150,240,230,15);
		delay(50);
		erase(a);
		rotation(a);
		erase(b);
		rotation(b);
		erase(c);
		rotation(c);
		erase(d);
		rotation(d);
	}
	getch();
	while(!kbhit())
	{
		clockcircle(300,150,20,15);
		clockcircle(300,150,40,15);
		clockcircle(300,150,60,15);
		clockcircle(300,150,80,15);
		ddaline(300,150,360,70,15);
		ddaline(300,150,360,230,15);
		ddaline(300,150,240,70,15);
		ddaline(300,150,240,230,15);
		delay(10);
		erase(a);
		rotation(a);
		erase(b);
		rotation(b);
		erase(c);
		rotation(c);
		erase(d);
		rotation(d);
	}
      /* ddaline(300,270,300,350);
	ddaline(298,267,298,351);
	ddaline(302,267,302,351);
	clockcircle(300,370,20);
	//ddaline();*/
	getch();
	closegraph();

}
/*void erasecolor(float a, float b ,float cy)
{
	int i;
	for(i=a+1;i<b;i++)
	{
		ddaline(i,cy,300,150,getbkcolor());
	}
}
void color(float a,float b,float cy)
{
	int i;
	for(i=a+1;i<b;i++)
	{
		ddaline(i,cy,300,150,YELLOW);
	}
} */
void erase(float z[])
{
	int i;
	for(i=0;i<n;i=i+2)
	{
		ddaline(z[i],z[i+1],z[i+2],z[i+3],getbkcolor());
	}
}

void rotation(float z[])
{
	int i;
	float x1,x2,y1,y2;
	for(i=0;i<n;i=i+2)
	{
		if(i==2){
		continue;
		}else
		{
		x1=fabs(300+(z[i]-300)*cos(-30)-(z[i+1]-150)*sin(-30));
		x2=fabs(300+(z[i+2]-300)*cos(-30)-(z[i+3]-150)*sin(-30));
		y1=fabs(150+(z[i]-300)*sin(-30)+(z[i+1]-150)*cos(-30));
		y2=fabs(150+(z[i+2]-300)*sin(-30)+(z[i+3]-150)*cos(-30));
	       }
	       //	printf("%f %f %f %f",x1,y1,x2,y2);
		z[i]=x1;
		z[i+1]=y1;
		z[i+2]=x2;
		z[i+3]=y2;
		ddaline(z[i],z[i+1],z[i+2],z[i+3],YELLOW); //n
	}
	ddaline(z[2],z[3],z[4],z[5],YELLOW); //n
}
void elipse()
{
	float rx=100,ry=40,xc=300,yc=350,r,xcur,ycur,p,x,y;
	xcur=0;
	ycur=ry;
	putpixel(xcur+xc,ycur+yc,WHITE);
	p=(ry*ry)-(rx*rx*ry)+(rx*rx)/4;
	x=ry*ry*xcur;
	y=rx*rx*ycur;
	while(x<=y && rx>0 && ry>0)
	{
		if(p>=0)
		{
			p=p+2*ry*ry*(xcur+1)+ry*ry+2*rx*rx*(1-ycur);
			ycur=ycur-1;
		}
		else
		{
			p=p+2*ry*ry*(xcur+1)+ry*ry;
		}
		xcur=xcur+1;
		x=ry*ry*xcur;
		y=rx*rx*ycur;
		putpixel(xcur+xc,ycur+yc,WHITE);
		putpixel(-xcur+xc,-ycur+yc,WHITE);
		putpixel(-xcur+xc,ycur+yc,WHITE);
		putpixel(xcur+xc,-ycur+yc,WHITE);
	}
	p=ry*ry*(xcur+0.5)*(xcur+0.5)+rx*rx*(ycur-1)*(ycur-1)-rx*rx*ry*ry;
	while(ycur>=0 && rx>0 && ry>0){
		if(p>=0)
		{
			p=p+rx*rx*(3-2*ycur);
		}
		else
		{
			p=p+ry*ry*(2*xcur+2)+rx*rx*(3-2*ycur);
			xcur=xcur+1;
		}
		ycur=ycur-1;
		putpixel(xcur+xc,ycur+yc,WHITE);
		putpixel(-xcur+xc,-ycur+yc,WHITE);
		putpixel(-xcur+xc,ycur+yc,WHITE);
		putpixel(xcur+xc,-ycur+yc,WHITE);
	}
}
void clockcircle(float xc,float yc,float r,int c)
{
	float xcur,ycur,p;
	xcur=0;
	ycur=r;
	putpixel(xcur+xc,ycur+yc,c);
	p=(xcur+1)*(xcur+1)+(ycur-0.5)*(ycur-0.5)-(r*r);
	while(xcur<=ycur && r>0)
	{
		if(p>=0)
		{
			p=p+2*xcur-2*ycur+5;
			ycur=ycur-1;
		}
		else
		{
			p=p+2*xcur+3;
		}
		xcur=xcur+1;
		putpixel(xcur+xc,ycur+yc,c);
		putpixel(-xcur+xc,-ycur+yc,c);
		putpixel(-xcur+xc,ycur+yc,c);
		putpixel(xcur+xc,-ycur+yc,c);
		putpixel(-ycur+xc,xcur+yc,c);
		putpixel(ycur+xc,xcur+yc,c);
		putpixel(ycur+xc,-xcur+yc,c);
		putpixel(-ycur+xc,-xcur+yc,c);

	}
}
void ddaline(float x1,float y1,float x2,float y2,int c)
{
	float m,mh,xcur,ycur;
	if(x1<0 || x2<0 || y1<0 || y2<0 || x1>getmaxx() || x2>getmaxx() || y1>getmaxy() || y2>getmaxy())
	{
		printf("\nCoordinate value(s) out of bound");
		getch();
		exit(0);
	}
	xcur=x1;
	ycur=y1;
	if(x1==x2)
	{
		if(y1<=y2)
		{
			while(ycur<=y2)
			{
				putpixel(xcur,ycur,c);
				ycur++;
			}
		}
		else
		{
			while(ycur>=y2)
			{
				putpixel(xcur,ycur,c);
				ycur--;
			}
		}
	}else if(y1==y2)
	{
		if(x1<=x2)
		{
			while(xcur<=x2)
			{
				putpixel(xcur,ycur,c);
				xcur++;
			}
		}
		else
		{
			while(xcur>=x2)
			{
				putpixel(xcur,ycur,c);
				xcur--;
			}
		}

	}
	else
	{
		m=(y2-y1)/(x2-x1);
		//printf("\n\n%f",m);
		if(m<=1)
		{
			if(x1<x2)
			{
				while(xcur<=x2)
				{
					putpixel(xcur,ycur,c);
					ycur=ycur+m;
					xcur++;
				}
			}
			else
			{
				while(xcur>=x2)
				{
					putpixel(xcur,ycur,c);
					ycur=ycur-m;
					xcur--;
				}
			}
		}else{
			mh=1/m;
			if(y1<y2)
			{
				while(ycur<=y2)
				{
					putpixel(xcur,ycur,c);
					xcur=xcur+mh;
					ycur++;
				}
			}
			else
			{
				while(ycur>=y2)
				{
					putpixel(xcur,ycur,c);
					xcur=xcur-mh;
					ycur--;
				}
			}
		}
	}
}
