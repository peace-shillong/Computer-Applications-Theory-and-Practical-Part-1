#include "Z:\C\AREAS.C"
void main(){
	int s,h,b,c;
	float r;
	do{
	clrscr();
	printf("MENU\n");
	printf("1. Area of Circle.\n");
	printf("2. Area of Square.\n");
	printf("3. Area of Triangle.\n");
	printf("4.Exit.\nEnter Choice");
	scanf("%d",&c);
	switch(c){
		case 1:
			printf("\nArea of Circle\nEnter Radius");
			scanf("%f",&r);
			#ifdef AREAC
			printf("\nArea of Circle is %.2f",AREAC(r));
			#endif
			getch();
			break;
		case 2:
			printf("\nArea of \nEnter side\n");
			scanf("%d",&s);
			printf("Area of Square is %d",AREAS(s));
			getch();
			break;
		case 3:
			printf("Area of Triangle\nEnter height and breadth");
			scanf("%d %d",&h,&b);
			printf("Area of Triangle is %d",AREAT(h,b));
			getch();
			break;
		case 4:
			break;
		default:
			printf("Wrong Input");
			getch();
	}
	}while(c!=4);
}