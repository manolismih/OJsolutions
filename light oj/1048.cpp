#include <cstdio>
using namespace std;

int t, n, d, dist[1005], apantisi[305], ai=0, biggerdist;
bool found;

void check(int day, int from)
{
	if (day==d+1)
		if (from == n+1)
		{
			for (int i=0; i<=d; i++)
				printf("%i\n",apantisi[i]);
			found = true;
			return;
		}
		else return;
	if (from == n+1) return;
	int i, currdist=0;
	for (i=from; i<=n && currdist+dist[i] <= biggerdist; i++)
		currdist += dist[i];
	for (--i; !found && i>=from; i--)
	{
		apantisi[day] = currdist;
		check(day+1,i+1);
		currdist -= dist[i];
	}
}

void bs(int from, int to)
{
	if (from == to)
	{
		printf("%i\n",from);
		biggerdist = from;
		check(0,0);
		return;
	}
	int maxdist=(from+to)/2, currdist=0, daysleft=d;
	bool ok=true;
	for (int i=0; i<=n; i++)
		if (currdist+dist[i] <= maxdist)
			currdist += dist[i];
		else
		{
			currdist = dist[i];
			--daysleft;
			if (daysleft < 0)
			{
				ok = false;
				break;
			}
		}
	if (ok) bs(from,maxdist);
	else bs(maxdist+1,to);
}

int main()
{
	scanf("%i",&t);
	for (int i=0; i<t; i++)
	{
		found = false;
		printf("Case %i: ",i+1);
		scanf("%i%i",&n,&d);
		int max=-2000000000, sum=0;
		for (int i=0; i<=n; i++)
		{
			scanf("%i",dist+i);
			if (dist[i] > max) max = dist[i];
			sum += dist[i];
		}
		bs(max,sum);
	}
}
