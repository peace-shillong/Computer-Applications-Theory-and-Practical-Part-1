#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void drawline(int x1,int y1,int x2,int y2);
void main()
{
      int gd=DETECT,gm;
      clrscr();
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      drawline(100,50,100,410);
      drawline(100,410,390,410);
      outtextxy(380,100,"Scale-:");
      outtextxy(400,110,"1 Unit= 5%");

      drawline(100,385,105,385);
      outtextxy(85,385,"5");

      drawline(95,360,105,360);
      outtextxy(80,360,"10");

      drawline(95,335,105,335);
      outtextxy(80,335,"15");

      drawline(95,310,105,310);
      outtextxy(80,310,"20");

      drawline(95,285,105,285);
      outtextxy(80,285,"25");

      drawline(95,260,105,260);
      outtextxy(80,260,"30");

      drawline(95,235,105,235);
      outtextxy(80,235,"35");

      drawline(95,210,105,210);
      outtextxy(80,210,"40");

      drawline(95,185,105,185);
      outtextxy(80,185,"45");

      drawline(95,160,105,160);
      outtextxy(80,160,"50");

      drawline(95,135,105,135);
      outtextxy(80,135,"55");

      drawline(95,110,105,110);
      outtextxy(80,110,"60");

      drawline(95,85,105,85);
      outtextxy(80,85,"65");

      drawline(95,60,105,60);
      outtextxy(80,60,"70");

      settextstyle(SMALL_FONT,VERT_DIR,5);
      outtextxy(40,150,"% 0F POPULATION");

      settextstyle(SMALL_FONT,HORIZ_DIR,5);
      outtextxy(260,420,"States");

      drawline(115,63,115,410); //assam
      drawline(145,63,145,410);
      drawline(115,63,145,63);
      settextstyle(SMALL_FONT,VERT_DIR,4);
      outtextxy(118,250,"Assam=69.30 %");

      drawline(145,368,145,410); //tripura
      drawline(175,368,175,410);
      drawline(145,368,175,368);
      settextstyle(SMALL_FONT,VERT_DIR,4);
      outtextxy(145,270,"Tripura=08.16 %");

      drawline(175,375,175,410);//Meghalaya
      drawline(205,375,205,410);
      drawline(175,375,205,375);
      settextstyle(SMALL_FONT,VERT_DIR,4);
      outtextxy(175,275,"Meghalaya=06.59 %");

      drawline(205,378,205,410);//Manipur
      drawline(235,378,235,410);
      drawline(205,378,235,378);
      settextstyle(SMALL_FONT,VERT_DIR,4);
      outtextxy(205,285,"Manipur=06.05 %");

      drawline(235,385,235,410); //Naga
      drawline(265,385,265,410);
      drawline(235,385,265,385);
      settextstyle(SMALL_FONT,VERT_DIR,4);
      outtextxy(235,290,"Nagaland=04.40 %");

      drawline(265,390,265,410); //AP
      drawline(295,390,295,410);
      drawline(265,390,295,390);
      settextstyle(SMALL_FONT,VERT_DIR,4);
      outtextxy(265,240,"Arunachal Pradesh=03.07 %");

      drawline(295,398,295,410); //Mizo
      drawline(325,398,325,410);
      drawline(295,398,325,398);
      settextstyle(SMALL_FONT,VERT_DIR,4);
      outtextxy(295,305,"Mizoram=02.43 %");

      settextstyle(SMALL_FONT,HORIZ_DIR,5);
      outtextxy(200,440,    "North_East Population");
      //drawline(110,460,420,460);
      getch();
      closegraph();
}
void drawline(int x1,int y1,int x2,int y2)
{
	int x,y,dx,dy,pk,i,x3,y3,dk;
	float m=0.0;
	dx = x2-x1; dy = y2-y1;
	x = x1;y = y1;
	if(dx!=0)
	{
		m =dy/dx;
	}

	if(m==0)
	{
		if(x1==x2)
		{
			if(y1<y2)
			{
				for(i=y1;i<=y2;i++)
				{
					putpixel(x,y,GREEN);
					y = y+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,RED);
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
					putpixel(x,y,RED);
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
	else if(-1<=m && m<0)
	{
		pk = (2*dy)-dx;
		if(x1<x2)
		{
			x = x1;
			y = y1;
			x3 = x2;
		}
		else
		{
			x = x2;
			y= y2;
			x3=x1;
		}
		while(x<x3)
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
	else if((m>0)&&(m<=1))
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
	else if(m>1)
	{
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
			putpixel(x,y,WHITE);
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
	else if(m<-1)
	{

		dk = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		if(y1<y2)
		{
			x= x1;
			y = y1;
			y3 = y2;
		}
		else
		{
			x = x2;
			y = y2;
			y3 = y1;
		}
		while(y<y3)
		{
			putpixel(x,y,WHITE);
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
