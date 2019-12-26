//Count no of vowel in list
//Author K.Dkhar
//2015
#include<string.h>
void v_count(char a[],int);
void main(){
	int n,i;char list[100];
	clrscr();
	printf("\n Count No of vowel in a list\n");

	printf("Enter String:\n");
	scanf("%s",list);
	n=strlen(list);
	v_count(list,n);
	getch();
}
void v_count(char list[],int n){
	int i,count=0;
	for(i=0;i<n;i++){
	list[i]=toupper(list[i]);

	     if(list[i]=='A'||list[i]=='I'||list[i]=='E'||list[i]=='O'||list[i]=='U'){
		count++;
		}

	}
	printf("\t The Number of Vowels is %d",count);
}