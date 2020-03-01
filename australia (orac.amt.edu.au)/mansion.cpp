#include <cstdio>

int n,w, curr, ans, people[100005];

int main()
{
	freopen("manin.txt","r",stdin);
	freopen("manout.txt","w",stdout);
	scanf("%d%d",&n,&w);
	for (int i=0; i<n; i++) scanf("%d",&people[i]);
	for (int i=0; i<w; i++) ans+=people[i];
	curr = ans;
	for (int i=w; i<n; i++)
	{
		curr += people[i] - people[i-w];
		if (curr>ans) ans = curr;
	}
	printf("%d\n",ans);
	return 0;
}

