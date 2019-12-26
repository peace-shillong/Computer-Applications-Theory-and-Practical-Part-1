#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
union REGS in,out;
void drawline(int x1,int y1,int x2,int y2);
void main()
{
      int gd,gm,x1,y1,x2,y2,x,button,xco,yco,xin,yin;
      int xout,yout,i=0,j=0,colr;
      gd=DETECT;
      clrscr();
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      //box
      /*drawline(70,70,500,70);
      drawline(70,70,70,400);
      drawline(70,400,500,400);
      drawline(500,400,500,70);*/
      //body
      drawline(200,200,350,200);
      drawline(200,200,200,350);
      drawline(200,350,350,350);
      drawline(350,200,350,350);
      //roof
      drawline(277,130,200,200);
      drawline(277,130,350,200);
      //window
      drawline(290,230,330,230);
      drawline(290,230,290,270);
      drawline(290,270,330,270);
      drawline(330,230,330,270);
      drawline(310,230,310,270);
      drawline(290,250,330,250);
      //door
      drawline(225,260,225,350);
      drawline(260,260,260,350);
      drawline(225,260,260,260);
      drawline(225,260,250,270);
      drawline(250,270,250,350);
      restrictmsptr(5,5,(getmaxx()-5),(getmaxy()-5));
      showmousept();
      //mouse button press
      while(1)
      {
		in.x.ax=3;
		int86(0x33,&in,&out);
		xco=out.x.cx;
		yco=out.x.dx;
		button=out.x.bx;
		if(button==1)
		{
			xin=xco;
			yin=yco;
			while(1)
			{
				in.x.ax=3;
				int86(0x33,&in,&out);
				xco=out.x.cx;
				yco=out.x.dx;
				button=out.x.bx;
				if(button==0)
				{
					xout=xco;
					yout=yco;
					break;
				}
			}
			break;
		}
	}
	drawline(xin,yin,xout,yin);
	drawline(xin,yin,xin,yout);
	drawline(xin,yout,xout,yout);
	drawline(xout,yout,xout,yin);
	getch();
	while(i!=getmaxx())
	{
		while(j!=getmaxy())
		{
			if((i<xin||i>xout)||(j<yin||j>yout))
			{
				colr=getpixel(i,j);
				if(colr==WHITE)
				{
					putpixel(i,j,BLACK);
				}
			}
			j++;
		}
		j=0;
		i++;
	}
      getch();
      closegraph();
}
showmousept()
{
	in.x.ax=1;
	int86(0x33,&in,&out);
	return(out.x.ax);
}
restrictmsptr(int x1,int y1,int x2,int y2)
{
	in.x.ax=7; //Restrict horizontal limit
	in.x.cx=x1;
	in.x.dx=x2;
	int86(0x33,&in,&out);
	in.x.ax=8;//restrict vertival limit
	in.x.cx=y1;
	in.x.dx=y2;
	int86(0x33,&in,&out);
	return;
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