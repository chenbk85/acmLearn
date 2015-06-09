#include <stdio.h>
#include <string.h>

int main()
{
	char code1[26][5];

    int cc,t,i,j,s,k;
	char tt[2];
	char st[10];

	char orii[256];
	char re[256];
	char temp[600];
	char num[101];

	strcpy(code1[0],".-"); /* A */
	strcpy(code1[1],"-..."); /* B */
	strcpy(code1[2],"-.-."); /* C */
	strcpy(code1[3],"-.."); /* D */
	strcpy(code1[4],"."); /* E */
	strcpy(code1[5],"..-."); /* F */
	strcpy(code1[6],"--."); /* G */
	strcpy(code1[7],"...."); /* H */
	strcpy(code1[8],".."); /* I */
	strcpy(code1[9],".---"); /* J */
	strcpy(code1[10],"-.-"); /* K */
	strcpy(code1[11],".-.."); /* L */
	strcpy(code1[12],"--"); /* M */
	strcpy(code1[13],"-."); /* N */
	strcpy(code1[14],"---"); /* O */
	strcpy(code1[15],".--."); /* P */
	strcpy(code1[16],"--.-"); /* Q */
	strcpy(code1[17],".-."); /* R */
	strcpy(code1[18],"..."); /* S */
	strcpy(code1[19],"-"); /* T */
	strcpy(code1[20],"..-"); /* U */
	strcpy(code1[21],"...-"); /* V */
	strcpy(code1[22],".--"); /* W */
	strcpy(code1[23],"-..-"); /* X */
	strcpy(code1[24],"-.--"); /* Y */
	strcpy(code1[25],"--.."); /* Z */


	scanf("%d",&cc);
	getchar();
 
	for(i=1;i<=cc;i++)
	{
		scanf("%s",orii);
		temp[0] = 0;
		num[0] = 0;
		for(j=0;orii[j];j++)
		{
			switch(orii[j])
			{
				case '_':
							strcat(temp,"..--");
							strcat(num,"4"); break;
				case '.':
							strcat(temp,"---.");
							strcat(num,"4"); break;
				case ',':
							strcat(temp,".-.-");
							strcat(num,"4"); break;
				case '?':
							strcat(temp,"----");
							strcat(num,"4"); break;
				default:
							strcat(temp,code1[orii[j]-'A']);
							t = strlen(code1[orii[j]-'A']);
							tt[0] = t+'0';
							tt[1] = 0;
							strcat(num,tt); break;
			}
		}
		
		t = strlen(num);
		s = 0;
		re[0] = 0;
		
		for(j=t-1;j>=0;j--)
		{
			strncpy(st,temp+s,num[j]-'0');
			st[num[j]-'0'] = 0;
			for(k=0;k<26;k++)
			{
				if(strcmp(st,code1[k])==0)
				{
					tt[0] = k+'A';
					tt[1] = 0;
					strcat(re,tt);
					break;
				}
			}
			
			if(strcmp(st,"..--")==0)
				strcat(re,"_");
			else if(strcmp(st,"---.")==0)
				strcat(re,".");
			else if(strcmp(st,".-.-")==0)
				strcat(re,",");
			else if(strcmp(st,"----")==0)
				strcat(re,"?");
			s+=num[j]-'0';
		}
 
		printf("%d: %s\n",i,re);
	}

	return 0;
}
