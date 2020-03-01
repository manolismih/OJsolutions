#include <cstdio>
#include <bitset>
#include <cstring>
#incude <list>
using namespace std;

bitset<60005> tree;
int t,n,apantisi;
list<int> helpar[30005];

void update(int pos)
{
	int from=1, to=n, i=1;
	while (from != to)
	{
		tree[i] = 1;
		if (i<=(from+to)/2)
			to = (from+to)/2, i = 2*i;
		else
			from = (from+to)/2 + 1, i = 2*i + 1;
	}
	tree[i]=1;	
}

int query(int pos)
{
	int from=1, to=
}

int main()
{
	scanf("%d",&t);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&n);
		apantisi=n;
		tree.reset();
		for (int num, i=1; i<=n; i++)
		{
			scanf("%d",&num);
			helpar[num].push_back(i);
		}
		
		for (int i=2; i<=30000; i++)
		{
			for (auto it=helpar[i-1].begin(); it!=helpar[i-1].end(); it++)
			{
				update(*it);
				int platos = *it - query(*it);
				if (platos*i > apantisi) apantisi = platos*i;
			}
			helpar[i-1].clear();
		}		
		printf("Case %i: %i\n",i,apantisi);
	}
	return 0;
}

