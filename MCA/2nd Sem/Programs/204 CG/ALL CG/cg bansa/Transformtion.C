
//Translation
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void lline(float x1,float y1,float x2,float y2,int c);
void main()
{

    int x[10],y[10],n,i,tx,ty;
    int d=DETECT,gm;
    printf("\nHow many coordinates? ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
       printf("\nEnter the coordinates of x %d and y %d: ",i,i);
       scanf("%d %d",&x[i],&y[i]);
    }
    printf("\n Enter the translation factor tx : ");
    scanf("%d",&tx);
     printf("\n Enter the translation factor ty : ");
    scanf("%d",&ty);

    initgraph(&d,&gm,"c:\\tc\\bgi");
    for(i=1;i<n;i++)
    {
	lline(x[i],y[i],x[i+1],y[i+1],5);

    }
    lline(x[n],y[n],x[1],y[1],5);
    getch();
   // clrscr();
    printf("\n After translaton");

    for(i=1;i<n;i++)
    {
	lline(x[i],y[i],x[i+1],y[i+1],0); //redrawing old line in black color

    }
    lline(x[n],y[n],x[1],y[1],0);

    //transaltion part
    for(i=1;i<=n;i++)
    {
	x[i]=x[i]+tx;
	y[i]=y[i]+ty;
    }
    for(i=1;i<n;i++)
    {
	lline(x[i],y[i],x[i+1],y[i+1],4);

    }
     lline(x[n],y[n],x[1],y[1],4);
     getch();

    closegraph();
}
void lline(float x1,float y1,float x2,float y2,int c)
{
	float i,j;
	if(x2>x1){
		for(i=x1;i<=x2;i++){
			j=y1+((i-x1)/(x1-x2))*(y1-y2);
			putpixel(i,j,c);
		}
	}else if(x1>x2){
		for(i=x2;i<=x1;i++){
			j=y2+((i-x2)/(x2-x1))*(y2-y1);
			putpixel(i,j,c);
		}
	}else if(x1==x2 && y2>y1){
		for(i=x1,j=y1;j<=y2;j++){
			putpixel(i,j,c);
		}
	}else if(x1==x2 && y2<y1){
		for(i=x1,j=y1;j>=y2;j--){
			putpixel(i,j,c);
		}
	}


}


