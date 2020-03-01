#include <cstdio>
#include <algorithm>
using namespace std;

int t, n;
struct node{
	int start, end, minus;
};
bool operator<(node a, node b)
{
	return a.start < b.start;
}
node times[50005];

int main()
{
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d",&n);
		for (int i=0; i<n; i++)
		{
			scanf("%d%d",&times[i].start,&times[i].end);
			times[i].minus = 0;
		}	
		sort(times,times+n);
		int apantisi=0, prev=0;
		node temp;
		for (int i=0; i<n; i++)
		{
			prev = prev + 1 - times[i].minus;
			if (prev > apantisi)
				apantisi = prev;
			temp.start = times[i].end+1;
			++lower_bound(times+i+1,times+n,temp)->minus;
		}
		printf("Case %i: %i\n",i+1,apantisi);
	}
	return 0;
}

