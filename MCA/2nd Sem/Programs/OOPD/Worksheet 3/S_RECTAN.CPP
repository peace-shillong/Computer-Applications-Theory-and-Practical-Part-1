#include<iostream.h>
#include<conio.h>
#include<math.h>
class S_Rectangle{
	float length,width;
	int x1,x2,x3,x4,y1,y2,y3,y4,xflag;
	public:
		S_Rectangle();
		S_Rectangle(int,int,int,int,int,int,int,int);
		void set(int,int, int,int, int,int , int,int);

		void set_all(int [],int []);

		float getLength();
		float getWidth();

		float perimeter();
		float area();
		void isSquare();


};
void main()
{

	/*
		points
			A.       D.

			B.	 C.

	*/
	S_Rectangle r1,r2(2,4,2,2,4,2,4,4);  //A B C D
	//S_Rectangle r2(2,2,4,2,4,4,2,4);  //B C D A
	//S_Rectangle r2(2,4,4,4,4,2,2,2);  //A D C B
	//S_Rectangle r2(2,2,2,4,4,4,4,2);  //B A D C

	//uncontinuos !Work
	//S_Rectangle r1(2,4,2,2,4,4,4,2);  //A B D C !
	//S_Rectangle r1(2,4,4,4,2,2,4,2);  //A D B C

	//S_Rectangle r2(4,2,4,4,2,4,2,2);  //C D A B
	//S_Rectangle r2(4,4,2,4,2,2,4,2);  //D A B C
	//S_Rectangle r2(4,2,2,2,2,4,4,4);  //C B A D
	//S_Rectangle r2(4,4,4,2,2,2,2,4);  //D C B A

	int x[4],y[4];
	clrscr();

	cout<<"Enter Coordinates for 1st Point(x1,y1) :"<<endl;
	cin>>x[0]>>y[0];
	cout<<"Enter Coordinates for 2nd Point(x2,y2) :"<<endl;
	cin>>x[1]>>y[1];
	cout<<"Enter Coordinates for 3rd Point(x3,y3) :"<<endl;
	cin>>x[2]>>y[2];
	cout<<"Enter Coordinates for 4th Point(x4,y4) :"<<endl;
	cin>>x[3]>>y[3];

	r1.set_all(x,y);

	cout<<"\nReactangle R1 length is "<<r1.getLength()<<endl;
	cout<<"\n Width is "<<r1.getWidth()<<endl;
	cout<<"Area is "<<r1.area();
	cout<<"\nPerimeter is :"<<r1.perimeter();
	r1.isSquare();
	//cout<<"\n\nReactangle R2 length is "<<r2.getLength()<<endl;
	//cout<<"\n Width is "<<r2.getWidth()<<endl;
	//cout<<"Area is "<<r2.area();
	//cout<<"\nPerimeter is :"<<r2.perimeter();
	//r2.isSquare();


	getch();

}

S_Rectangle::S_Rectangle(){
	length=width=0;
	x1=x2=x3=x4=0;
	y1=y2=y3=y4=0;
	xflag=0;
}
S_Rectangle::S_Rectangle(int x1,int y1,int x2,int y2,int x3,int y3,int x4, int y4){

	xflag=0;
	set(x1,y1,x2,y2,x3,y3,x4,y4);


}

void S_Rectangle::set(int x1,int y1,int x2,int y2,int x3,int y3,int x4, int y4){

     int flag=0;
     if(x1>=0 && x1<=20 && x2>=0 && x2<=20 && x3>=0 && x3<=20 && x4>=0 && x4<=20){
	   if(y1>=0 && y1<=20 && y2>=0 && y2<=20 && y3>=0 && y3<=20 && y4>=0 && y4<=20){
	      //lie in 1st Quad

	      //if(x1==x2 && y1==y3 && x3==x4 && y2==y4){
	      /*
	      //main checking
	      if(x1==x2){
		if(y2==y3 && y1==y4 && x3==x4)
			flag=1;
			xflag=1;
	      }
	      else if(y1==y2){
		if(x1==x4 && x2==x3 && y3==y4)
			flag=1;
	      }
	      */

	      //Using Distance Formula
	      int xi=(x1-x3)*(x1-x3);
	      int yi=(y1-y3)*(y1-y3);
	      int d1=xi+yi;
	      //float d1=sqrt(dai);
	      xi=(x2-x4)*(x2-x4);
	      yi=(y2-y4)*(y2-y4);
	      int d2=xi+yi;
	      //float d2=sqrt(dai);
	      if(d1==d2)
		flag=1;
	      else
		flag=0;

	      if(flag==1)
	      {
	      //forms a rectangle
	      S_Rectangle::x1=x1; // mot this.x1
	      S_Rectangle::x2=x2;
	      S_Rectangle::x3=x3;
	      S_Rectangle::x4=x4;

	      S_Rectangle::y1=y1;
	      S_Rectangle::y2=y2;
	      S_Rectangle::y3=y3;
	      S_Rectangle::y4=y4;
	      }
	      else{
		//
		cout<<"Given Points Don't Form a rectangle ";
	       //	length=width=0;
		}

	   }
	   else{
		cout<<"Y-Coordinates don't lie on the 1st Quadrant";
		//length=width=0;

		}
     }
     else{
	cout<<"X-Coordinates don't lie on the 1st Quadrant";
       //	length=width=0;
	}


}
void S_Rectangle::set_all(int a[],int b[]){

	int i,flag=0,main_flag=0;

	for(i=0;i<4;i++){
		if(a[i]>=0 && a[i]<=20){
			if(b[i]<=20 && b[i]>=0){
			  flag++;
			  //flag becomes 4 if points lie in 1st quad
			}
		}
	}
	if(flag==4){

	 //if(a[0]==a[1] && b[0]==b[2] && a[2]==a[3] && b[1]==b[3]){
	 /*
	  if(a[0]==a[1]){
		if(b[1]==b[2] && b[0]==b[3] && a[2]==a[3])
			main_flag=1;
			xflag=1;//means points x-axis are equal

	      }
	  else if(b[0]==b[1]){
		if(a[0]==a[3] && a[1]==a[2] && b[2]==b[3])
			main_flag=1;
	      }

	 *///Using Distance Formula
	      int xi=(a[0]-a[2])*(a[0]-a[2]);
	      int yi=(b[0]-b[2])*(b[0]-b[2]);
	      int d1=xi+yi;
	      //float d1=sqrt(dai);
	      xi=(a[1]-a[3])*(a[1]-a[3]);
	      yi=(b[1]-b[3])*(b[1]-b[3]);
	      int d2=xi+yi;
	      //float d2=sqrt(dai);
	      if(d1==d2)
		main_flag=1;
	      else
		main_flag=0;


	 if(main_flag==1)
	 {

		//forms a rectangle
	      x1=a[0];
	      x2=a[1];
	      x3=a[2];
	      x4=a[3];

	      y1=b[0];
	      y2=b[1];
	      y3=b[2];
	      y4=b[3];
	 }
	 else{
		 cout<<"Given Points Do not form a Rectangle";
	       //	length=width=0;

	 }

	}
	else{
		cout<<"Given Points Don't Lie on 1st Quadrant";
	       //	length=width=0;
	}

}

float S_Rectangle::getLength(){


     if(xflag){ // x coordinates are equal
	if(abs(x4-x2) > abs(y1-y2)){
	length =abs(x4-x2);
	width = abs(y1-y2);
	}
	else{
		length=abs(y1-y2);
		width=abs(x4-x2);
	}

     }
     else{
	if(abs(x2-x1)>abs(y3-y2)){
		length = abs(x2-x1);
		width =abs(y3-y2);
	}
	else
	{
		length=abs(y3-y2);
		width=abs(x2-x1);
	}
     }

     return length;
}
float S_Rectangle::getWidth(){

	if(length==0 && width==0)
	     if(abs(x4-x2) > abs(y1-y2)){
		length = x4-x2;
		width = y1-y2;
		}
	     else{
		length = y1-y2;
		width =x4-x2;
		}

	return width;
}
float S_Rectangle::perimeter(){
	return 2*(length+width);
}

float S_Rectangle::area(){
	return length*width;
}

void S_Rectangle::isSquare(){
	if( length==width)
		cout<<"\nGiven Points Form a Square";
	else
		cout<<"\nGiven Points Do Not Form a Square";

}
