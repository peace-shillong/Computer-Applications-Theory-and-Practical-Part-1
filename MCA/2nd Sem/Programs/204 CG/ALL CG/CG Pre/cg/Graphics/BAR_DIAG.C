#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

 int k,x1,y1,x2,y2,dx,dy;
 float xi,yi,x,y,tmp;
 int tmpx,tmpy,i,j;

void main()
{
 int gd=DETECT,gm;
 int ax[3]={15,15,590}, ay[3]={10,360,360};
 int sl[12],z,i,max[12];
 printf("Enter the sales (MAX 100) : ");
 for(i=0;i<12;i++)
 {
  printf("\n For %d month",i+1);
  scanf("%d",&sl[i]);
  max[i]=(sl[i-1]>sl[i]?sl[i-1]:sl[i]);
 }
 for(i=0;i<7;i++)
  printf("\n%d",max[i]);

 getch();
 initgraph(&gd,&gm,"c:\\tc");

 line(ax[0],ay[0],ax[1],ay[1]);
 line(ax[1],ay[1],ax[2],ay[2]);
 outtextxy(ax[0]-10,ay[0]-5,"SALES");
 outtextxy(ax[1]+250,ay[1]+40,"MONTH");

 outtextxy(ax[1]+30,ay[1]+10,"jan");
 outtextxy(ax[1]+80,ay[1]+10,"feb");
 outtextxy(ax[1]+130,ay[1]+10,"mar");
 outtextxy(ax[1]+180,ay[1]+10,"apl");
 outtextxy(ax[1]+230,ay[1]+10,"may");
 outtextxy(ax[1]+280,ay[1]+10,"jun");
 outtextxy(ax[1]+330,ay[1]+10,"jul");
 outtextxy(ax[1]+380,ay[1]+10,"aug");
 outtextxy(ax[1]+430,ay[1]+10,"sep");
 outtextxy(ax[1]+480,ay[1]+10,"oct");
 outtextxy(ax[1]+530,ay[1]+10,"nov");
 outtextxy(ax[1]+580,ay[1]+10,"dec");

/* outtextxy(ax[0]-10,ay[0]+315,"10");
 outtextxy(ax[0]-10,ay[0]+285,"20");
 outtextxy(ax[0]-10,ay[0]+255,"30");
 outtextxy(ax[0]-10,ay[0]+225,"40");
 outtextxy(ax[0]-10,ay[0]+195,"50");
 outtextxy(ax[0]-10,ay[0]+165,"60");
 outtextxy(ax[0]-10,ay[0]+135,"70");
 outtextxy(ax[0]-10,ay[0]+105,"80");
 outtextxy(ax[0]-10,ay[0]+75,"90");
 outtextxy(ax[0]-10,ay[0]+45,"100");*/

 x1=ax[1]+40;
 y1=ay[1]-(sl[0]*3);
 x2=x1;
 y2=ay[1];
 draw();

 for(i=1;i<12;i++)
 {
// rect(sl,sl+5);
 x1=x2+50;
 y1=ay[1]-(sl[i]*3);
 x2=x1;
 y2=ay[1];
 draw();
 }
 getch();
 closegraph();
 restorecrtmode();
}

rect(int arr[],int arry[])
{
 int n=4;
 tmpx=arr[0];
 tmpy=arry[0];
 x2=arr[1];
 x1=tmpx;
 y2=arry[1];
 y1=tmpy;
 draw();
 for(i=(n-2);i>0;i--)
 {
   x1=x2;
   x2=arr[n-i];
   y1=y2;
   y2=arry[n-i];
   draw();
 }
 x1=x2;
 x2=tmpx;
 y1=y2;
 y2=tmpy;
 draw();
 return;
}

draw()
{
 dx=x2-x1;
 dy=y2-y1;

 if(abs(dx)>abs(dy))
  tmp=abs(dx);
 else
  tmp=abs(dy);

 xi=dx/tmp;
 yi=dy/tmp;
 putpixel(x,y,CYAN);
 x=x1;
 y=y1;

 for(k=1;k<tmp;k++)
 {
  x=x+xi;
  y=y+yi;
  putpixel(x,y,BLUE);
 }
 return;
}