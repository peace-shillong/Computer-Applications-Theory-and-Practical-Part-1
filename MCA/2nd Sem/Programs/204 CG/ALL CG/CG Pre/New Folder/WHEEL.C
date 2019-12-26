#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
void drawline(int,int,int,int,int);
void drawcircle(int,int,int,int);
void color(int,int,int,int);
void translate(int*,int*);
void main()
{
	int driver,mode,x[11],y[11];
	clrscr();
	driver = DETECT;

	initgraph(&driver,&mode,"C:\\tc\\bgi");
	//X
	drawline(30,20,30,80,15);
	drawline(0,50,60,50,15);
	drawline(8,30,53,70,15);
	drawline(53,30,8,70,15);


	x[0] = 30;
	x[1] = 30;
	x[2] = 30;
	x[3] = 0;
	x[4] = 60;
	x[5] = 8;
	x[6] = 53;
	x[7] = 53;
	x[8] = 8;

	y[0] = 50;
	y[1] = 20;
	y[2] = 80;
	y[3] = 50;
	y[4] = 50;
	y[5] = 30;
	y[6] = 70;
	y[7] = 30;
	y[8] = 70;

	translate(x,y);

	translate(x,y);

	//Y
	drawline(500,20,500,80,15);
	drawline(470,50,530,50,15);
	drawline(478,30,523,70,15);
	drawline(523,30,478,70,15);

	x[0] = 500;
	x[1] = 500;
	x[2] = 500;
	x[3] = 470;
	x[4] = 530;
	x[5] = 478;
	x[6] = 523;
	x[7] = 523;
	x[8] = 478;

	y[0] = 50;
	y[1] = 20;
	y[2] = 80;
	y[3] = 50;
	y[4] = 50;
	y[5] = 30;
	y[6] = 70;
	y[7] = 30;
	y[8] = 70;



	translate(x,y);
	translate(x,y);

	getch();
	closegraph();
}
void translate(int x[],int y[])
{
	int tx=1,ty=1,i,j;

	for(i = 0;i<500;i++)
	{
		if(kbhit())
		{
			break;
		}
		else
		{
		drawcircle(x[0],y[0],30,BLACK);
		drawline(x[1],y[1],x[2],y[2],BLACK);
		drawline(x[3],y[3],x[4],y[4],BLACK);
		drawline(x[5],y[5],x[6],y[6],BLACK);
		drawline(x[7],y[7],x[8],y[8],BLACK);

		x[0]=x[0]+tx;
		x[1]=x[1]+tx;
		x[2]=x[2]+tx;
		x[3]=x[3]+tx;
		x[4]=x[4]+tx;
		x[5]=x[5]+tx;
		x[6]=x[6]+tx;
		x[7]=x[7]+tx;
		x[8]=x[8]+tx;

		drawcircle(x[0],y[0],30,WHITE);
		drawline(x[1],y[1],x[2],y[2],WHITE);
		drawline(x[3],y[3],x[4],y[4],WHITE);
		drawline(x[5],y[5],x[6],y[6],WHITE);
		drawline(x[7],y[7],x[8],y[8],WHITE);

		delay(5);
	       }
	}

	for(j = 0;j<400;j++)
	{
		if(kbhit())
		{
			break;
		}
		else
		{
		drawcircle(x[450],y[450],30,BLACK);
		drawline(x[1],y[1],x[2],y[2],BLACK);
		drawline(x[3],y[3],x[4],y[4],BLACK);
		drawline(x[5],y[5],x[6],y[6],BLACK);
		drawline(x[7],y[7],x[8],y[8],BLACK);


		y[0]=y[0]+ty;
		y[1]=y[1]+ty;
		y[2]=y[2]+ty;
		y[3]=y[3]+ty;
		y[4]=y[4]+ty;
		y[5]=y[5]+ty;
		y[6]=y[6]+ty;
		y[7]=y[7]+ty;
		y[8]=y[8]+ty;

		drawcircle(x[0],y[0],30,WHITE);
		drawline(x[1],y[1],x[2],y[2],WHITE);
		drawline(x[3],y[3],x[4],y[4],WHITE);
		drawline(x[5],y[5],x[6],y[6],WHITE);
		drawline(x[7],y[7],x[8],y[8],WHITE);


		delay(5);
		drawcircle(x[0],y[0],30,BLACK);
		}
	}
	for(i = 500;i<=1;i--)
	{
		if(kbhit())
		{
			break;
		}
		drawcircle(x[0],y[0],30,BLACK);
		drawline(x[1],y[1],x[2],y[2],BLACK);
		drawline(x[3],y[3],x[4],y[4],BLACK);
		drawline(x[5],y[5],x[6],y[6],BLACK);
		drawline(x[7],y[7],x[8],y[8],BLACK);

		x[0]=x[0]-tx;
		x[1]=x[1]-tx;
		x[2]=x[2]-tx;
		x[3]=x[3]-tx;
		x[4]=x[4]-tx;
		x[5]=x[5]-tx;
		x[6]=x[6]-tx;
		x[7]=x[7]-tx;
		x[8]=x[8]-tx;

		drawcircle(x[0],y[0],30,WHITE);
		drawline(x[1],y[1],x[2],y[2],WHITE);
		drawline(x[3],y[3],x[4],y[4],WHITE);
		drawline(x[5],y[5],x[6],y[6],WHITE);
		drawline(x[7],y[7],x[8],y[8],WHITE);

		delay(5);

	}

	for(j = 400;j<=1;j--)
	{
		if(kbhit())
		{
			break;
		}
		drawcircle(x[450],y[450],30,BLACK);
		drawline(x[1],y[1],x[2],y[2],BLACK);
		drawline(x[3],y[3],x[4],y[4],BLACK);
		drawline(x[5],y[5],x[6],y[6],BLACK);
		drawline(x[7],y[7],x[8],y[8],BLACK);


		y[0]=y[0]-ty;
		y[1]=y[1]-ty;
		y[2]=y[2]-ty;
		y[3]=y[3]-ty;
		y[4]=y[4]-ty;
		y[5]=y[5]-ty;
		y[6]=y[6]-ty;
		y[7]=y[7]-ty;
		y[8]=y[8]-ty;

		drawcircle(x[0],y[0],30,WHITE);
		drawline(x[1],y[1],x[2],y[2],WHITE);
		drawline(x[3],y[3],x[4],y[4],WHITE);
		drawline(x[5],y[5],x[6],y[6],WHITE);
		drawline(x[7],y[7],x[8],y[8],WHITE);


		delay(5);
		drawcircle(x[0],y[0],30,BLACK);
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
void drawline(int x1,int y1,int x2,int y2,int cl)
{
   int x,y;
   if(x1<x2)

	{
		for(x=x1;x<x2;x++)
		{
		       //delay(10);
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,cl);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,cl);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,cl);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,cl);
			}
		}

	}
	if(x1==x2 && y1==y2)
	{
	      x=x1;
	      y=y1;
	      putpixel(x,y,cl);

	}
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
