#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define w first
#define s second 

int nweak,nsmall,n, weak[50005], small[50005];
pair<int,int> toy[1000005];

bool check(int bound)
{
	int pos=0;
	multiset<int> rem;
	for (int i=0; pos<n && i<nweak; i++)
	{
		for ( ; pos<n && toy[pos].w<weak[i]; pos++)
			rem.insert(toy[pos].s);
		if (rem.size() <= bound) rem.clear();
		else for (int i=0; i<bound; i++) rem.erase(prev(rem.end()));
	}
	for (; pos<n; pos++) rem.insert(toy[pos].s);
	
	for (int i=0; pos<n && i<nsmall; i++)
		for (int del=0; !rem.empty() && *rem.begin()<small[i] && del<bound; del++)
			rem.erase(rem.begin());
			
	return rem.empty();	
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&nweak,&nsmall,&n);
	for (int i=0; i<nweak; i++) scanf("%d",&weak[i]);
	for (int i=0; i<nsmall; i++) scanf("%d",&small[i]);
	for (int i=0; i<n; i++) scanf("%d%d",&toy[i].w,&toy[i].s);
	sort(weak,weak+nweak);
	sort(small,small+nsmall);
	sort(toy,toy+n);
	
	int from= n/(nweak+nsmall), to=n+1, middle;
	while (from != to)
	{
		middle = (from+to)/2;
		if (check(middle)) to = middle;
		else from = middle+1;
	}

	printf("%d\n",from==n+1 ? -1 : from);
	return 0;
}

