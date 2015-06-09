
#include<stdio.h>
int main()
{
	int n,i,j,m;
	scanf("%d",&m);
	while(m--)
	{
	scanf("%d",&n);
	if(n==0)  break;
	j = 0;
	for(i = 1;i<=n;i++)
	{
		if(n%i==0)
			j = j+1;
	}
	j = j%4;
	if(j==0) printf("East\n");
	if(j==1) printf("South\n");
	if(j==2) printf("West\n");
	if(j==3) printf("North\n");
	}
    return 0;
}

