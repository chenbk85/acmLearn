// 1002.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
int main()
{
	int n,i,j;
	char c;
	scanf("%c",&c);
	scanf("%d",&n);
	if(n%2==0) n++;
	for(i = 1;i <= n;i++)
	{
		 for(j = 1;j<=n-i;j++)
			 printf(" ");
		 for(j=1;j<=2*i-1;j++)
			printf("*");
		printf("\n");
	 }
	return 0;
}

