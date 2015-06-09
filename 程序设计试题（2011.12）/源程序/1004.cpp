#include<stdio.h>
int main()
{int n,i,a,b;
long m;
scanf("%d",&n);
m=0;
while(n!=0)
{m=0;
	for(i=1;i<=100;i++)
	{
		if(i%n==0)continue;
        a=i/10;
	    b=i%10;
    	if(a==0&&b%n==0)continue;
	    if(a!=0)
		{   if(a%n==0)continue;
	        if(b!=0&&b%n==0)continue;
		}
        m=m+i;
	}
   printf("%ld\n",m);
   scanf("%d",&n);

}
   return 0;
}

