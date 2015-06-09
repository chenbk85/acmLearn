// 208-1004-Let the Balloon Rise.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i,j,n,m,count[1000],max,t;
	string s[1000],temp;
	while(1)
	{
		cin>>m;
		if(!m) break;
		for(i = 0;i < m;i++)
			cin>>s[i];
		for(i = 0;i<m;i++) count[i] = 1;
		for(i = 0;i < m-1;i++)
		{
			for(j = 0;j < m-1-i;j++)
				if(s[j] > s[j+1]) 
				{
					temp = s[j];
					s[j] = s[j+1];
					s[j+1] = temp;
				}
		}
		j = 0;
		while(j<m)
		{
			for(i = j;s[i]==s[i+1];i++)
				count[j]++;			
			j += count[j];
		}
		max = count[0];
		t = 0;
		for(i = 0;i<m;i++)
			if(max<count[i]) {t = i;}
		cout<<s[t]<<endl;
	}
	return 0;	
}

