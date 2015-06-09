#include<stdio.h>
int main()
{
	int i,c,b,j,s,k;
	int a[100];
	scanf("%d%d",&c,&b);
    for(i=c;i<b+1;i++)
	{
		s=0;k=0;
		for(j=1;j<i;j++)
			if(i%j==0){a[k]=j;k++;}
		for(j=0;j<k;j++)
			s=s+a[j];
		if(i==s)printf("%d\n",i);
			
	}
	return 0;
}