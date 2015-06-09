// 尼科彻斯定理.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<stdio.h>
int main()
{
    int a,b,c,d,n;
	scanf("%d",&n);
	while(n--)
	{
    scanf("%d",&a);           /*输入整数*/
    b=a*a*a;                  /*求整数的三次方*/
    printf("%d*%d*%d=%d=",a,a,a,b);
    for(d=0,c=0;c<a;c++)       /*输出数列，首项为a*a-a+1,等差值为2*/
    {
        d+=a*a-a+1+c*2;       /*求数列的前a项的和*/
        printf(c?"+%d":"%d",a*a-a+1+c*2);
    }
	printf("\n");
	}
	return 0;
}

