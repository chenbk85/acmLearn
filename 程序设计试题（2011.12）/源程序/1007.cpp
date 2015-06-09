// 1007.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
int main()
{	
	int a[10],i,j,t,n,k;
	scanf("%d",&n);
	while(n!=0)
	{
	   for(i=0;i<n;i++)
	   {     
		scanf("%d",&a[i]);
	   } 
	    for(i=0;i<n;i++)
	    for(j=0;j<n-i-1;j++)
        {      
			if(a[j]>a[j+1])
	        {  
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
		}
	for(k=0;k<n;k++)
	{  printf("%d ",a[k]);
	} 
	printf("\n");
	scanf("%d",&n);

	}
     
	return 0;	
}

