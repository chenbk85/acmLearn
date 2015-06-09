#include   <stdio.h>
void  main( )
{
	int g,i,k,n,a[10]={0,0,0,0,0,0,0,0,0,0},p,k1,k2;
	char ch;
	long m1,m2,m3;
	scanf("%c%d%d",&ch,&k1,&k2);
	p=ch-'A'+1;
	i=1;a[1]=1;n=0;
	while(1)
	{
		g=1;
		for(k=i-1;k>=1;k--)
			if(a[i]==a[k]) g=0;                      //数字重复 过滤掉
		if((i==p)&&(a[p]<k1||a[p]>k2)) g=0;          //第i方格为受限格，过滤掉范围以外的选择
		if(i==9&&g==1)
		{
			m1=a[2]*10+a[3];
			m2=a[5]*10+a[6];
			m3=a[8]*10+a[9];
			if(a[4]*a[7]*m1+a[1]*a[7]*m2==a[1]*a[4]*m3)    //等式是否成立
			{
				n++;
				printf("(%d) %d/%ld+%d/%ld=%d/%d\n",n,m1,a[1],m2,a[4],m3,a[7]);
			}
		}
		if(i<9&&g==1)                              //不到9个数，继续
		{
			i++;a[i]=1;continue;	
		}
		while(a[i]==9&&i>1) i--;                    //往前回溯
		if(i==1&&a[i]==9) break;                    //a[1]==9，第1个数为9，所有数均试过，结束
		else a[i]++;                                //试探a[i]下一个数字
	}
}