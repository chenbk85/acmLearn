#include <stdio.h>
#include <math.h>
int main()
{
	int HJ=0;
	for(int i=0;i<16;i++) // 16=2^4 : (0 0 0 0)~~(1 1 1 1) 的全排列
	{  
		int A=1000,B=2000;
		for(int j=0;j<4;j++) // 因为4回合判定一次,以4个一组 例如(0 1 0 1)可表示为A(失败 胜利 失败 胜利)  
		{	   
			if(i&(1<<j))
			{	   
				A+=B/4;
				B-=B/4;
			}
			else
			{
				B+=A/4;
				A-=A/4;
			}
		}
		if(abs(A-B)>=1000)
			HJ++; 
	}
	printf("%.3f\n",HJ*pow(0.5,4));
	return 0;   
}
