#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
#include<process.h>
void drawline(int,int,int,int,int);
void drawcircle(int,int,int,int);
void color(int,int,int,int);
void translate(int*,int*);
void main()
{
	int driver,mode,x[11],y[11],maxx;
	clrscr();
	driver = DETECT;
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	drawline(1,401,650,401,WHITE);//line
	drawline(70,280,170,280,WHITE); //70 280 170 280 1
	drawline(70,280,70,330,WHITE); //70 330  2
	drawline(170,280,170,330,WHITE);//170 330 3
	drawline(70,330,40,330,WHITE); //40 330  4
	drawline(170,330,200,330,WHITE);//200 330 5
	drawline(40,330,40,370,WHITE); //40 370  6
	drawline(200,330,200,370,WHITE);//200 370 7
	drawline(40,370,200,370,WHITE);  //8
	drawcircle(70,385,15,WHITE); //70 385 9
	drawcircle(170,385,15,WHITE); //170 385 10
	color(71,386,8,WHITE);
	color(171,386,8,WHITE);
	color(100,300,12,WHITE);
	x[0]=70;y[0]=280;
	x[1]=170;y[1]=280;
	x[2]=70;y[2]=330;
	x[3]=170;y[3]=330;
	x[4]=40;y[4]=330;
	x[5]=200;y[5]=330;
	x[6]=40;y[6]=370;
	x[7]=200;y[7]=370;
	x[8]=70;y[8]=385;
	x[9]=170;y[9]=385;
	x[10]=71;y[10]=281;
	translate(x,y);
	getch();
	closegraph();
}
void translate(int x[],int y[])
{
	int tx = 1,ty = 0,i;
	for(i = 0;i<400;i++)
	{
		if(kbhit())
		{
			break;
		}
		color(x[10],y[10],12,WHITE);
		color(x[8],y[8],8,WHITE);
		color(x[9],y[9],8,WHITE);
		drawline(x[0],y[0],x[1],y[1],BLACK);
		drawline(x[0],y[0],x[2],y[2],BLACK);
		drawline(x[1],y[1],x[3],y[3],BLACK);
		drawline(x[2],y[2],x[4],y[4],BLACK);
		drawline(x[3],y[3],x[5],y[5],BLACK);
		drawline(x[4],y[4],x[6],y[6],BLACK);
		drawline(x[5],y[5],x[7],y[7],BLACK);
		drawline(x[6],y[6],x[7],y[7],BLACK);
		drawcircle(x[8],y[8],15,BLACK);
		drawcircle(x[9],y[9],15,BLACK);
		x[0] = x[0]+tx;
		y[0] = y[0]+ty;
		x[1] = x[1]+tx;
		y[1] = y[1]+ty;
		x[2] = x[2]+tx;
		y[2] = y[2]+ty;
		x[3] = x[3]+tx;
		y[3] = y[3]+ty;
		x[4] = x[4]+tx;
		y[4] = y[4]+ty;
		x[5] = x[5]+tx;
		y[5] = y[5]+ty;
		x[6] = x[6]+tx;
		y[6] = y[6]+ty;
		x[7] = x[7]+tx;
		y[7] = y[7]+ty;
		x[8] = x[8]+tx;
		y[8] = y[8]+ty;
		x[9] = x[9]+tx;
		y[9] = y[9]+ty;
		x[10] = x[10]+tx;
		y[10] = y[10]+ty;
		drawline(x[0],y[0],x[1],y[1],WHITE);
		drawline(x[0],y[0],x[2],y[2],WHITE);
		drawline(x[1],y[1],x[3],y[3],WHITE);
		drawline(x[2],y[2],x[4],y[4],WHITE);
		drawline(x[3],y[3],x[5],y[5],WHITE);
		drawline(x[4],y[4],x[6],y[6],WHITE);
		drawline(x[5],y[5],x[7],y[7],WHITE);
		drawline(x[6],y[6],x[7],y[7],WHITE);
		drawcircle(x[8],y[8],15,WHITE);
		drawcircle(x[9],y[9],15,WHITE);
		delay(1);
	}
}
void drawcircle(int xc,int yc,int r,int cl)
{
	 int x,y;
	 float pk;
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
		putpixel(x+xc,y+yc,cl);
		putpixel(y+xc,x+yc,cl);
		putpixel(y+xc,-x+yc,cl);
		putpixel(x+xc,yc-y,cl);
		putpixel(xc-x,yc-y,cl);
		putpixel(xc-y,yc-x,cl);
		putpixel(xc-y,x+yc,cl);
		putpixel(xc-x,y+yc,cl);
	 }
	 putpixel(xc+r,yc,cl);
	 putpixel(xc-r,yc,cl);
	 putpixel(xc,yc-r,cl);
	 putpixel(xc,yc+r,cl);

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
		colr1 = getpixel(i,j);
		colr2 = getpixel(i,j);
	}
	i = xc;j = yc;
	colr1 =  getpixel(i,j);
	colr2 =  getpixel(i,j);
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
	colr1 = getpixel(i,j);
	colr2 = getpixel(i,j);
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
void drawline(int x1,int y1,int x2,int y2,int cl)
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
					putpixel(x,y,cl);
					y = y+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,cl);
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
					putpixel(x,y,cl);
					x= x+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=x2;i<=x1;i++)
				{
					putpixel(x,y,cl);
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
			putpixel(x,y,cl);
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
			putpixel(x,y,cl);
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
			putpixel(x,y,cl);
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
			putpixel(x,y,cl);
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