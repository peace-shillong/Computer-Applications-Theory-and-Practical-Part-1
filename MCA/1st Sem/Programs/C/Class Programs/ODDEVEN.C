#include<stdio.h>
#include<conio.h>
void main(){
      int n,res;
      clrscr();
      printf("Enter any Number ");
      scanf("%d",&n);
      res=n%2;
      if(res==0)
	      printf("%d is an Even Number",n);
      else
	      printf("%d is an Odd Number",n);
      getch();
}
