// 211-1009-FatMouse' Trade.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<stdio.h>
struct
{
    int java;
    int food;
    double aver;
}unit[10000],t;
int main()
{
    int i,j,k,m,n;
    double sum;
    while(scanf("%d%d",&m,&n)!=EOF&&n!=-1&&m!=-1)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&unit[i].java,&unit[i].food);
            unit[i].aver=(double)(unit[i].java)/unit[i].food;
        }
        for(i=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
            {
                if(unit[k].aver<unit[j].aver)
                    k=j;
            }
            t=unit[k];
            unit[k]=unit[i];
            unit[i]=t;
        }
        for(i=0;i<n&&m!=0;i++)
        {
            if(m>=unit[i].food)
            {
                m-=unit[i].food;
                sum+=unit[i].java;
            }
            else
            {
                sum+=unit[i].aver*m;
                m=0;
            }
        }
        printf("%.3f\n",sum);
    }
    return 0;
}