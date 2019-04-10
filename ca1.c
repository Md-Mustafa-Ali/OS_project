#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
int main()
{ int a[2],b[2],p,n;
  pipe(a);
  pipe(b);
  p=fork();
  if(p!=0)
   { int c;
     char buff2[100];
     n=read(a[0],buff2,100);
     for(int i=0;i<n;i++)
      { c=(int)buff2[i];
        if(c>=97 && c<=122)
          { c=c-32;
            buff2[i]=(char)c;
          }
        else if(c>=65 && c<=90)
          { c=c+32;
            buff2[i]=(char)c;
          }
      }
     write(b[1],buff2,n);
   }
  else
   { char buff1[100];
     printf("Enter a string to reverse the case : \n");
     n=read(0,buff1,100);
     write(a[1],buff1,n);
     wait(NULL);
     printf("String with reversed case : \n");
     n=read(b[0],buff1,n);
     write(1,buff1,n);
   }
}
