#include <stdio.h>
#include <malloc.h>

//int c=0;
int* data;
void display(int m)
{
	int j;
	printf("%d",data[0]);
	for(j=1;j<m;j++)	
		printf("+%d",data[j]);
//	c++;
	printf("\n");
}

void HJ(int n,int m)
{	
	int i;	
	if(n==0)	
		display(m);   
	else		
		for(i=n;i>0;i--)		
			if(m==0||i<=data[m-1])			
			{			
				data[m]=i;	
				HJ(n-i,m+1);	
			}		
}

int main()
{
	int n;
		printf("n: ");
		scanf("%d",&n);
		data = (int*) malloc(n*sizeof(int));
		HJ(n,0);
	//	printf("count: %d\n",c);
		free(data);
	return 0;
}

