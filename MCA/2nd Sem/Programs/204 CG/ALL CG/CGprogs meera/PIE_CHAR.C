#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void drawcircle();
void drawline(int,int,int,int);
void color(int xc,int yc,int col,int bcolor);
int main()
{
	int driver,mode,xc,yc,r;
	clrscr();
	driver = DETECT;
	initgraph(&driver,&mode,"Z:\\tc\tc\bgi");
	drawcircle();
	outtextxy(100,20,"----PIE_CHART FOR NORTHEAST STATES' POPULATION----");
	outtextxy(310,130,"ASSAM (69.30%)");
	drawline(200,150,300,150);
	drawline(200,150,150,240);
	outtextxy(100,270,"TRIPURA (8.16%)");
	drawline(200,150,225,249);
	outtextxy(240,250,"MEGHALAYA (6.59%)");
	drawline(200,150,265,230);
	outtextxy(280,220,"MANIPUR (6.05%)");
	drawline(200,150,290,200);
	outtextxy(300,190,"NAGALAND (4.40%)");
	drawline(200,150,298,180);
	outtextxy(310,170,"ARUNACHAL PRADESH (3.07%)");
	drawline(200,150,299,164);
	outtextxy(310,150,"MIZORAM (2.43%)");

	color(170,130,RED,WHITE);
	color(140,180,RED,WHITE);
	color(150,230,RED,WHITE);
	color(200,60,RED,WHITE);

	color(200,200,GREEN,WHITE);

	color(240,200,YELLOW,WHITE);
	color(230,200,YELLOW,WHITE);
	color(205,160,YELLOW,WHITE);
	color(211,166,YELLOW,WHITE);

	color(270,190,11,WHITE);
	color(230,170,11,WHITE);
	color(250,180,11,WHITE);
	color(205,155,11,WHITE);
	color(210,160,11,WHITE);
	color(215,165,11,WHITE);
	//color(290,170,BLUE,WHITE);

	color(250,170,BLUE,WHITE);
	color(291,190,BLUE,WHITE);
	color(220,160,BLUE,WHITE);

	color(280,170,13,WHITE);

	color(295,151,9,WHITE);

	getch();
	return 0;
}
void color(int xc,int yc,int col,int bcolor)
{
	int i,j,colr1,colr2;
	i = xc;j = yc;
	colr2 = getpixel(i,j);
	colr1 = colr2;
	while(colr1!=bcolor)
	{
		while(colr2!=bcolor)
		{
			putpixel(i,j,col);
			i++;
			colr2 = getpixel(i,j);
		}
		j++;
		i = xc;
		colr1 = colr2 = getpixel(i,j);
	}
	i = xc;j = yc;
	colr1 = colr2 =  getpixel(i,j);
	while(colr1!=bcolor)
	{
		while(colr2!=bcolor)
		{
			putpixel(i,j,col);
			i--;
			colr2 = getpixel(i,j);
		}
		j--;
		i = xc;
		colr1 = colr2 = getpixel(i,j);
	}
	i = xc;j = yc;
	colr1 = colr2 = getpixel(i,j);
	while(colr1!=bcolor)
	{
		while(colr2!=bcolor)
		{
			putpixel(i,j,col);
			i++;
			colr2 = getpixel(i,j);
		}
		j--;
		i = xc;
		colr1 = colr2 = getpixel(i,j);
	}
	i = xc;j = yc;
	colr1 = colr2 = getpixel(i,j);
	while(colr1!=bcolor)
	{
		while(colr2!=bcolor)
		{
			putpixel(i,j,col);
			i--;
			colr2 = getpixel(i,j);
		}
		j++;
		i = xc;
		colr1 = colr2 = getpixel(i,j);
	}
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
void drawcircle()
{
	 int x,y,i,xc=200,yc=150,r=100;
	 float pk,s=-1;
	 x = 0;y = r;
	 //pk = f(x+1,y-(1/2),r);
	 pk = 1-r;
	 //pk = 5/4-r;
	 while(x<y)
	 {
		if(pk<0)
		{
			pk = pk+(2*x)+3;
			y = y;
		}
		else
		{
			pk = pk+(2*x)-(2*y)+5;
			y  = y - 1;
		}
		x = x+1;
		putpixel(x+xc,y+yc,WHITE);
		//xarray[i++]=x+xc;yarray[s++];
		putpixel(y+xc,x+yc,WHITE);
		//xarray[i++]=x+xc;yarray[s++];
		putpixel(y+xc,-x+yc,WHITE);
		//xarray[i++]=x+xc;yarray[s++];
		putpixel(x+xc,yc-y,WHITE);
		//xarray[i++]=x+xc;yarray[s++];
		putpixel(xc-x,yc-y,WHITE);
		//xarray[i++]=x+xc;yarray[s++];
		putpixel(xc-y,yc-x,WHITE);
		//xarray[i++]=x+xc;yarray[s++];
		putpixel(xc-y,x+yc,WHITE);
		//xarray[i++]=x+xc;yarray[s++];
		putpixel(xc-x,y+yc,WHITE);
		//xarray[i++]=x+xc;yarray[s++];
	 }
	 putpixel(xc+r,yc,WHITE);
	 putpixel(xc-r,yc,WHITE);
	 putpixel(xc,yc-r,WHITE);
	 putpixel(xc,yc+r,WHITE);
}