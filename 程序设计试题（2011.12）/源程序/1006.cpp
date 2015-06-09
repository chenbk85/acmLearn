// 1006.1.cpp : 定义控制台应用程序的入口点。

#include<stdio.h>
int main()
{
	int n,m,i,a,flag;
	scanf("%d",&n);
	while(n!=0)
	{
		m=0;flag=1;
		while(n!=0)
		{
			a=n%10;
			if(a%2==0)
			{ flag=0;printf("no\n");break;}
			else {n=n/10;m=m+a*a;}
		}
	    if(flag==1)	
			printf("%d\n",m);
		scanf("%d",&n);
	}
  return 0;
}


