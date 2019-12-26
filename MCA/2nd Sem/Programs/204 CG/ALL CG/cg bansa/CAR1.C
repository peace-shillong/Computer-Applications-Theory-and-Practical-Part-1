#include<stdio.h>
#include<graphics.h>

void drawcircle(int,int,int,int);
void drawline(int x1,int y1,int x2,int y2,int c);
void fill_car(int,int,int,int);
void trans(int*,int*);


void main()
{
	int driver=DETECT,mode,x[25],y[25],maxx;;
	clrscr();

	initgraph(&driver,&mode,"c:\\tc\\bgi");

	//road
		drawline(10,320,600,320,WHITE);
	//car

	drawline(20,290,20,240,15);
	drawline(20,240,90,240,15);
	drawline(90,240,90,270,15);
	drawline(70,270,110,270,15);
	drawline(110,270,110,290,15);
	drawline(20,290,110,290,15);
	drawline(70,240,70,290,15);
	drawline(75,250,75,260,15);
	drawline(75,250,90,250,15);
	drawline(75,260,90,260,15);

	drawcircle(40,305,5,BROWN);
	drawcircle(40,305,13,BROWN);
	drawcircle(90,305,13,BROWN);
	drawcircle(90,305,5,BROWN);


	x[0]=20;y[0]=290;
	x[1]=20;y[1]=240;
	x[2]=20;y[2]=240;
	x[3]=90;y[3]=240;
	x[4]=90;y[4]=240;
	x[5]=90;y[5]=270;
	x[6]=70;y[6]=270;
	x[7]=110;y[7]=270;
	x[8]=110;y[8]=270;
	x[9]=110;y[9]=290;
	x[10]=20;y[10]=290;
	x[11]=110;y[11]=290;
	x[12]=70;y[12]=240;
	x[13]=70;y[13]=290;
	x[14]=75;y[14]=250;
	x[15]=75;y[15]=260;
	x[16]=75;y[16]=250;
	x[17]=90;y[17]=250;
	x[18]=75;y[18]=260 ;
	x[19]= 90;y[19]=260;
	x[20]=30;y[20]=305;

	x[21]=21;y[21]=241;
	x[22]=80;y[22]=275;

	trans(x,y);
	getch();
	closegraph();
}


void trans(int x[],int y[])
{
	int tx = 1,ty = 0,i;
	for(i = 0;i<400;i++)
	{
		if(kbhit())
		{
			break;
		}

		fill_car(x[21],y[21],6,15);
		fill_car(x[22],y[22],6,15);

		drawline(x[0],y[0],x[1],y[1],BLACK);
		drawline(x[2],y[2],x[3],y[3],BLACK);
		drawline(x[4],y[4],x[5],y[5],BLACK);
		drawline(x[6],y[6],x[7],y[7],BLACK);
		drawline(x[8],y[8],x[9],y[9],BLACK);
		drawline(x[10],y[10],x[11],y[11],BLACK);
		drawline(x[12],y[12],x[13],y[13],BLACK);
		drawline(x[14],y[14],x[15],y[15],BLACK);
		drawline(x[16],y[16],x[17],y[17],BLACK);
		drawline(x[18],y[18],x[19],y[19],BLACK);

	       drawcircle(x[20],y[20],5,BLACK);
	       drawcircle(x[20],y[20],13,BLACK);
	       drawcircle(x[3],y[20],13,BLACK);
	       drawcircle(x[3],y[20],5,BLACK);

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
		x[11] = x[11]+tx;
		y[11] = y[11]+ty;
		x[12] = x[12]+tx;
		y[12] = y[12]+ty;
		x[13] = x[13]+tx;
		y[13] = y[13]+ty;
		x[14] = x[14]+tx;
		y[14] = y[14]+ty;
		x[15] = x[15]+tx;
		y[15] = y[15]+ty;
		x[16] = x[16]+tx;
		y[16] = y[16]+ty;
		x[17] = x[17]+tx;
		y[17] = y[17]+ty;
		x[18] = x[18]+tx;
		y[18] = y[18]+ty;
		x[19] = x[19]+tx;
		y[19] = y[19]+ty;
		x[20] = x[20]+tx;
		y[20] = y[20]+ty;


		x[21] = x[21]+tx;
		y[21] = y[21]+ty;
		x[22] = x[22]+tx;
		y[22] = y[22]+ty;


		drawline(x[0],y[0],x[1],y[1],15);
		drawline(x[2],y[2],x[3],y[3],15);
		drawline(x[4],y[4],x[5],y[5],15);
		drawline(x[6],y[6],x[7],y[7],15);
		drawline(x[8],y[8],x[9],y[9],15);
		drawline(x[10],y[10],x[11],y[11],15);
		drawline(x[12],y[12],x[13],y[13],15);
		drawline(x[14],y[14],x[15],y[15],15);
		drawline(x[16],y[16],x[17],y[17],15);
		drawline(x[18],y[18],x[19],y[19],15);
	       drawcircle(x[20],y[20],5,WHITE);
	       drawcircle(x[20],y[20],13,15);
	       drawcircle(x[3],y[20],13,15);
	       drawcircle(x[3],y[20],5,15);
		fill_car(x[21],y[21],6,15);
		fill_car(x[22],y[22],6,15);
	       delay(30);
	}
}

void drawline(int x1,int y1,int x2,int y2,int c)
{
	int x,y,dx,dy,pk,i,x3,y3,dk;
	float m=0;
	dx = x2-x1; dy = y2-y1;
	x = x1;y = y1;
	if(dx!=0)
	{
		m = (float)dy/(float)dx;
	}
	//case when slope is 0
	if(m==0)
	{
		if(x1==x2)
		{
			if(y1<y2)
			{
				for(i=y1;i<=y2;i++)
				{
					putpixel(x,y,c);
					y = y+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,c);
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
					putpixel(x,y,c);
					x= x+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=x2;i<=x1;i++)
				{
					putpixel(x,y,c);
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
			x = x1;y = y1;x3 = x2;
		}
		else
		{
			x = x2;y= y2;x3=x1;
		}
		while(x<x3)
		{
			putpixel(x,y,c);
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
			x = x1;y = y1,x3 = x2;
		}
		else
		{
			x = x2;y= y2;x3 = x1;
		}
		while(x<x3)
		{
			putpixel(x,y,c);
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
			x= x1;y = y1;y3 = y2;
		}
		else
		{
			x = x2;y = y2;y3 = y1;
		}
		while(y<y3)
		{
			putpixel(x,y,c);
			if(pk<0)
			{
				pk = pk+(2*dx);
				x = x;
			}
			else
			{
				pk = pk+(2*(dx-dy));
				x = x+1;
			}
			y = y+1;
		}
	}
	//case when slop is >1 and -ve
	else if(m<-1)
	{

		dk = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		if(y1<y2)
		{
			x= x1;y = y1;y3 = y2;
		}
		else
		{
			x = x2;y = y2;y3 = y1;
		}
		while(y<y3)
		{
			putpixel(x,y,c);
			if(dk<0)
			{
				dk = dk-(dy*x1);
				x = x-1;
			}
			else
			{
				dk = dk-(dy*x1)-(3*dx*dy);
				x = x;
			}
			y = y+1;
		}
	}

}

void drawcircle(int xc,int yc,int r,int col)
{
	int x,y,pk;
	x=0;
	y=r;
	pk=1-r;
	while(x<y)
	{

		if(pk<0)
		{
			pk=pk+2*x+3;
			x=x+1;
			y=y;

		}
		else
		{
			pk=pk+2*x-2*y+5;
			x=x+1;
			y=y-1;

		}
		putpixel(xc+x,yc+y,col);
		putpixel(xc+y,yc+x,col);
		putpixel(xc+y,yc-x,col);
		putpixel(xc+x,yc-y,col);
		putpixel(xc-x,yc-y,col);
		putpixel(xc-y,yc-x,col);
		putpixel(xc-y,yc+x,col);
		putpixel(xc-x,yc+y,col);
	}
	 putpixel(xc-r,yc,col);
	 putpixel(xc+r,yc,col);
	 putpixel(xc,yc-r,col);
	 putpixel(xc,yc+r,col);
}


void fill_car(int x, int y, int fcolor, int bcolor)
{
	int a,b,c;
	int x1, y1;
	x1=x;
	y1=y;
	a=getpixel(x,y);
	b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x++;
			c=getpixel(x,y);
		}
		y++;
		x=x1;
		b=getpixel(x,y);
		c=getpixel(x,y);
	}
	x=x1;
	y=y1;
	b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x--;
			c=getpixel(x,y);
		}
	y++;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}

	x=x1;
	y=y1;
	b=c=a;
	while(b!=bcolor)
	{

		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x--;
			c=getpixel(x,y);
		}
	y--;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}
		x=x1;
		y=y1;
		b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x++;
			c=getpixel(x,y);
		}
	y--;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}
}