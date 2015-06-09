// 1006.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
void main()
{
	long int m,n,c,max;
	scanf("%ld",&m);
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
	printf("\nMax is %ld and we need %ld steps.",max,n);

}

