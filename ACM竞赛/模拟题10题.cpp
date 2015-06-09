#include <stdio.h>
#include <time.h>
#define  N 21
void npow(int p[],int n)       //计算n的N次方保存在p[]数组中，低位存储在低位
{
	int i,j,k,m,len;
	for(i=0;i<N+1;i++) p[i]=0;
	p[0]=n;len=1;
	for(i=1;i<N;i++)
	{
		for(k=0,j=0;j<len;j++)
		{
			m=p[j]*n+k;
			p[j]=m%10;
			k=m/10;
		}
		if(k>0) {p[j]=k;len++;} 
	}
}
int nextn(int p[])               //对当前p[]的N为整数，求下一个数
{
	int i,m;

	for(i=0;i<N;i++)
		if(p[i]!=0) break;
	m=p[i];
	while(i>=0)
	{
		p[i]=m-1;
		i--;
	}
	if(p[N-1]==0) return(0);
	else return(1);
}
void prn(int s[])                   //打印结果
{
	int i;
	for(i=N-1;i>=0;i--)
		printf("%d",s[i]);
	printf("\n");
}
void main()
{ int a[10][25],i,j,k,rst[N],fg[10],f,len;
  int s[21]={8,8,8,8,8,                  //初值，当有10个9时已超过21位
             8,8,8,8,8,
	         8,9,9,9,9,
		     9,9,9,9,9,
		     9};
  time_t t1,t2;
  time(&t1);
  for(i=0;i<10;i++)                        //输出N次方表
  {
	  npow(a[i],i);
	  for(j=N-1;j>=0;j--)
		  printf("%d",a[i][j]);
	  printf("\n");
  }
   printf("------------------------\n");
  while(1) 
  {
	  k=0;
	  for(i=0;i<N;i++)                //计算
	  {
		  rst[i]=k;
		  for(j=0;j<N;j++)
		  {
			  rst[i]+=a[s[j]][i];
		  }
		  k=rst[i]/10;
		  rst[i]%=10;
	  }
	  if(k==0) {                        //小于等于21位
		  len=N;
		  while(rst[len-1]==0) len--;
		  if(len!=N) break;              //小于21位，结束
		  for(i=0;i<10;i++) fg[i]=0;
		  for(i=0;i<N;i++) {             //置标志
			  fg[rst[i]]++;
			  fg[s[i]]--;
		  }
		  for(f=0,i=0;i<10;i++)           //判相等
			  if(fg[i]!=0) {f=1;break;}
		  if(f==0)                         //相等输出解
			  prn(rst);
	  }
  
      if(nextn(s)==0) break;               //找下一个数

  }
    time(&t2);
	printf("time=%ds\n",t2-t1);

}
