// 203_行编辑程序.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<stdio.h>
#include<string.h>
int main()
{
	char string1[100],string2[100];
	int i,j,k,flag,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",&string1);
		j = 0;
		flag = 0;
		for(i = 0;i < strlen(string1);i++)
		{
			if(flag) break;
			if(string1[i]=='@') 
			{
				k = i+1;
				flag = 1;
			}
			else k = 0;
		}
		for(i = k;i < strlen(string1);++i)
		{
			if(string1[i]=='#') string1[i-1] = '#';
		}
		for(i  = k;i < strlen(string1);++i)
		{
			if(string1[i]=='#') continue;
			string2[j++] = string1[i];
		}
		string2[j] = '\0';
		if(strlen(string2)==0) printf("###@###\n");
		else printf("%s\n",&string2);
	}
	return 0;
}

