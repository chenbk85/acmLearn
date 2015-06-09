// 1001.cpp : 定义控制台应用程序的入口点。
//


#include<stdio.h>
int main()
{
	int a,b,i,m,n = 0;
	while(1)
	{
	scanf("%d%d",&a,&b);
	if(!a&&!b) break;
	n = 0;
	for(m = a+1;m < b;m++)
	{
		for(i = 2;i <  m;i++)
			if(m%i==0) break;
		if(i>=m&&m!=1)  printf("%d ",m);
		if(i>=m&&m!=1)  n++;
	}
	if(n) printf("\n%d\n",n);
	else printf("0\n");
	}
	return 0;
}

