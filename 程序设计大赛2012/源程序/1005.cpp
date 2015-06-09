// 250.cpp : 定义控制台应用程序的入口点。
//
#include<stdio.h>

int a[21],n;
int main()
{
	int t;
	a[1] = 1;
	int IsPrime(int t);
	int Find(int t);
	void backtrace(int t);
	while(scanf("%d",&n)!=EOF)
	{
		backtrace(2);
	}
	return 0;
}
int IsPrime(int t)
{
	int i;
	for(i = 2;i < t;i++)
		if(t%i == 0) return 0;
	return 1;
}
int Find(int t)
{
	int i;
	for(i = 1;i < t;i++)
		if(a[i] == t) return 1;
	return 0;
}
void backtrace(int t)
{
	int i;
	if(t>n)
	{
		if(IsPrime(a[n]+a[1])&&!Find(t))
		{
			for(i = 1;i < n+1;++i)
				printf("%d ",a[i]);
			printf("\n");
		}
		else 
			for(i = 2;i <= n;i++)
			{
				a[t] = i;
				if(IsPrime(a[t]+a[t-1])&&!Find(t)) backtrace(t+1);
			}
	}
}