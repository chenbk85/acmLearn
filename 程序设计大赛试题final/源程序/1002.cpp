// 10020.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"
#include "string.h"
int main()
{
	int n,i,a[200],k,j;
	char s[200],b[200]; 
	while(1)
	{
        scanf("%d",&n);
	    if(n==0)break;
	    for(i=0;i<n;i++)
		    scanf("%d",&a[i]);
		while(1)
		 { 
			 scanf("%d",&k);
			 if(k==0)break;
		     getchar();
			 gets(s);
			 if(strlen(s)<n)
				 for(i=strlen(s);i<n;i++)
					 s[i]=' ';
			 s[i]='\0';
			 for(j=k;j>0;j--)
			 {
				 for(i=0;i<200;i++) b[i]=' ';
				 for(i=0;i<n;i++)
				 b[a[i]-1]=s[i]; 
				 b[i]='\0';
				 for(i=0;i<n;i++)
					 s[i]=b[i];
			 }
				for(i=0;i<n;i++)
					printf("%c",b[i]);
				printf("\n");
		}
	}
	return 0;
}

