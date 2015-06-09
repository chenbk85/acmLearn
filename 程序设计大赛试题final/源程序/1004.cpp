
#include"math.h"
#include"stdio.h"

int main()
{
	int a1,a2,a3,a4,a5,i,j,m;
	long int m3,n3,m4,n4,m5,n5;
	static int t[9];
	static long s[9][10];
	scanf("%d",&m);
	for(a1=1;a1<=9;a1++)
		for(a2=0;a2<=9;a2++)
			for(a3=0;a3<=9;a3++)
			{
				m3=a1*100+a2*10+a3;
				n3=pow(a1,3)+pow(a2,3)+pow(a3,3);
				if(m3==n3)s[3][++t[3]]=m3;
				for(a4=0;a4<=9;a4++)
				{
					m4=m3*10+a4;
					n4=pow(a1,4)+pow(a2,4)+pow(a3,4)+pow(a4,4);
					if(m4==n4)s[4][++t[4]]=m4;
					for(a5=0;a5<=9;a5++)
					{
						m5=m4*10+a5;
						n5=pow(a1,5)+pow(a2,5)+pow(a3,5)+pow(a4,5)+pow(a5,5);
						if(m5==n5)s[5][++t[5]]=m5;
					}
				}
			}
			if(m==2){printf("Armstrong number of:1 1\n");}
			if(m==3) {
			printf("Armstrong number of 1:1\n");
			printf("Armstrong number of 2:does not exist!\n");
			}
			if(m>3) {printf("Armstrong number of 1:1 2 3 4 5 6 7 8 9\n");
			printf("Armstrong number of 2:does not exist!\n");
			for(i=3;i<m;i++)
			{
				
				printf("Armstrong number of %d:",i);
				for(j=1;j<=t[i];j++)
					printf("%ld ",s[i][j]);printf("\n");
			}
			}
			
		return 0;
}










