#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int fath[110];
int r[11000],u[11000],v[11000],w[11000];
int map[110][110];
int used[110][110];
int find(int x)
{
    return fath[x]==x?fath[x]:fath[x]=find(fath[x]);
}
bool cmp(int i,int j)
{
    return w[i]<w[j];
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(used,0,sizeof(used));

		int i;
        for(i=1;i<=n;i++) fath[i]=i;

        for(i=1;i<=n*(n-1)/2;i++) r[i]=i;

		int j;
        for(i=1;i<=n;i++) 
			for(j=1;j<=n;j++) 
				scanf("%d",&map[i][j]);
        
		int Q;
		scanf("%d",&Q);
        while(Q--)
        {
            int x,y;
			scanf("%d%d",&x,&y);
            used[x][y]=used[y][x]=1;
        }

        int tmp=1;//¿ÉÓÃ±ßÊı
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                if(map[i][j]==0) continue;
                if(used[i][j])
                {
                    int x=find(i),y=find(j);
                    fath[x]=y;
                    continue;
                }
                u[tmp]=i,v[tmp]=j,w[tmp++]=map[i][j];
            }
        }
        sort(r+1,r+tmp,cmp);
        int cnt=0;
        for(i=1;i<tmp;i++)
        {
            int e=r[i];
            int x=find(u[e]),y=find(v[e]);
            if(x!=y)
            {
                cnt+=w[e];
                fath[x]=y;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
