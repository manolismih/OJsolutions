#include <cstdio>
#include <algorithm>

int N, from[10005], to[10005], order[10005];

bool compare(int a, int b)	{	return to[a]<to[b];}

int main()
{
	freopen("rentacar.in","r",stdin);    
    freopen("rentacar.out","w",stdout);    
    scanf("%d",&N);    
    for(int i=1; i<=N; i++) scanf("%d%d%d",&order[i],&from[i],&to[i]);
	
	std::sort(order+1,order+N+1,compare);
	int time=0, ans=0;
	for (int i=1; i<=N; i++)
		if (from[order[i]]>=time)
		{
			time = to[order[i]];
			ans++;
		}
	printf("%d",ans);
}
