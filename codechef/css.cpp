#include <cstdio>
#include <map>
using namespace std;

map<pair<int,int>,int> myhash;
pair<int,int> elements[1000005], temp;
int id, n, q;
int main()
{
	scanf("%i%i",&n,&q);
	for (int pos, i=0; i<n; i++)
	{
		scanf("%i%i",&temp.first,&temp.second);
		pos = myhash[temp];
		if (!pos) myhash[temp] = pos = ++id;
		scanf("%i%i",&temp.first,&temp.second);
		if (temp.second >= elements[pos].second)
			elements[pos] = temp;
	}
	for (int i=0; i<q; i++)
	{
		scanf("%i%i",&temp.first,&temp.second);
		printf("%i\n",elements[myhash[temp]].first);
	}
	return 0;
}

