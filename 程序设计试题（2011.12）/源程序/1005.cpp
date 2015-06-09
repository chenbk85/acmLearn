
#include<stdio.h>
int main()
{
	int Process(int a,int b);
	int n,i,j,a,b;
	scanf("%d%d",&a,&b);
	n = Process(a,b);
	for(i = 1;i<=n;i++)
	{
		for(j = 0;j<n-i;j++)
			printf(" ");
		for(j = 0;j<2*i-1;j++)
			printf("*");
		for(j = 0;j<n-i;j++)
			printf(" ");
		printf("\n");
	}
	return 0;
}
int Process(int a,int b)
{
	int i,t;
	if(a>b)
	{
		t = a;
		a = b;
		b = t;
	}
	for(i = a;i>=2;i--)
		if(a%i==0&&b%i==0) return i;
}

