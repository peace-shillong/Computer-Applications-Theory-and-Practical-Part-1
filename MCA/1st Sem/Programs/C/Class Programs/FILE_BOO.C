//BOOK Storing/Searching System
#include<stdio.h>
void main(){
	//Book info
	char book_nm[20],author[20],publsh[20];
	int book_price,book_id;
	FILE fs;
	fs=fopen("Z:\\BookSSS.txt","w+");
	clrscr();
	printf("Enter Book Title\n");
	scanf("%s",book_nm);
	printf("Enter Book Author\n");
	//scanf("%s",book_nm);
	printf("%s",book_nm);


	getch();
}