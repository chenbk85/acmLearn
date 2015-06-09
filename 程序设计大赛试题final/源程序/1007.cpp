
#include<stdio.h>
#include<string.h>
int main()
{
	char s[100][100],str[100];
	int i=0,j,k,m,n,a[100],t;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
			a[i]=0;
		    scanf("%s",s[i]);
	}
	for(i=0;i<m;i++)
		for(j=0;j<n-1;j++)
			for(k=j+1;k<n;k++)
				if(s[i][j]>s[i][k]) a[i]++;
	for(i=0;i<m-1;i++)
		for(j=0;j<m-1-i;j++)
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				strcpy(str,s[j]);
				strcpy(s[j],s[j+1]);
				strcpy(s[j+1],str);
			}
	for(i=m-1;i>=0;i--)
		printf("%s\n",s[i]);
	return 0;
}
