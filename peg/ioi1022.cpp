#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

int n,people[1000005],par[1000005],best=2100000000,bestloc,sum;
list<int> alist[1000005];

int dfs(int v)
{
	int s=0,biggest=0;
	for (auto it:alist[v])
		if (it != par[v])
		{
			par[it] = v;
			int temp = dfs(it);
			s += temp;
			if (temp > biggest) biggest = temp;
		}
	if (max(biggest,sum-s-people[v]) < best)
	{
		best = max(biggest,sum-s-people[v]);
		bestloc = v;
	} 
	return s+people[v];
}

int main()
{
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{
		scanf("%d",&people[i]);
		sum += people[i];
	}	
	for (int v1,v2,i=0; i<n-1; i++)
	{
		scanf("%d%d",&v1,&v2);
		alist[v1].push_back(v2);
		alist[v2].push_back(v1);
	}
	par[0]=1000002; // no par
	dfs(0);
	printf("%d\n",bestloc);
	return 0;
}
