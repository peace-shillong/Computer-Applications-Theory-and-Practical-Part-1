#include<STDIO.H>
#include<CONIO.H>
#include<GRAPHICS.H>
#include<MATH.H>
#include <DOS.H>
# define round(a)((int)(a+0.5)) 
# define pi 3.142857 
int psang; 
void parcir(int xc,int yc,float r,int col) 
{ int k=0; float x,y; 
for(k=0;k<360;k++) 
{ x=xc+r*cos(pi*k/180); 
y=yc+r*sin(pi*k/180); 
putpixel(round(x),round(y),col); 
// delay(10); 
} 
} 
//++++++++++++++++++++++++++++++++++++++++++ 

void ddaline(int x1,int y1,int x2,int y2,int col) 
{ int steps,dx,dy,i;float xinc,yinc,x,y; 
dx=x2-x1; 
dy=y2-y1; 
if(abs(dx)>abs(dy)) 
steps=abs(dx); 
else 
steps=abs(dy); 
xinc=(float)dx/steps; 
yinc=(float)dy/steps; 
x=x1;y=y1; 
putpixel(x,y,col); 
for(i=0;i<=steps;i++) {
x=x+xinc;
y=y+yinc; 
putpixel(round(x),round(y),col); 
} 
}
void circleMidpoint(int xc, int yc, int r)
{
int x = 0, y = r;
int p = 1 - r;
while (x < y)
{
drawCircle(xc, yc, x, y);
x++;

if (p < 0)
p = p + 2 * x + 1;
else
{
y--;
p = p + 2 * (x - y) + 1;
}
drawCircle(xc, yc, x, y);

}
}
int drawCircle(int xc, int yc, int x, int y)
{
putpixel(xc+x, yc+y, RED);
putpixel(xc-x, yc+y, RED);
putpixel(xc+x, yc-y, RED);
putpixel(xc-x, yc-y, RED);
putpixel(xc+y, yc+x, RED);
putpixel(xc-y, yc+x, RED);
putpixel(xc+y, yc-x, RED);
putpixel(xc-y, yc-x, RED);
}

void drawclock()
{
setcolor(2);
circleMidpoint(200,200,70);
setcolor(3);
circleMidpoint(200,200,72);
setcolor(13);
outtextxy(190,135,"12");
outtextxy(195,260,"6");
outtextxy(135,200,"9");
outtextxy(260,200,"3");
setcolor(5);
ddaline(150,270,150,370,CYAN);
ddaline(150,370,250,370,CYAN);
ddaline(250,370,250,270,CYAN);
}


void main()
{int gd=DETECT,gm=DETECT;
float xh,yh,xs,ys,mx,my,x,y;
float hang=-90,mang=-90,sang=-90;
struct time t;
clrscr();

gettime(&t);

hang+=t.ti_hour*30;
mang+=t.ti_min*6;
sang+=t.ti_sec*0.1;
psang=60;
printf("%d: %d: %d",t.ti_hour,t.ti_min,t.ti_sec);
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
while(!kbhit())
{ cleardevice();
drawclock(); // gettime(&t); printf("%d: %d: %d",t.ti_hour,t.ti_min,t.ti_sec);
xh=200+20*cos(pi*hang/180);
yh=200+20*sin(pi*hang/180);
ddaline(200,200,round(xh),(yh),YELLOW);
mx=200+40*cos(pi*mang/180);
my=200+40*sin(pi*mang/180);
ddaline(200,200,round(mx),round(my),RED);
xs=200+60*cos(pi*sang/180);
ys=200+60*sin(pi*sang/180);
ddaline(200,200,round(xs),round(ys),BLUE);
hang+=(1/120);
mang+=0.1;
sang+=6;
if(psang==60)
{ while(psang!=120)
{
x=200+70*cos(psang*pi/180);
y=270+70*sin(psang*pi/180);
psang+=1;
ddaline(200,270,round(x),round(y),RED);
parcir(round(x),round(y),10,RED);
ddaline(200,270,round(x),round(y),BLACK);
parcir(round(x),round(y),10,BLACK);
delay(5);
}
}
if(psang==120)
{ while(psang!=60)
{
x=200+70*cos(psang*pi/180);
y=270+70*sin(psang*pi/180);
psang-=1;
ddaline(200,270,round(x),round(y),RED);
parcir(round(x),round(y),10,RED);
ddaline(200,270,round(x),round(y),BLACK);
parcir(round(x),round(y),10,BLACK);
delay(5);
}
}
delay(700);
}
getch();
}