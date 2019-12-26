#include<iostream.h>
#include<conio.h>
#include<Z:\draw.h>
#include<dos.h>
#include<Z:\mouse.h>
void translation(int *poly,int sides,int ,int);
void magnify(int *poly,int sides,float,float);
void rotate(int *poly,int sides,float theta,int x,int y);
void main()
{
	int poly[]={345,150,380,255,320,255};//,poly1[]={245,150,136,127,166,75},poly2[]={245,150,318,67,348,119};
	int gd=DETECT,mode;
	initgraph(&gd,&mode,"");
	polygn(3,poly,WHITE);                      //blades
	//polygn(3,poly1,WHITE);
	//polygn(3,poly2,WHITE);

	//int base[]={225,140,265,140,350,getmaxy()-50,150,getmaxy()-50};
	//polygn(4,base,BROWN);
	getch();
	/*while(getch()!='q')
		translation(poly,3,10,0);
	*/
	magnify(poly,3,2,2);
	getch();
	translation(poly,3,-100,0);
	getch();
	while(!kbhit())
	{
		rotate(poly,3,10,245,150);
		delay(100);
	}
	//for(int i=0;i<6;i++)
		//cout<<poly[i]<<endl;
	 getch();
}
void magnify(int *poly,int sides,float xf,float yf)
{
	int poly1[8];
	for(int i=0;i<=sides*2;i+=2)
	{
		poly1[i]=poly[0]+(int)(poly[i]-poly[0])*xf;
		poly1[i+1]=poly[1]+(int)(poly[i+1]-poly[1])*yf;
	}
	polygn(sides,poly,BLACK);
	polygn(sides,poly1,WHITE);
	for(i=0;i<=sides*2;i++)
		poly[i]=poly1[i];
}
void translation(int *poly,int sides,int xmove,int ymove)
{
	int poly1[8];
	for(int i=0;i<=sides*2;i+=2)
	{
		poly1[i]=(poly[i])+xmove;
		poly1[i+1]=(poly[i+1])+ymove;
	}
	polygn(sides,poly,BLACK);
	polygn(sides,poly1,WHITE);
	for(i=0;i<=sides*2;i++)
		poly[i]=poly1[i];
}
void rotate(int *poly,int sides,float theta,int x,int y)
{
	int poly1[8];
	theta=6.28*(theta/360);
	for(int i=0;i<=sides*2;i+=2)
	{
		poly1[i]=x+(poly[i]-x)*cos(theta)-(poly[i+1]-y)*sin(theta);
		poly1[i+1]=y+(poly[i]-x)*sin(theta)+(poly[i+1]-y)*cos(theta);
	}
	polygn(sides,poly,BLACK);
	polygn(sides,poly1,WHITE);
	for(i=0;i<=sides*2;i++)
		poly[i]=poly1[i];
}