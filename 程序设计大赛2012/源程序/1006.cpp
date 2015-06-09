// 215-1022-Train Problem.cpp : 定义控制台应用程序的入口点。
//


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	int *base;
	int *top;
	int size;
	int length;
}Stack;
void Init(Stack &S)
{
	S.base = (int *)malloc(10*sizeof(int));
	S.top = S.base;
	S.size = 10;
	S.length = 0;
}
void Push(Stack &S,int e)
{
	*S.top++ = e;
	S.length++;
}
void Pop(Stack &S)
{
	S.top--;
	S.length--;
}
int main()
{
	Stack S;
	int a[20],k,r;
	char string1[10],string2[10];
	int i,n,j,m;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%s%s",&n,string1,string2);
		j = 0;
		r = 0;
		k = 0;
		Init(S);
		for(i = 0;string1[i]!='\0';i++)
		{
			Push(S,string1[i]-48);
			a[k++] = 1;
			if(string1[i]==string2[j]) 
			{
				Pop(S);
				j++;
				a[k++] = 0;
				for(r = i-1;r >= 0;r--)
				{
					if(string1[r]==string2[j])
					{
						Pop(S);
						a[k++] = 0;
						j++;
					}
					else break;
				}
			}
		}
		while(S.length>0)
		{
			if(*(S.top-1) == string2[j]-48)
			{
				Pop(S);
				j++;
				a[k++] = 0;
			}
			else break;
		}
		if(j>=strlen(string2)) 
			{
				printf("Yes.\n");
				for(i = 0;i < k;i++)
				{
						if (a[i] == 1) printf("in\n");
						else printf("out\n");
				}
		     }
		else printf("No.\n");
		printf("FINISH\n");
	}
	return 0;
}

