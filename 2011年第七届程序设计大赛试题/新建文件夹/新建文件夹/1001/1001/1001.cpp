// 1001.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<stdio.h>
int main()
{
	int a,b,i,m,n = 0;
	scanf("%d%d",&a,&b);
	for(m = a+1;m < b;m++)
	{
		for(i = 2;i <  m;i++)
			if(m%i==0) break;
		if(i>=m)  printf("%d ",m);
		if(i>=m) n++;
	}
	if(n) printf("\n%d",n);
	else printf("0");
	return 0;
}

