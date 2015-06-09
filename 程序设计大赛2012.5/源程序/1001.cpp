
#include<stdio.h>
int main(void)
{
    double x[4],y[4],a,b,c,p,q,s;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x[1],&y[1],&x[2],&y[2],&x[3],&y[3]);
        a=((y[1]-y[2])*(x[1]-x[3])-(y[1]-y[3])*(x[1]-x[2]))/((x[1]*x[1]-x[2]*x[2])*(x[1]-x[3])-(x[1]*x[1]-x[3]*x[3])*(x[1]-x[2]));
        b=(y[1]-y[2]-a*(x[1]*x[1]-x[2]*x[2]))/(x[1]-x[2]);
        c=y[1]-a*x[1]*x[1]-b*x[1];
        p=(y[2]-y[3])/(x[2]-x[3]);
        q=y[2]-p*x[2];
        s=a*x[3]*x[3]*x[3]/3+(b-p)*x[3]*x[3]/2+(c-q)*x[3]-(a*x[2]*x[2]*x[2]/3+(b-p)*x[2]*x[2]/2+(c-q)*x[2]);
        printf("%.2lf\n",s);
    }
    return 0;
}

