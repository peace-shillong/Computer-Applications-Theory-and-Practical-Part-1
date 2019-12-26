#include<graphics.h>
#include<conio.h>
#include<math.h>
void elipse(float,float,float,float);
void color(int,int,int,int);
void rotate(double*,double*);
void drawcircle(int xc,int yc,int r,int cl)
{
	 int x,y,i;
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
	 putpixel(xc,yc+r,cl);
	 putpixel(xc,yc-r,cl);
}
void main()
{
	int driver = DETECT,mode;
	double mars[5],earth[5];
	clrscr();
	initgraph(&driver,&mode,"Z:\\tc\tc\bgi");
       //	elipse(250,200,150,100);
       //	elipse(250,200,200,150);
	elipse(250,200,170,130);
	elipse(250,200,240,200);
	drawcircle(250,200,30,WHITE);
	color(250,200,YELLOW,WHITE);
	drawcircle(200,105,15,WHITE);  //mars
	color(200,105,RED,WHITE);
	//color(200,108,RED,WHITE);
	drawcircle(100,100,10,WHITE);  //earth
	color(100,100,BLUE,WHITE);
	//color(100,104,BLUE,WHITE);
	mars[0] = 200;mars[1] = 105;mars[2] = 108;
	earth[0] = 100;earth[1]= 100;earth[2]=104;
	rotate(mars,earth);
	getch();
	closegraph();
}
void rotate(double mars[],double earth[])
{
	int pre1,pre2;
	double a,i;
	while(1)
	{
		if(kbhit())
		{
			break;
		}
			color(mars[0],mars[1],RED,WHITE);
			color(earth[0],earth[1],BLUE,WHITE);
		color(mars[0],mars[1],BLACK,WHITE);
		drawcircle(mars[0],mars[1],15,BLACK);
		color(earth[0],earth[1],BLACK,WHITE);
		drawcircle(earth[0],earth[1],10,BLACK);


		a = (3.14/360);
		//a = 0.2999;

		pre1 = mars[0];pre2 = earth[0];
		mars[0] = (mars[0]*cos(a))-(mars[1]*sin(a))+(250*(1-cos(a))+(200*sin(a)));
		mars[1] = (pre1*sin(a))+(mars[1]*cos(a))+(200*(1-cos(a))-(250*sin(a)));

		earth[0] = (earth[0]*cos(a))-(earth[1]*sin(a))+(250*(1-cos(a))+(200*sin(a)));
		earth[1] = (pre2*sin(a))+(earth[1]*cos(a))+(200*(1-cos(a))-(250*sin(a)));

		drawcircle(mars[0],mars[1],15,WHITE);
		color(mars[0],mars[1],RED,WHITE);

		drawcircle(earth[0],earth[1],10,WHITE);
		color(earth[0],earth[1],BLUE,WHITE);
		delay(30);
	}
}
void elipse(float xc,float yc,float rx,float ry)
{
	float x,y,x1,y1,p1,p2,x0,y0,v1,v2;
	x = 0;
	y = ry;
	p1 = (ry*ry)-((rx*rx)*ry)+((0.25)*rx*rx);
	v1 = 2*ry*ry*x;
	v2 = 2*rx*rx*y;
	putpixel(x+xc,y+yc,7);
	putpixel(x+xc,yc-y,7);
	putpixel(xc-x,yc-y,7);
	putpixel(xc-x,y+yc,7);
	//region 1
	while(v1<v2)
	{
		x = x+1;
		if(p1<0)
		{
			p1 = p1+((ry*ry)*(2*x+3));
		}
		else if(p1>=0)
		{
			y = y-1;
			p1 = p1+((ry*ry)*(2*x+3))-(2*(rx*rx)*(y-1));
		}
		putpixel(x+xc,y+yc,7);
		putpixel(x+xc,yc-y,7);
		putpixel(xc-x,yc-y,7);
		putpixel(xc-x,y+yc,7);
		v1 = (2*ry*ry*x)+(2*ry*ry);
		v2 = (2*rx*rx*y)-(2*rx*rx);
	}
	//region 2
	p2 = (ry*ry)*(x+0.5)*(x+0.5)+(rx*rx)*(y-1)*(y-1)-(rx*rx)*(ry*ry);
	while(y>=0)
	{
		y = y-1;
		//v2 = (2*rx*rx*y)-(2*rx*rx);
		if(p2<=0)
		{
			x = x+1;
		  //  	v1 = (2*ry*ry*x)+(2*ry*ry);
			p2 = p2+(rx*rx)*(3-(2*y))+(ry*ry)*((2*x)+2);
		}
		else if(p2>0)
		{
			x = x;
			p2 = p2+(rx*rx)*(3-2*y);
		}
		//p2 = p2+(2*(rx*rx)*(y-1))+(rx*rx)+(ry*ry)*((x+1+1/2)*(x+1+1/2))-((x+1/2)*(x+1/2));
		v2 = v2-(2*rx*rx*y);
		v1 = (2*ry*ry*x)+v1;
		putpixel(x+xc,y+yc,7);
		putpixel(x+xc,yc-y,7);
		putpixel(xc-x,yc-y,7);
		putpixel(xc-x,y+yc,7);
	}
}
void color(int xc,int yc,int col,int bcolor)
{
	int i,j,colr,k;
	i = xc;j = yc;
	colr = getpixel(i,j);
	while(colr!=bcolor)
	{
		while(colr!=bcolor)
		{
			putpixel(i,j,col);
			i++;
			colr = getpixel(i,j);
		}
		j++;
		i = xc;
		colr = getpixel(i,j);
	}
	i = xc;j = yc;
	colr = getpixel(i,j);
	while(colr!=bcolor)
	{
		while(colr!=bcolor)
		{
			putpixel(i,j,col);
			i--;
			colr = getpixel(i,j);
		}
		j--;
		i = xc;
		colr = getpixel(i,j);
	}
	i = xc;j = yc;
	colr = getpixel(i,j);
	while(colr!=bcolor)
	{
		while(colr!=bcolor)
		{
			putpixel(i,j,col);
			i++;
			colr = getpixel(i,j);
		}
		j--;
		i = xc;
		colr = getpixel(i,j);
	}
	i = xc;j =  yc;
	colr = getpixel(i,j);
	while(colr!=bcolor)
	{
		while(colr!=bcolor)
		{
			putpixel(i,j,col);
			i--;
			colr = getpixel(i,j);
		}
		j++;
		i = xc;
		colr = getpixel(i,j);
	}
}