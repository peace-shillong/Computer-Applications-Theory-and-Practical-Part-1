//VEHICLE
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
void drawline(int,int,int,int,int);
void drawcircle(int,int,int,int);
void color(int,int,int,int);
void translate(int*,int*);
void main()
{
	int driver,mode,x[55],y[55];
	clrscr();
	driver = DETECT;
	initgraph(&driver,&mode,"c:\\tc\\bgi");

	//LOAD
	drawline(20,50,150,50,WHITE);//50,50 100,50
	drawline(20,50,20,90,WHITE); //50,75
	drawline(150,50,150,90,WHITE); //100,75
	drawline(20,90,150,90,WHITE);//25,100 125,100
	color(80,70,2,WHITE);

	//BODY
	drawline(17,90,150,90,WHITE);  //125,75
	drawline(17,90,17,120,WHITE);
	drawline(150,90,150,120,WHITE);
	drawline(17,120,30,120,WHITE);
	drawline(30,120,40,110,WHITE);
	drawline(40,110,60,110,WHITE);
	drawline(60,110,70,120,WHITE);
	drawline(70,120,160,120,WHITE);
	drawline(160,120,170,110,WHITE);
	drawline(170,110,190,110,WHITE);
	drawline(190,110,200,120,WHITE);
	drawline(200,120,215,120,WHITE);
	drawline(215,120,215,95,WHITE);
	drawline(185,95,215,95,WHITE);
	drawline(180,90,185,95,WHITE);

	//HOOD
	drawline(150,60,150,88,WHITE);
	drawline(150,60,180,60,WHITE);
	drawline(180,60,180,88,WHITE);
	drawline(150,88,180,88,WHITE);
	color(170,70,8,WHITE);

	//TYRES
	drawcircle(50,125,10,WHITE);    //50,110
	drawcircle(180,125,10,WHITE);   //100,110
	drawline(0,136,550,136,WHITE);
	color(50,125,7,WHITE);
	color(180,125,7,WHITE);

	x[0] = 20;   x[1] = 150;  x[2] = 20;   x[3] = 20;   x[4] = 150;
	x[5] = 150;  x[6] = 20;   x[7] = 150;  x[8] = 17;   x[9] = 150;
	x[10] = 17;  x[11] = 17;  x[12] = 150; x[13] = 150; x[14] = 17;
	x[15] = 30;  x[16] = 30;  x[17] = 40;  x[18] = 40;  x[19] = 60;
	x[20] = 60;  x[21] = 70;  x[22] = 70;  x[23] = 160; x[24] = 160;
	x[25] = 170; x[26] = 170; x[27] = 190; x[28] = 190; x[29] = 200;
	x[30] = 200; x[31] = 215; x[32] = 215; x[33] = 215; x[34] = 185;
	x[35] = 215; x[36] = 180; x[37] = 185; x[38] = 150; x[39] = 150;
	x[40] = 150; x[41] = 180; x[42] = 180; x[43] = 180; x[44] = 150;
	x[45] = 180; x[46] = 0;   x[47] = 550;

	//CIRCLE
	x[48] = 50;  x[49] = 180; x[50] = 170; x[51] = 80;

	y[0] = 50;   y[1] = 50;   y[2] = 50;   y[3] = 90;   y[4] = 50;
	y[5] = 90;   y[6] = 90;   y[7] = 90;   y[8] = 90;   y[9] = 90;
	y[10] =90;   y[11] = 120; y[12] = 90;  y[13] = 120; y[14] = 120;
	y[15] = 120; y[16] = 120; y[17] = 110; y[18] = 110; y[19] = 110;
	y[20] = 110; y[21] = 120; y[22] = 120; y[23] = 120; y[24] = 120;
	y[25] = 110; y[26] = 110; y[27] = 110; y[28] = 110; y[29] = 120;
	y[30] = 120; y[31] = 120; y[32] = 120; y[33] = 95;  y[34] = 95;
	y[35] = 95;  y[36] = 90;  y[37] = 95;  y[38] = 60;  y[39] = 88;
	y[40] = 60;  y[41] = 60;  y[42] = 60;  y[43] = 88;  y[44] = 88;
	y[45] = 88;  y[46] = 136; y[47] = 136;

	//CIRCLE
	y[48] = 125; y[49] = 125; y[50] = 70;  y[51] = 70;

	translate(x,y);
	getch();
	closegraph();
}
void translate(int x[],int y[])
{
	int tx = 1,i;
	for(i = 0;i<500;i++)
	{
		if(kbhit())
		{
			break;
		}
		color(x[50],y[50],8,WHITE);
		color(x[51],y[51],2,WHITE);
		color(x[48],y[48],7,WHITE);
		color(x[49],y[49],7,WHITE);
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
		drawline(x[20],y[20],x[21],y[21],BLACK);
		drawline(x[22],y[22],x[23],y[23],BLACK);
		drawline(x[24],y[24],x[25],y[25],BLACK);
		drawline(x[26],y[26],x[27],y[27],BLACK);
		drawline(x[28],y[28],x[29],y[29],BLACK);
		drawline(x[30],y[30],x[31],y[31],BLACK);
		drawline(x[32],y[32],x[33],y[33],BLACK);
		drawline(x[34],y[34],x[35],y[35],BLACK);
		drawline(x[36],y[36],x[37],y[37],BLACK);
		drawline(x[38],y[38],x[39],y[39],BLACK);
		drawline(x[40],y[40],x[41],y[41],BLACK);
		drawline(x[42],y[42],x[43],y[43],BLACK);
		drawline(x[44],y[44],x[45],y[45],BLACK);
	  //	drawline(x[46],y[46],x[47],y[47],BLACK);


		drawcircle(x[48],y[48],10,BLACK);
		drawcircle(x[49],y[49],10,BLACK);

		x[0] = x[0]+tx;    x[1] = x[1]+tx;
		x[2] = x[2]+tx;    x[3] = x[3]+tx;
		x[4] = x[4]+tx;    x[5] = x[5]+tx;
		x[6] = x[6]+tx;    x[7] = x[7]+tx;
		x[8] = x[8]+tx;    x[9] = x[9]+tx;
		x[10] = x[10]+tx;  x[11] = x[11]+tx;
		x[12] = x[12]+tx;  x[13] = x[13]+tx;
		x[14] = x[14]+tx;  x[15] = x[15]+tx;
		x[16] = x[16]+tx;  x[17] = x[17]+tx;
		x[18] = x[18]+tx;  x[19] = x[19]+tx;
		x[20] = x[20]+tx;  x[21] = x[21]+tx;
		x[22] = x[22]+tx;  x[23] = x[23]+tx;
		x[24] = x[24]+tx;  x[25] = x[25]+tx;
		x[26] = x[26]+tx;  x[27] = x[27]+tx;
		x[28] = x[28]+tx;  x[29] = x[29]+tx;
		x[30] = x[30]+tx;  x[31] = x[31]+tx;
		x[32] = x[32]+tx;  x[33] = x[33]+tx;
		x[34] = x[34]+tx;  x[35] = x[35]+tx;
		x[36] = x[36]+tx;  x[37] = x[37]+tx;
		x[38] = x[38]+tx;  x[39] = x[39]+tx;
		x[40] = x[40]+tx;  x[41] = x[41]+tx;
		x[42] = x[42]+tx;  x[43] = x[43]+tx;
		x[44] = x[44]+tx;  x[45] = x[45]+tx;
		x[48] = x[48]+tx;  x[49] = x[49]+tx;
		x[50] = x[50]+tx;  x[51] = x[51]+tx;

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
		drawline(x[20],y[20],x[21],y[21],15);
		drawline(x[22],y[22],x[23],y[23],15);
		drawline(x[24],y[24],x[25],y[25],15);
		drawline(x[26],y[26],x[27],y[27],15);
		drawline(x[28],y[28],x[29],y[29],15);
		drawline(x[30],y[30],x[31],y[31],15);
		drawline(x[32],y[32],x[33],y[33],15);
		drawline(x[34],y[34],x[35],y[35],15);
		drawline(x[36],y[36],x[37],y[37],15);
		drawline(x[38],y[38],x[39],y[39],15);
		drawline(x[40],y[40],x[41],y[41],15);
		drawline(x[42],y[42],x[43],y[43],15);
		drawline(x[44],y[44],x[45],y[45],15);

		drawcircle(x[48],y[48],10,WHITE);
		drawcircle(x[49],y[49],10,WHITE);


		delay(1);
		if(i==350)
		{
			sound(250);
			delay(10000);
			nosound();
		}

		//write equation for x//write equation for y
		//redraw the lines with white color with new x,y
		//do for all points here only
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
					y=y+1;
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
					x=x+1;
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