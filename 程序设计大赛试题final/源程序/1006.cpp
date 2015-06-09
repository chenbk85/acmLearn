// 1006.cpp : 定义控制台应用程序的入口点。
//


#include<stdio.h>
int main()
{
	long int m,n,c,max;
	while(1){
	scanf("%ld",&m);
	if(!m) break;
	n=0;c=m;
	printf("%ld",m);
	max=m;
	while(c!=1)
	{
		if(c%2==1)
		{
			c=3*c+1;
			n++;
			printf("->%ld",c);
			if(c>max)max=c;
		}
		else
		{
			c=c/2;
			n++;
			printf("->%ld",c);
			if(c>max)max=c;
		}
		
	}	
	printf("\nMax is %ld and we need %ld steps.\n",max,n);
	}
	return 0;
}

