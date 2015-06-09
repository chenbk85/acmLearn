// 1005.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,c,j,k,m,t,p,q;
	char string[100],temp[8],a,b;
	scanf("%d",&n);
	while(n--)
	{
		getchar();
		gets(string);
		t = 0;
		strcpy(temp,"000");
		for(i = 0;string[i]!='\0';i++)
		{
			if(string[i]>='0'&&string[i]<='9')  {a = string[i];j=i;}
			if(j==i) break;
		}
		for(i = j+1;string[i]!='\0';i++)
		{
			if(string[i]>='0'&&string[i]<='9')  b = string[i];
			if(b==string[i])  break;
		}
		while(!strcmp(temp,"000"))
		{
			for(i = 0;string[i]!='\0';i++)
			{
				if(string[i]=='a'&&string[i+1]=='d')  strcpy(temp,"adds");
				if(string[i]=='a'&&string[i+1]=='d')  break;
				if(string[i]=='m'&&string[i+1]=='i')  strcpy(temp,"minus");
				if(string[i]=='m'&&string[i+1]=='i')  break;
				if(string[i]=='t'&&string[i+1]=='i')  strcpy(temp,"times");
				if(string[i]=='t'&&string[i+1]=='i')  break;
				if(string[i]=='d'&&string[i+1]=='i')  strcpy(temp,"divided");
				if(string[i]=='d'&&string[i+1]=='i')  break;
			}
		}
		p = a-48;
		q = b-48;
		if(strcmp(temp,"adds")==0) {c = p+q;printf("%d+%d=%d\n",p,q,c);}
		if(strcmp(temp,"minus")==0) 
		{
			c = p-q;
			if(c<0) printf("The result is minus!\n");
			else 
			printf("%d-%d=%d\n",p,q,c);
		}
		if(strcmp(temp,"times")==0)  {c = p*q;printf("%d*%d=%d\n",p,q,c);}
		if(strcmp(temp,"divided")==0) {c = p/q;printf("%d/%d=%d\n",p,q,c);}
	}
	return 0;
}

