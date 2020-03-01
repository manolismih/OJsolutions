#include <cstdio>

int n,h[100005],x[100005],t[100005],stack[100005],stacki,curh,ans;

int main()
{
	freopen("artin.txt","r",stdin);
	freopen("artout.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d %d",&t[i],&x[i],&h[i]);
	}
	for(int i=1;i<=n;++i)
	{
		while(stacki>0)
		{
			int top=stack[stacki-1];
			if(t[i]>t[top]+x[top]-1)
			{
				stacki--;
				curh-=h[top];
			}
			else break;
		}
		stack[stacki++]=i;
		curh+=h[i];
		if(curh>ans) ans=curh;
	}
	printf("%d",ans);
}

