void main(){

	int i;
	char far *v=0xB8000000;
	clrscr();
	for(i=0;i<=3999;i+=2)
		*(v+i)=65;
		//printf("Hello");
		*(v+2)=66;
	for(i=1;i<=3999;i+=2)
		*(v+i)=10000;
	getch();
}