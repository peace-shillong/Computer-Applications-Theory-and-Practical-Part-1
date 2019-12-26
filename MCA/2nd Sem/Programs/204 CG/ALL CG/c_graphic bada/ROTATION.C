#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void rline(float x1,float y1,float x2,float y2,int c);
void main()
{

    float x[10],y[10],angle;
    int n,i,tx,ty,xr,yr;
    int d=DETECT,gm;
    printf("\nHow many sides do u want ? ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
       printf("\nEnter the coordinates of x %d and y %d: ",i,i);
       scanf("%f %f",&x[i],&y[i]);
    }

    printf("\n\n Enter the rotation angle : ");
    scanf("%f",&angle);


    xr=x[1];
    yr=y[1];

    initgraph(&d,&gm,"c:\\tc\\bgi");

    for(i=1;i<n;i++)
    {
	rline(x[i],y[i],x[i+1],y[i+1],4);

    }
    rline(x[n],y[n],x[1],y[1],4);
      getch();


    angle=6.28*(angle/360);
    printf("\n After Rotation");

   /* for(i=1;i<n;i++)
    {
	rline(x[i],y[i],x[i+1],y[i+1],0); //redrawing old line in black color

    }
    rline(x[n],y[n],x[1],y[1],0); */
    //rotation
    for(i=1;i<=n;i++)
    {
	x[i]=(float)xr+(x[i]-xr)*cos(angle)-(y[i]-yr)*sin(angle);
	y[i]=(float)yr+(x[i]-xr)*sin(angle)+(y[i]-yr)*cos(angle);
    }

    //drawing lines after changing value of x and y
    for(i=1;i<n;i++)
    {
	rline(x[i],y[i],x[i+1],y[i+1],3);
    }
    rline(x[n],y[n],x[1],y[1],3);
    getch();

}

void rline(float x1,float y1,float x2,float y2,int c)
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