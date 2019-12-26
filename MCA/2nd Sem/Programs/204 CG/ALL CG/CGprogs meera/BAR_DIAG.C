#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void drawline(int,int,int,int);
void color(int,int,int);
void main()
{
	int driver,mode,m=0,x1,y1,x2,y2,x,y,i;
	clrscr();
	driver = DETECT;
	initgraph(&driver,&mode,"Z:\\tc\tc\bgi");
	outtextxy(300,50,"scale = 10,00,000");
	outtextxy(100,20,"----PUPULATION BAR DIAGRAM OF NORTHEAST STATES----");
	outtextxy(300,60,"A = Assam 3,11,69,272");
	outtextxy(300,70,"T = Tripura 39,71,032");
	outtextxy(300,80,"Me = Meghalaya 29,64,008");
	outtextxy(300,90,"Ma = Manipur 27,21,756");
	outtextxy(300,100,"N = Nagaland 19,80,602");
	outtextxy(300,110,"Ar = Arunachal pradesh 13,82,611 ");
	outtextxy(300,120,"Mi = Mizoram 10,91,014");
	drawline(50,50,50,400);
	drawline(30,100,30,200);
	drawline(200,430,300,430);
	drawline(50,400,400,400);
	outtextxy(320,430,"States");
	drawline(40,390,60,390); //10,00,000
	drawline(40,380,60,380); //20,00,000
	drawline(40,370,60,370); //30,00,000
	drawline(40,360,60,360); //40,00,000
	drawline(40,350,60,350); //50,00,000
	drawline(40,340,60,340); //60,00,000
	drawline(40,330,60,330); //70,00,000
	drawline(40,320,60,320); //80,00,000
	drawline(40,310,60,310); //1,00,00,000
	drawline(40,300,60,300); //1,10,00,000
	drawline(40,290,60,290); //1,20,00,000
	drawline(40,280,60,280); //1,30,00,000
	drawline(40,270,60,270); //1,40,00,000
	drawline(40,260,60,260); //1,50,00,000
	drawline(40,250,60,250); //1,60,00,000
	drawline(40,240,60,240); //1,70,00,000
	drawline(40,230,60,230); //1,80,00,000
	drawline(40,220,60,220); //1,90,00,000
	drawline(40,210,60,210); //2,00,00,000
	drawline(40,200,60,200); //2,10,00,000
	drawline(40,190,60,190); //2,20,00,000
	drawline(40,180,60,180); //2,30,00,000
	drawline(40,170,60,170); //2,40,00,000
	drawline(40,160,60,160); //2,50,00,000
	drawline(40,150,60,150); //2,60,00,000
	drawline(40,140,60,140); //2,70,00,000
	drawline(40,130,60,130); //2,80,00,000
	drawline(40,120,60,120); //2,90,00,000
	drawline(40,110,60,110); //3,00,00,00
	drawline(40,130,60,130); //3,10,00,00
	drawline(40,140,60,140); //3,20,00,00

	drawline(80,400,80,110);
	drawline(80,110,90,110);
	drawline(90,400,90,110);
	outtextxy(80,410,"A");
	color(81,399,BLUE);

	drawline(110,400,110,365);
	drawline(110,365,120,365);
	drawline(120,400,120,365);
	outtextxy(110,410,"T");
	color(111,399,RED);

	drawline(140,400,140,375);
	drawline(140,375,150,375);
	drawline(150,400,150,375);
	outtextxy(140,410,"Me");
	color(141,399,GREEN);

	drawline(170,400,170,378);
	drawline(170,378,180,378);
	drawline(180,400,180,378);
	outtextxy(170,410,"Ma");
	color(171,399,YELLOW);

	drawline(200,400,200,385);
	drawline(200,385,210,385);
	drawline(210,400,210,385);
	outtextxy(200,410,"N");
	color(201,399,6);

	drawline(230,400,230,388);
	drawline(230,388,240,388);
	drawline(240,400,240,388);
	outtextxy(230,410,"Ar");
	color(231,399,8);

	drawline(260,400,260,390);
	drawline(260,390,270,390);
	drawline(270,400,270,390);
	outtextxy(260,410,"Mi");
	color(261,399,5);
	settextstyle(SMALL_FONT,VERT_DIR,5);
	outtextxy(25,200,"population");
	getch();
	closegraph();
}
void color(int x,int y,int col)
{
	int colr,temp = x;
	colr = getpixel(x,y);
	while(colr!=WHITE)
	{
		while(colr!=WHITE)
		{
			putpixel(x,y,col);
			x+=1;
			colr = getpixel(x,y);
			if(colr==WHITE)
			{
				break;
			}
		}
		x = temp;
		y = y-1;
		colr = getpixel(x,y);
	}
}
void drawline(int x1,int y1,int x2,int y2)
{
	int d1,d2,x,y,dx,dy,pk,i,xs,ck,c1,c2,ys;
	float m=0;
	dx = x2-x1; dy = y2-y1;
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
		if(x1<x2)
		{
			x = x1;y = y1;xs = x2;
		}
		else
		{
			x = x2;y= y2;xs=x1;
		}
		while(x<xs)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk = pk+(2*dy);
				y = y-1;
			}
			else
			{
				pk = pk+(2*(dy-dx));
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
			x = x1;y = y1,xs = x2;
		}
		else
		{
			x = x2;y= y2;xs = x1;
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
				y = y+1;
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
			x= x1;y = y1;ys = y2;
		}
		else
		{
			x = x2;y = y2;ys = y1;
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
				x = x+1;
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
			x= x1;y = y1;ys = y2;
		}
		else
		{
			x = x2;y = y2;ys = y1;
		}
		while(y<ys)
		{
			putpixel(x,y,WHITE);
			if(ck<0)
			{
				ck = ck-(dy*x1);
				//pk = pk+(2*dx);
				x = x-1;
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