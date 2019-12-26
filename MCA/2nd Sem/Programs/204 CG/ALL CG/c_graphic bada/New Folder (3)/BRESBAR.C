#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void drawline(int x1,int y1,int x2,int y2);
void boundaryfill(int,int,int);
void main()
{
      int gd,gm;
      gd=DETECT;
      clrscr();
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      drawline(100,50,100,410);
      drawline(100,410,390,410);
      outtextxy(410,80,"Scale-:");
      outtextxy(430,100,"1 Unit= 10,00,000");

      drawline(410,180,425,180);
      drawline(410,180,410,195);
      drawline(410,195,425,195);
      drawline(425,180,425,195);
      boundaryfill(411,194,1);
      outtextxy(430,185,"= Assam(3,11,69,272)");

      drawline(410,210,425,210);
      drawline(410,210,410,225);
      drawline(410,225,425,225);
      drawline(425,210,425,225);
      boundaryfill(411,224,2);
      outtextxy(430,215,"= Tripura(39,71,032)");

      drawline(410,240,425,240);
      drawline(410,240,410,255);
      drawline(410,255,425,255);
      drawline(425,240,425,255);
      boundaryfill(411,254,3);
      outtextxy(430,245,"= Meghalaya(29,64,008)");

      drawline(410,270,425,270);
      drawline(410,270,410,285);
      drawline(410,285,425,285);
      drawline(425,270,425,285);
      boundaryfill(411,284,4);
      outtextxy(430,275,"= Manipur(27,21,756)");

      drawline(410,300,425,300);
      drawline(410,300,410,315);
      drawline(410,315,425,315);
      drawline(425,300,425,315);
      boundaryfill(411,314,5);
      outtextxy(430,305,"= Nagaland(19,64,80,602)");

      drawline(410,330,425,330);
      drawline(410,330,410,345);
      drawline(410,345,425,345);
      drawline(425,330,425,345);
      boundaryfill(411,344,6);
      outtextxy(430,335,"=Arunachal Pradesh(13,82,611)");

      drawline(410,360,425,360);
      drawline(410,360,410,375);
      drawline(410,375,425,375);
      drawline(425,360,425,375);
      boundaryfill(411,374,12);
      outtextxy(430,365,"= Mizoram(10,91,014)");

      drawline(95,400,105,400);
      outtextxy(85,400,"1");//10,00,000

      drawline(95,390,105,390);
      outtextxy(85,390,"2");//20,00,000

      drawline(95,380,105,380);
      outtextxy(85,380,"3"); //30,00,000

      drawline(95,370,105,370);
      outtextxy(85,370,"4");//40,00,000

      drawline(95,360,105,360);
      outtextxy(80,360,"5");//50,00,000

      drawline(95,350,105,350);
      outtextxy(80,350,"6");//60,00,000

      drawline(95,340,105,340);
      outtextxy(80,340,"7");//70,00,000

      drawline(95,330,105,330);
      outtextxy(80,330,"8");//80,00,000

      drawline(95,320,105,320);
      outtextxy(80,320,"9");//90,00,000

      drawline(95,310,105,310);
      outtextxy(80,310,"10");//1,00,00,000

      drawline(95,300,105,300);
      outtextxy(80,300,"11");//1,10,00,000

      drawline(95,290,105,290);
      outtextxy(80,290,"12");

      drawline(95,280,105,280);
      outtextxy(80,280,"13");

      drawline(95,270,105,270);
      outtextxy(80,270,"14");

      drawline(95,260,105,260);
      outtextxy(80,260,"15");

      drawline(95,250,105,250);
      outtextxy(80,250,"16");

      drawline(95,240,105,240);
      outtextxy(80,240,"17");

      drawline(95,230,105,230);
      outtextxy(80,230,"18");

      drawline(95,220,105,220);
      outtextxy(80,220,"19");

      drawline(95,210,105,210);
      outtextxy(80,210,"20");

      drawline(95,200,105,200);
      outtextxy(80,200,"21");

      drawline(95,190,105,190);
      outtextxy(80,190,"22");

      drawline(95,180,105,180);
      outtextxy(80,180,"23");

      drawline(95,170,105,170);
      outtextxy(80,170,"24");

      drawline(95,160,105,160);
      outtextxy(80,160,"25");

      drawline(95,150,105,150);
      outtextxy(80,150,"26");

      drawline(95,140,105,140);
      outtextxy(80,140,"27");

      drawline(95,130,105,130);
      outtextxy(80,130,"28");

      drawline(95,120,105,120);
      outtextxy(80,120,"29");

      drawline(95,110,105,110);
      outtextxy(80,110,"30");

      drawline(95,100,105,100);
      outtextxy(80,100,"31");

      drawline(95,90,105,90);
      outtextxy(80,90,"32");

      /*drawline(95,80,105,80);
      outtextxy(80,80,"33");

      drawline(95,70,105,70);
      outtextxy(80,70,"34");

      drawline(95,60,105,60);
      outtextxy(80,60,"35");*/

      drawline(48,380,48,240);
      settextstyle(SMALL_FONT,VERT_DIR,5);
      outtextxy(40,100,">  % 0f population");

      settextstyle(SMALL_FONT,HORIZ_DIR,5);
      drawline(145,429,255,429);
      outtextxy(260,420,"> States");

      //settextstyle(SMALL_FONT,VERT_DIR,4);
      //outtextxy(118,250,"Assam=69.30 %");
      drawline(115,97,115,410); //assam
      drawline(130,97,130,410);
      drawline(115,97,130,97);
      boundaryfill(116,409,1);

      //settextstyle(SMALL_FONT,VERT_DIR,4);
      //outtextxy(145,270,"Tripura=08.16 %");
      drawline(145,375,145,410); //tripura
      drawline(160,375,160,410);
      drawline(145,375,160,375);
      boundaryfill(146,409,2);

      //settextstyle(SMALL_FONT,VERT_DIR,4);
      //outtextxy(175,275,"Meghalaya=06.59 %");
      drawline(175,383,175,410);//Meghalaya
      drawline(190,383,190,410);
      drawline(175,383,190,383);
      boundaryfill(176,409,3);


      drawline(205,386,205,410);//Manipur
      drawline(220,386,220,410);
      drawline(205,386,220,386);
      //settextstyle(SMALL_FONT,VERT_DIR,4);
      //outtextxy(205,285,"Manipur=06.05 %");
      boundaryfill(206,409,4);

      drawline(235,393,235,410); //Naga
      drawline(250,393,250,410);
      drawline(235,393,250,393);
      //settextstyle(SMALL_FONT,VERT_DIR,4);
      //outtextxy(235,290,"Nagaland=04.40 %");
      boundaryfill(236,409,5);

      drawline(265,396,265,410); //AP
      drawline(280,396,280,410);
      drawline(265,396,280,396);
      //settextstyle(SMALL_FONT,VERT_DIR,4);
      //outtextxy(265,240,"Arunachal Pradesh=03.07 %");
      boundaryfill(266,409,6);

      drawline(295,399,295,410); //Mizo
      drawline(310,399,310,410);
      drawline(295,399,310,399);
      //settextstyle(SMALL_FONT,VERT_DIR,4);
      //outtextxy(295,305,"Mizoram=02.43 %");
      boundaryfill(296,409,12);

      settextstyle(SMALL_FONT,HORIZ_DIR,5);
      outtextxy(110,440,"Fig: Bar Diagram Of North_East Population");
      drawline(110,460,420,460);
      getch();
      closegraph();
}
void boundaryfill(int x,int y,int fcolor)
{
	int color,x1=x;
	color=getpixel(x,y);
	while(color!=WHITE)
	{
		while(color!=WHITE)
		{
			putpixel(x,y,fcolor);
			x+=1;
			color=getpixel(x,y);
			if(color==WHITE)
			{
				break;
			}
		}
		x=x1;
		y=y-1;
		color=getpixel(x,y);
	}
}
void drawline(int x1,int y1,int x2,int y2)
{
	int d1,d2,x,y,dx,dy,pk,i,x3,y3;
	float m=0;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	x=x1;
	y=y1;
	if(dx!=0)
	{
		m=(float)dy/(float)dx;
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
				x=x2;
				y=y2;
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
				x=x2;
				y=y2;
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
			x=x1;
			y=y1;
			x3=x2;
			y3=y2;
		}
		else
		{
			x=x2;
			y=y2;
			x3=x1;
			y3=y1;
		}
		while(x<x3)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk=pk+(2*dy);
				if(y>y3)
					y=y-1;
				else
					y=y+1;
			}
			else
			{
				pk = pk+(2*(dy-dx));
			}
			x=x+1;
		}
	}
	//case when m is +ve and less than 1
	else if(0<m && m<=1)
	{
		pk=(2*dy)-dx;
		if(x1<x2)
		{
			x=x1;
			y=y1;
			x3=x2;
			y3=y2;
		}
		else
		{
			x=x2;
			y=y2;
			x3=x1;
			y3=y1;
		}
		while(x<x3)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk=pk+(2*dy);
			}
			else
			{
				pk=pk+(2*(dy-dx));
				if(y<y3)
					y=y+1;
				else
					y=y-1;
			}
			x=x+1;
		}
	}
	//case when slop is >1 and +ve
	else if(m>1)
	{
		pk = (2*dy)-dx;
		if(y1<y2)
		{
			x=x1;
			y=y1;
			y3=y2;
			x3=x2;
		}
		else
		{
			x=x2;
			y=y2;
			y3=y1;
			x3=x1;
		}
		while(y<y3)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk=pk+(2*dx);
				x=x;
			}
			else
			{
				pk = pk+(2*(dx-dy));
				if(x<x3)
					x=x+1;
				else
					x=x-1;
			}
			y=y+1;
		}
	}
	//case when slop is >1 and -ve
	else if(m<-1)
	{

		pk = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		if(y1<y2)
		{
			x=x1;
			y=y1;
			y3=y2;
			x3=x2;
		}
		else
		{
			x=x2;
			y=y2;
			y3=y1;
			x3=x1;
		}
		while(y<y3)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk=pk-(dy*x1);
				if(x>x3)
					x=x-1;
				else
					x=x+1;
			}
			else
			{
				pk=pk-(dy*x1)-(3*dx*dy);
				x=x;
			}
			y=y+1;
		}
	}

}