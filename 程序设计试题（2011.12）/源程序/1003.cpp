
#include <stdio.h>
#include<string.h>                                    //要用到string.h头文件中函数
int main()
{
	int i;
	char a[20]="MMM",b[200],c[10];
	while(1)                //控制循环条件
	{
		gets(a);
        if(strcmp(a,"ENDOFINPUT")==0)break;
		gets(b);
		gets(c);                                     //输入三行字符串信息
		for(i=0;b[i]!='\0';i++)
		{
			if(b[i]==' '||b[i]==',')continue;               //如果为空格或者逗号则跳过
			if(b[i]>=65&&b[i]<70){b[i]+=21; continue;}
			if(b[i]>69&&b[i]<91){b[i]-=5;continue;}             //在一定范围内解码
		}
		printf("%s\n",b);                             //输出原码
	}
	return 0;
}

