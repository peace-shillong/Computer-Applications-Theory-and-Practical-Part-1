//Program To Build A House
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void draw_line(float ,float ,float ,float );

void main()
{
	int driver=DETECT,mode;
	int i;
	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");

	outtextxy(285,20,"HOUSE");

	//Middle House Frame
	draw_line(150,150,250,150);
	draw_line(150,150,150,250);
	draw_line(150,250,250,250);
	draw_line(250,150,250,250);
	draw_line(200,100,150,150);
	draw_line(200,100,250,150);
	draw_line(200,100,300,40);
	draw_line(250,150,350,80);
	draw_line(300,40,350,80);
	draw_line(350,80,350,180);
	draw_line(250,250,350,180);

	//RHS House Frame
	draw_line(100,40,500,40);
	draw_line(350,80,480,80);
	draw_line(500,40,480,80);
	draw_line(480,80,480,180);
	draw_line(350,180,480,180);
	draw_line(500,40,515,55);
	draw_line(480,80,515,55);
	draw_line(515,55,515,150);
	draw_line(515,150,480,180);

	//LHS House Frame
	draw_line(80,80,235,80);
	draw_line(100,40,80,80);
	draw_line(80,80,80,180);
	draw_line(80,180,150,180);

	//Border Design
	draw_line(150,160,250,160);
	draw_line(150,240,250,240);
	draw_line(250,160,350,90);
	draw_line(251,240,351,170);
	draw_line(350,90,480,90);
	draw_line(350,170,480,170);
	draw_line(480,90,515,65);
	draw_line(515,140,480,170);
	draw_line(80,90,218,90);
	draw_line(80,170,150,170);

	//Windows Frame
	draw_line(90,100,130,100);
	draw_line(90,120,130,120);
	draw_line(90,140,130,140);
	draw_line(90,100,90,140);
	draw_line(110,100,110,140);
	draw_line(130,100,130,140);

	draw_line(160,100,200,100);
	draw_line(160,120,180,120);
	draw_line(160,100,160,140);
	draw_line(180,100,180,120);

	draw_line(170,155,230,155);
	draw_line(170,165,230,165);
	draw_line(170,155,170,165);
	draw_line(200,155,200,165);
	draw_line(230,155,230,165);

	draw_line(260,165,290,145);
	draw_line(260,182,290,162);
	draw_line(260,200,290,180);
	draw_line(260,165,260,200);
	draw_line(275,155,275,190);
	draw_line(290,145,290,180);

	draw_line(310,133,340,110);
	draw_line(310,151,340,128);
	draw_line(310,170,340,147);
	draw_line(310,133,310,170);
	draw_line(325,122,325,158);
	draw_line(340,110,340,147);

	draw_line(360,100,400,100);
	draw_line(360,120,400,120);
	draw_line(360,140,400,140);
	draw_line(360,100,360,140);
	draw_line(380,100,380,140);
	draw_line(400,100,400,140);

	draw_line(430,100,470,100);
	draw_line(430,120,470,120);
	draw_line(430,140,470,140);
	draw_line(430,100,430,140);
	draw_line(450,100,450,140);
	draw_line(470,100,470,140);

	//Doors House Frame
	draw_line(170,175,230,175);
	draw_line(170,175,170,240);
	draw_line(200,175,200,240);
	draw_line(230,175,230,240);

	draw_line(510,80,510,145);
	draw_line(490,95,490,161);
	draw_line(500,87,500,153);
	draw_line(490,95,510,80);

	//Hook
	draw_line(190,205,210,205);
	draw_line(190,206,210,206);
	draw_line(210,205,210,220);
	draw_line(195,210,195,215);

	//House Design
	draw_line(198,110,203,110);
	draw_line(195,120,205,120);
	draw_line(190,130,210,130);
	draw_line(180,140,220,140);

	//Step And Footpath
	draw_line(170,240,165,248);
	draw_line(230,240,225,248);
	draw_line(165,248,165,260);
	draw_line(225,248,225,258);
	draw_line(165,260,120,405);
	draw_line(225,258,200,370);
    //	draw_line(120,390,150,410);

	//Small Design
   /*	draw_line(410,50,400,70);
	draw_line(410,50,420,70);
	draw_line(400,70,420,70);
	draw_line(410,50,425,45);
	draw_line(425,45,435,60);
	draw_line(435,60,420,70);   */

	//Fencing
	for(i=10;i<80;i=i+5)
	{
		draw_line(i,150-20,i,150+20);
	}
	for(i=520;i<1000;i=i+3)
	{
		draw_line(i,140-10,i,140+10);
	}
	for(i=0;i<155;i=i+5)
	{
		draw_line(5+(i/3),130+i,5+(i/3),270+i);
	}
	for(i=50;i<520;i=i+4)
	{
		draw_line(150+i,290-i/3,150+i,400-i/3);
	}
	for(i=-95;i<-30;i=i+4)
	{
		draw_line(150+i,290-i/3,150+i,400-i/3);
	}

	getch();
	closegraph();
}

void draw_line(float x1,float y1,float x2,float y2)
{
   int x,y;
   if(x1<x2)

	{
		for(x=x1;x<x2;x++)
		{
		     //	delay(200);
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,WHITE);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
		     //	delay(200);
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,WHITE);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
			     //	delay(200);
				putpixel(x,y,WHITE);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
			      //delay(200);
				putpixel(x,y,WHITE);
			}
		}

	}
	if(x1==x2 && y1==y2)
	{
	      x=x1;
	      y=y1;
	      putpixel(x,y,GREEN);

	}
}
