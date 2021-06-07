#include <cstdio>
#include <map>

int N, K, num[1000000];
std::map<int,int> emf;

int main()
{
	scanf("%d%d",&N,&K);
	for (int i=0; i<N; i++) scanf("%d",&num[i]);
	int ans=0, sum=0, diff=0, beg=0, end=-1;
	while (1)
		if (diff>K)
		{
			sum -= num[beg];
			emf[num[beg]]--;
			if (emf[num[beg]]==0) diff--;
			beg++;
		}
		else
		{
			ans = std::max(ans,sum);
			if (++end == N) break;
			sum += num[end];
			if (emf[num[end]]==0) diff++;
			emf[num[end]]++;
		}
	printf("%d\n",ans);
}
