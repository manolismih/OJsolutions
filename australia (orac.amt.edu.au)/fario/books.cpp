#include <cstdio>

int n,m,ir, height[100005], inf[100005];
bool irr[100005], vis[100005];

void dfs(int pos)
{
	vis[pos] = 1;
	if (pos != 1 && height[pos-1] >= height[pos] && !vis[pos-1]) dfs(pos-1);
	if (pos != n-1 && height[pos+1] >= height[pos] && !vis[pos+1]) dfs(pos+1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&ir);
	for (int i=1; i<=n; i++) scanf("%d",&height[i]);
	for (int i=1; i<=m; i++) scanf("%d",&inf[i]);
	for (int num, i=1; i<=ir; i++) 
	{
		scanf("%d",&num);
		irr[num] = 1;
	}
	
	for (int i=1; i<=m; i++) 
		if (!vis[inf[i]]) dfs(inf[i]);
	int ans=0;
	for (int i=1; i<=n; i++)
		if (vis[i] && irr[i]) ans++;
	printf("%d\n",ans);
	return 0;
}

