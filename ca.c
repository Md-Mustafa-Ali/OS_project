#include<pthread.h>
#include<stdio.h>
float avg=0.0,min=0.0,max=0.0;
void *average(void *a)
{ int *q=(int*)(a);
  int n=*q;
  q=q+1;
  int sum=0;
  for(int i=1;i<n+1;i++)
   { sum+=*q;
     q=q+1; }
  avg=sum/n;
}
void *minimum(void *a)
{ int *q=(int*)(a);
  int n=*q;
  q=q+1;
  int m=*q;
  q=q+1;
  for(int i=1;i<n;i++)
   { if(m>*q)
        m=*q;
     q=q+1; }
  min=m;
}
void *maximum(void *a)
{ int *q=(int*)(a);
  int n=*q;
  q=q+1;
  int m=*q;
  q=q+1;
  for(int i=1;i<n;i++)
   { if(m<*q)
       m=*q;
     q=q+1; }
  max=m;
}
int main()
{ int n;
  pthread_t th1,th2,th3;
  printf("Enter the total no. of observations : ");
  scanf("%d",&n);
  int values[n+1];
  values[0]=n;
  int *p=&values[0];
  printf("Enter the %d values \n",n);
  for(int i=1;i<n+1;i++)
      scanf("%d",&values[i]);
  pthread_create(&th1,NULL,average,(void*)p);
  pthread_create(&th2,NULL,minimum,(void*)p);
  pthread_create(&th3,NULL,maximum,(void*)p);
  pthread_join(th1,NULL);
  pthread_join(th2,NULL);
  pthread_join(th3,NULL);
  printf("\nThe average value is %0.1f\n",avg);
  printf("The minimum value is %0.1f\n",min);
  printf("The maximum value is %0.1f\n",max);
}
