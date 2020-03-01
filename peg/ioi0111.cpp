#include <cstdio>

int n,sum[1030][1030];

int main()
{
	scanf("%d%d",&n,&n);
	int type,val,x,y,l,b,r,t;
	while (scanf("%d",&type) && type!=3)
		if (type==1)
		{
			scanf("%d%d%d",&x,&y,&val);
			for (int i=x; i<=n; i++) sum[y][i] += val;
		}
		else
		{
			scanf("%d%d%d%d",&l,&b,&r,&t);
			int ans=0;
			for (int y=b; y<=t; y++) ans += sum[y][r] - sum[y][l-1];
			printf("%d\n",ans);
		}
}
