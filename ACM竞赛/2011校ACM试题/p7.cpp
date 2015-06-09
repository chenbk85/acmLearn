#include <stdio.h>
#include <iostream.h>
#include <string.h>

main()
{
	int u,n,i,j,k,max,s,total,t,all;
	int a[60][30];
	int b[2000],c[2000];
	int e[300];
	
	scanf("%d",&n);
	u=0;
	
	while (n>0)
	{
		u++;
		total=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		b[0]=1;
		all=0;
		
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i][0]);
			all+=a[i][0];
			for (j=1;j<=a[i][0];j++)
			{
				scanf("%d",&a[i][j]);
			}
		}/*读入数据*/

		for (i=1;i<=n;i++)
		{
			memset(c,0,sizeof(c));
			s=0;
			max=0;
			
			for (j=1;j<=a[i][0];j++)
			{
				s=s+10-a[i][j];
				if (s>max) max=s;
			}

			s=0;
			memset(e,0,sizeof(e));
			
			if (max==0) e[0]=1;
			
			for (j=1;j<=a[i][0];j++)
			{
				s=s+10-a[i][j];
				if (s==max) e[j]=1;
			}

			total+=max;
			for (j=0;j<=a[i][0];j++)
			
			for (k=0;k<=all;k++)
			{
				if (b[k]==1 && e[j]==1)
				{
					c[k+j]=1;
				}
			}

			for (k=0;k<=all;k++)
				b[k]=c[k];
		}/*递推求解*/

		printf("Workyards %d\n",u);
		printf("Maximum profit is %d.\n",total);
		printf("Number of pruls to buy:");
		t=0;

		for (k=0;k<=all;k++)
			if (b[k]==1)
			{
				t++;
				printf(" %d",k);
				if (t>=10) break;
			}

		/*输出解答*/
		printf("\n\n");
		scanf("%d",&n);
	}
}

