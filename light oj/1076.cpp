#include <cstdio>
using namespace std;

int t, n, containers, vessels[1005];

void bs(int from, int to)
{
	if (from == to)
	{
		printf("%i\n",from);
		return;
	}
	int maxcap = (from+to)/2, containleft=containers-1, filled=0;
	bool ok=true;
	for (int i=0; i<n; i++)
		if (filled+vessels[i] <= maxcap)
			filled += vessels[i];
		else
		{
			filled = vessels[i];
			if (--containleft < 0)
			{
				ok = false;
				break;
			}
		}
	if (ok) bs(from,maxcap);
	else bs(maxcap+1,to);
}

int main()
{
	scanf("%i",&t);
	for (int i=0; i<t; i++)
	{
		printf("Case %i: ",i+1);
		scanf("%i%i",&n,&containers);
		int max=-2000000000, sum=0;
		for (int i=0; i<n; i++)
		{
			scanf("%i",vessels+i);
			if (vessels[i] > max) max = vessels[i];
			sum += vessels[i];
		}
		bs(max,sum);
	}
	return 0;
}

