#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void drawline(int x1,int y1,int x2,int y2);
void bfill(int x, int y, int fcolor, int bcolor);
void main()
{
      int gd,gm;
      gd=DETECT;
      clrscr();
      initgraph(&gd,&gm,"c:\\tc\\bgi");
     // drawline(100,30,100,410);
      //drawline(100,410,390,410);


	drawline(350,220,370,220);
      drawline(350,230,370,230);
      drawline(350,220,350,230);
      drawline(370,220,370,230);
      bfill(360,221,1,15);
      outtextxy(380,220,"Assam =31,169,272");

      drawline(350,240,370,240);
      drawline(350,250,370,250);
      drawline(350,240,350,250);
      drawline(370,240,370,250);
      bfill(360,241,2,15);
      outtextxy(380,240,"Tripura = 3,671,032");

      drawline(350,260,370,260);
      drawline(350,270,370,270);
      drawline(350,260,350,270);
      drawline(370,260,370,270);
      bfill(360,261,3,15);
      outtextxy(380,260,"Meghalaya = 2,964,009");

      drawline(350,280,370,280);
      drawline(350,290,370,290);
      drawline(350,280,350,290);
      drawline(370,280,370,290);
      bfill(360,281,4,15);
      outtextxy(380,280,"Manipur = 2,721,756");

      drawline(350,300,370,300);
      drawline(350,310,370,310);
      drawline(350,300,350,310);
      drawline(370,300,370,310);
      bfill(360,301,5,15);
      outtextxy(380,300,"Nagaland = 1,980,602");


      drawline(350,320,370,320);
      drawline(350,330,370,330);
      drawline(350,320,350,330);
      drawline(370,320,370,330);
      bfill(360,321,6,15);
      outtextxy(380,323,"Arunachal Pradesh = 1,382,611");

      drawline(350,340,370,340);
      drawline(350,350,370,350);
      drawline(350,340,350,350);
      drawline(370,340,370,350);
      bfill(360,341,12,15);
      outtextxy(380,343,"Mizoram = 1,071,014");


      drawline(100,25,100,410);
      drawline(100,410,390,410);
      outtextxy(300,150,"Scale:1 Unit=4,000,000 million");

      //drawline(95,390,105,390);
    //  outtextxy(85,390,"4mill");

     // drawline(95,380,105,380);
      //outtextxy(85,380,"6");

     drawline(95,360,105,360);
    outtextxy(85,360,"1");

    // drawline(95,350,105,350);
    // outtextxy(85,350,"1");


    drawline(95,315,105,315);
   outtextxy(85,315,"2");


     //drawline(95,310,105,310);
   // outtextxy(80,310,"2");
     // drawline(95,300,105,300);
     // outtextxy(85,300,"2");
    drawline(95,270,105,270);
     outtextxy(85,270,"3");

 //  drawline(95,270,105,270);
  // outtextxy(80,270,"3");

   // drawline(95,250,105,250);
    // outtextxy(80,250,"3");


    //drawline(95,230,105,230);
     // outtextxy(85,230,"12");

     // drawline(95,220,105,220);
     // outtextxy(80,220,"20");

     // drawline(95,210,105,210);
   //   outtextxy(80,210,"20");

      drawline(95,225,105,225);
      outtextxy(85,225,"4");

   //   drawline(95,190,105,190);
 //     outtextxy(85,190,"24");

    // drawline(95,180,105,180);
   // outtextxy(80,180,"24");

    //  drawline(95,170,105,170);
  //   outtextxy(80,170,"24");

    // drawline(95,160,105,160);
      //outtextxy(55,160,"24");

     drawline(95,180,105,180);
      outtextxy(85,180,"5");

     // drawline(95,140,105,140);
   //  outtextxy(55,140,"28");

    // drawline(95,130,105,130);
     //outtextxy(80,130,"28");

      //drawline(95,120,105,120);
      //outtextxy(80,120,"28");

      //drawline(95,110,105,110);
      //outtextxy(85,110,"28");

   drawline(95,135,105,135);
    outtextxy(85,135,"6");

      //drawline(95,90,105,90);
     // outtextxy(80,90,"64");

     // drawline(95,80,105,80);
     // outtextxy(80,80,"66");

   //  drawline(95,70,105,70);
 //     outtextxy(85,70,"32");

	drawline(95,90,105,90);
    outtextxy(85,90,"7");
	drawline(95,45,105,45);
	outtextxy(85,45,"8");

      drawline(150,380,50,250);
      settextstyle(SMALL_FONT,VERT_DIR,5);
      outtextxy(40,85,"Population(In-Million)");

      settextstyle(SMALL_FONT,HORIZ_DIR,5);
      drawline(145,430,250,430);
      outtextxy(260,420,"States");

      drawline(115,63,115,410);
      drawline(130,63,130,410);
      drawline(115,63,130,63);
      settextstyle(SMALL_FONT,VERT_DIR,4);
   //   outtextxy(100,255,"Assam");
      bfill(120,300,1,WHITE);

      drawline(145,368,145,410);
      drawline(160,368,160,410);
      drawline(145,368,160,368);
      settextstyle(SMALL_FONT,VERT_DIR,4);
     // outtextxy(145,310,"Meghalaya");
      bfill(150,370,2,WHITE);

      drawline(175,375,175,410);
      drawline(190,375,190,410);
      drawline(175,375,190,375);
      settextstyle(SMALL_FONT,VERT_DIR,4);
     // outtextxy(175,330,"Tripura");
      bfill(180,380,3,WHITE);

      drawline(205,378,205,410);
      drawline(220,378,220,410);
      drawline(205,378,220,378);
      settextstyle(SMALL_FONT,VERT_DIR,4);
     // outtextxy(205,325,"Manipur");
      bfill(215,383,4,WHITE);

      drawline(235,385,235,410);
      drawline(250,385,250,410);
      drawline(235,385,250,385);
      settextstyle(SMALL_FONT,VERT_DIR,4);
     // outtextxy(235,325,"Nagaland");
      bfill(245,388,5,WHITE);

      drawline(265,390,265,410);
      drawline(280,390,280,410);
      drawline(265,390,280,390);
      settextstyle(SMALL_FONT,VERT_DIR,4);
     // outtextxy(295,350,"Mizoram");
      bfill(275,395,6,WHITE);

      drawline(295,398,295,410);
      drawline(310,398,310,410);
      drawline(295,398,310,398);
      settextstyle(SMALL_FONT,VERT_DIR,4);
    //  outtextxy(265,280,"Arunachal Pradesh");
      bfill(300,400,12,WHITE);

      settextstyle(SMALL_FONT,HORIZ_DIR,5);
      outtextxy(110,440,"Fig: Bar Diagram Of North_East Population");
      getch();
      closegraph();
}
void drawline(int x1,int y1,int x2,int y2)
{
	int x,y,dx,dy,pk,i,x3,y3,dk;
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
			x = x1;
			y = y1;
			x3 = x2;
		}
		else
		{
			x= x2;
			y= y2;
			x3= x1;
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
	//case when m is +ve and less than 1
	else if(0<m&&m<=1)
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
			y = y2;
			x3 = x1;
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
			x = x2;
			y = y2;
			y3 = y1;
		}
		while(y<y3)
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
void bfill(int x, int y, int fcolor, int bcolor)
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