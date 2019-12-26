#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void *thread_function1(void *arg);
void *thread_function2(void *arg);
char message[]="Hello world";
int main()
{
  int res1;
  int res2;
  pthread_t child_thread1;
  pthread_t child_thread2;
  void *thread_result;
  char arg[]="good bye";
  res1=pthread_create(&child_thread1,NULL,thread_function1,(void*)arg);
  res2=pthread_create(&child_thread2,NULL,thread_function2,(void*)arg);
  if(res1!=0)
   {
    perror("The thread creation failed");
    exit(EXIT_FAILURE);
   }
  printf("the thread creation of child1 succeeded");
  if(res2!=0)
   {
    perror("the thread creation failed");
    exit(EXIT_FAILURE);
   }
   printf("The thread creation of child2 succeeded");
   res1=pthread_join(child_thread1,&thread_result);
   res2=pthread_join(child_thread2,&thread_result);
   if(res1!=0)
   {
      printf("the thread joined failed");
      exit(EXIT_FAILURE):
   }
   printf("The thread1 has finished join");
   printf("the message is now %s",message);
   if(res2!=0)
   {
     printf("The thread joined failed");
     exit(EXIT_FAILURE);
   }
   printf("The thread has finished join");
   exit(EXIT_SUCCESS);
}
void *thread_function1(void *arg)
{
  printf("Display the modified content of the string:\n");
  sleep(1);
  strcpy(message,"Good Bye");
  pthread_exit("Thank you");
}
void *thread_function2(void *arg)
{
  printf("Display the square of the first n natural number\n");
  int i,n,square;
  square=0;
  printf("Enter the range of the natural number");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    square=square+i*i;
    printf("%d",square);
  }
}
