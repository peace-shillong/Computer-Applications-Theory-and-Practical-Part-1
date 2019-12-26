#include<iostream.h>
#include<conio.h>
#include<z:\draw.h>
#include<z:\mouse.h>
#include<dos.h>
//#include<z:\mouse.h>
void rotate(int *poly,int sides,float theta,int x,int y);
void main()
{
	int poly[]={245,150,230,225,245,255,260,225},poly1[]={245,150,187,99,154,97,172,125},poly2[]={245,150,317,125,335,97,302,99};
	int gd=DETECT,mode;
	initgraph(&gd,&mode,"c:\\tc\\bgi");
	polygn(4,poly,WHITE);                      //blades
	polygn(4,poly1,WHITE);
	polygn(4,poly2,WHITE);
	circle(245,150,2);

	int base[]={245,120,235,140,200,getmaxy()-10,290,getmaxy()-10,255,140};
	polygn(5,base,WHITE);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	int cntrl[]={20,20,70,20,70,40,20,40};
	int button,x,y;
	polygn(4,cntrl,WHITE);
	outtextxy(cntrl[0]+2,cntrl[1]+2,"Speed +");
	cntrl[1]=cntrl[3]=60;
	cntrl[5]=cntrl[7]=80;
	polygn(4,cntrl,WHITE);
	outtextxy(cntrl[0]+2,cntrl[1]+2,"Speed -");
	cntrl[1]=cntrl[3]=100;
	cntrl[5]=cntrl[7]=120;
	polygn(4,cntrl,WHITE);
	outtextxy(cntrl[0]+4,cntrl[1]+2,"Stop s");
	cntrl[1]=cntrl[3]=140;
	cntrl[5]=cntrl[7]=160;
	polygn(4,cntrl,WHITE);
	outtextxy(cntrl[0]+4,cntrl[1]+2,"Quit q");
	getch();
	int spd=100;
	char ch;
	initmouse();
	showmousept();
	while((ch=getch())!='q')
	while(!kbhit())
	{       getmspos(&button,&x,&y);
		if(ch=='-'&&spd<=200)
			spd+=20;
		if(ch=='+'&&spd>0)
			spd-=10;
		if(ch=='s')continue;
		if(button==1)
		{
			if(x>20&&x<80&&y>20&&y<40&&spd>0)
				spd-=10;
			else if(x>20&&x<80&&y>60&&y<80&&spd<=0)
				spd+=20;
			else if(x>20&&x<80&&y>100&&y<120)
			{
				ch='s';
				continue;
			}
			else if(x>20&&x<80&&y>140&&y<160)
				exit(0);
		}
		rotate(poly,4,10,245,150);
		rotate(poly1,4,10,245,150);
		rotate(poly2,4,10,245,150);
		circle(245,150,2);
		polygn(5,base,WHITE);
		delay(spd);

	}
	//for(int i=0;i<6;i++)
		//cout<<poly[i]<<endl;
	 getch();
}
void rotate(int *poly,int sides,float theta,int x,int y)
{
	float poly1[10];
	theta=6.28*(theta/360);
	for(int i=0;i<=sides*2;i+=2)
	{
		poly1[i]=x+(poly[i]-x)*cos(theta)-(poly[i+1]-y)*sin(theta);
		poly1[i+1]=y+(poly[i]-x)*sin(theta)+(poly[i+1]-y)*cos(theta);
	}

	polygn(sides,poly,BLACK);
	for(i=0;i<=sides*2;i++)
		poly[i]=ROUND(poly1[i]);
	polygn(sides,poly,WHITE);

}





