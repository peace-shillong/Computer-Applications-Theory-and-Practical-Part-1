# include<iostream.h>
# include<graphics.h>
# include<conio.h>
# include<math.h>
# define f  0.3
# define projection_angle  45

void show_screen( );

void Bezier_curve(const int,const int [10][3]);

double nCr(int,int);
double factorial(int);

void get_projected_point(double&,double&,double&);
void multiply_matrices(const float[4],const float[4][4],float[4]);

void Dashed_line(const int,const int,const int,const int,const int=0);


int main( )
{
       int driver=VGA;
       int mode=VGAHI;

       int n;

       do
      {
         show_screen( );

         gotoxy(8,10);
         cout<<"Degree of Bezier Curve : n :";

         gotoxy(8,11);
	 //cout<<"様様様様様様様様様様様様様様";

         gotoxy(12,13);
         cout<<"Enter the value of n (1<n<10) = ";
         cin>>n;

         if(n>=10)
        n=10;

         int control_points[10][3]={0};

         for(int count=0;count<=n;count++)
        {
           gotoxy(8,18);
           cout<<"Coordinates of Point-"<<count<<" (x"<<count<<",y"<<count<<",z"<<count<<") :";

           gotoxy(8,19);
	   //cout<<"様様様様様様様様様様様様様様様様様様";

           gotoxy(12,21);
           cout<<"Enter the value of x"<<count<<" = ";
           cin>>control_points[count][0];

           gotoxy(12,23);
           cout<<"Enter the value of y"<<count<<" = ";
           cin>>control_points[count][1];

           gotoxy(12,25);
           cout<<"Enter the value of z"<<count<<" = ";
           cin>>control_points[count][2];

           gotoxy(8,18);
           cout<<"                                            ";

           gotoxy(12,21);
           cout<<"                                            ";

           gotoxy(12,23);
           cout<<"                                            ";

           gotoxy(12,25);
           cout<<"                                            ";
         }

         initgraph(&driver,&mode,"..\\Bgi");

         setcolor(15);
           Bezier_curve(n,control_points);

         setcolor(15);
           outtextxy(110,460,"Press <Enter> to continue or any other key to exit.");

         int key=int(getch( ));

         if(key!=13)
        break;
      }
       while(1);

       return 0;
    }


 /*************************************************************************///--------------------------  Bezier_curve( )  --------------------------///*************************************************************************/
 void Bezier_curve(const int n,const int cp[10][3])
    {
       int color=getcolor( );

       setcolor(7);

       double x_1;
       double y_1;
       double z_1;
       double x_2;
       double y_2;
       double z_2;

       for(int count=0;count<n;count++)
      {
         x_1=cp[count][0];
         y_1=cp[count][1];
         z_1=cp[count][2];
         x_2=cp[(count+1)][0];
         y_2=cp[(count+1)][1];
         z_2=cp[(count+1)][2];

         get_projected_point(x_1,y_1,z_1);
         get_projected_point(x_2,y_2,z_2);

         Dashed_line((int)(x_1+0.5),(int)(y_1+0.5),
                         (int)(x_2+0.5),(int)(y_2+0.5));
      }

       double x;
       double y;
       double z;

       for(float u=0.0005;u<=1;u+=0.0005)
      {
         x=0;
         y=0;
         z=0;

         for(int k=0;k<=n;k++)
        {
           x+=(cp[k][0]*nCr(n,k)*pow(u,k)*powl((1-u),(n-k)));
           y+=(cp[k][1]*nCr(n,k)*pow(u,k)*powl((1-u),(n-k)));
           z+=(cp[k][2]*nCr(n,k)*pow(u,k)*powl((1-u),(n-k)));
        }

         get_projected_point(x,y,z);

         putpixel((int)(x+0.5),(int)(y+0.5),color);
      }
    }

 /*************************************************************************///------------------------------  nCr( )  -------------------------------///*************************************************************************/
 double nCr(int n,int r)
    {
       double nf;
       double rf;
       double nrf;
       double ncr;

       nf=factorial(n);
       rf=factorial(r);
       nrf=factorial((n-r));

       ncr=(nf/(rf*nrf));

       return ncr;
    }

 /*************************************************************************///---------------------------  factorial( )  ----------------------------///*************************************************************************/
 double factorial(int number)
    {
       double factorial=1;

       if(number==0 || number==1);

       else
      {
         for(int count=1;count<=number;count++)
        factorial=factorial*count;
      }

       return factorial;
    }

 /************************************************************************///---------------------  get_projected_point( )  -----------------------///************************************************************************/
 void get_projected_point(double& x,double& y,double& z)
    {
       float fcos0=(f*cos(projection_angle*(M_PI/180)));
       float fsin0=(f*sin(projection_angle*(M_PI/180)));

       float Par_v[4][4]={
                {1,0,0,0},
                {0,1,0,0},
                {fcos0,fsin0,0,0},
                {0,0,0,1}
             };

       float xy[4]={x,y,z,1};
       float new_xy[4]={0};

       multiply_matrices(xy,Par_v,new_xy);

       x=new_xy[0];
       y=new_xy[1];
       z=new_xy[2];
    }

 /************************************************************************///----------------------  multiply_matrices( )  ------------------------///************************************************************************/
 void multiply_matrices(const float matrix_1[4],
		  const float matrix_2[4][4],float matrix_3[4])
    {
       for(int count_1=0;count_1<4;count_1++)
      {
         for(int count_2=0;count_2<4;count_2++)
        matrix_3[count_1]+=
               (matrix_1[count_2]*matrix_2[count_2][count_1]);
      }
    }

 /*************************************************************************///---------------------------  Dashed_line( )  --------------------------///*************************************************************************/
 void Dashed_line(const int x_1,const int y_1,const int x_2,
		      const int y_2,const int line_type)
    {
       int count=0;
       int color=getcolor( );

       int x1=x_1;
       int y1=y_1;

       int x2=x_2;
       int y2=y_2;

       if(x_1>x_2)
      {
         x1=x_2;
         y1=y_2;

         x2=x_1;
         y2=y_1;
      }

       int dx=abs(x2-x1);
       int dy=abs(y2-y1);
       int inc_dec=((y2>=y1)?1:-1);

       if(dx>dy)
      {
         int two_dy=(2*dy);
         int two_dy_dx=(2*(dy-dx));
         int p=((2*dy)-dx);

         int x=x1;
         int y=y1;

         putpixel(x,y,color);

         while(x<x2)
        {
           x++;

           if(p<0)
              p+=two_dy;

           else
              {
             y+=inc_dec;
             p+=two_dy_dx;
              }

           if((count%2)!=0 && line_type==0)
              putpixel(x,y,color);

	   else if((count%5)!=4 && line_type==1)
              putpixel(x,y,color);

	   else if((count%10)!=8 && (count%10)!=9 && line_type==2)
              putpixel(x,y,color);

	   else if((count%20)!=18 && (count%20)!=19 && line_type==3)
              putpixel(x,y,color);

	   else if((count%12)!=7 && (count%12)!=8 &&
                (count%12)!=10 && (count%12)!=11 && line_type==4)
              putpixel(x,y,color);

           count++;
        }
      }

       else
      {
         int two_dx=(2*dx);
         int two_dx_dy=(2*(dx-dy));
         int p=((2*dx)-dy);

         int x=x1;
         int y=y1;

         putpixel(x,y,color);

         while(y!=y2)
        {
           y+=inc_dec;

           if(p<0)
              p+=two_dx;

           else
              {
             x++;
             p+=two_dx_dy;
              }

           if((count%2)!=0 && line_type==0)
              putpixel(x,y,color);

	   else if((count%5)!=4 && line_type==1)
              putpixel(x,y,color);

	   else if((count%10)!=8 && (count%10)!=9 && line_type==2)
              putpixel(x,y,color);

	   else if((count%20)!=18 && (count%20)!=19 && line_type==3)
              putpixel(x,y,color);

	   else if((count%12)!=7 && (count%12)!=8 &&
                (count%12)!=10 && (count%12)!=11 && line_type==4)
              putpixel(x,y,color);

           count++;
        }
      }
    }

 /*************************************************************************///--------------------------  show_screen( )  ---------------------------///*************************************************************************/
 void show_screen( )
    {
       restorecrtmode( );
       clrscr( );
       textmode(C4350);

       //cprintf("\n********************************************************************************");
       //cprintf("*-*****************************-                -*****************************-*");
       //cprintf("*------------------------------- ");

       textbackground(1);
       cprintf(" Bezier Curve ");
       textbackground(8);

       //cprintf(" -------------------------------*");
       //cprintf("*-*****************************-                -*****************************-*");
       //cprintf("*-****************************************************************************-*");

       for(int count=0;count<42;count++)
      //cprintf("*-*                                                                          *-*");

       gotoxy(1,46);
      // cprintf("*-****************************************************************************-*");
      // cprintf("*------------------------------------------------------------------------------*");
      // cprintf("********************************************************************************");

       gotoxy(1,2);
    }
