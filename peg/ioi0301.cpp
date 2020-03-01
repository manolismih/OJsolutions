#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

list<int> alist[20005];
int n, par[20005], num[20005];

int dfs(int v)
{
	num[v]=1;
	for (auto &next:alist[v])
	{
		if (next == par[v]) continue;
		par[next] = v;
		num[v] += dfs(next);
	}
	return num[v];
}

int main()
{
	scanf("%d",&n);
	for (int a,b,i=1; i<n; i++)
	{
		scanf("%d%d",&a,&b);
		alist[a].push_back(b);
		alist[b].push_back(a);
	}
	par[1]=0;
	num[1] = dfs(1);
	int ans=n, pos;
	for (int i=1; i<=n; i++)
	{
		int sum=0,curr=0;
		for (auto &it:alist[i])
		{
			if (it==par[i]) continue;
			sum += num[it];
			curr = max(curr,num[it]);
		}
		curr = max(curr,n-sum-1);
		if (curr < ans)
		{
			ans = curr;
			pos = i;
		}
	}
	printf("%d %d\n",pos,ans);
}
