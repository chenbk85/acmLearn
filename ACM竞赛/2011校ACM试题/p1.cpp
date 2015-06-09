#include   <stdio.h>
int revs(int m);
int revs(int m)
{
	int n=0;

	while(m)
	{
		n=n*10+m%10;
		m=m/10;
	}
	return(n);
}

void  main( )
{
	int d,n,k,m;
	scanf("%d",&d);
	while(d-->0) {
		scanf("%d",&n);
		m=revs(n);
		k=0;
		if(m==n) printf("%d %d\n",k,n);
		else 
		{
			for(k=1;k<=10;k++)
			{
				n=m+n;
				m=revs(n);
				if(m==n) break;
			}
			if(k>10) printf("impossible\n");
			else printf("%d %d\n",k,n);
		}
	}
}
