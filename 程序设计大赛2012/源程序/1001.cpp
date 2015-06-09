
#include<stdio.h>
int main()
{
	int n,a,b,s;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		if(a >= 100)
		{
			a %= 100;
		}
		if(b >= 100)
		{
			b %= 100;
		}
		s = a + b;
		if(s >= 100)
		{
			s %= 100;
		}
		printf("%d\n",s);
	}
	return 0;
}

