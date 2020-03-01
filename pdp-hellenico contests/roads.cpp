#include <cstdio>
#include <set>
using namespace std;
#define pii pair<int,int>
#define itr multiset<pair<int,int> >::iterator
#define mp make_pair
#define inf l+100

int n,l,k;
pii curr;
itr it1,it2,it3,it4;
multiset<pii> gap;
multiset<int> gapsize;

bool intersect(pii a, pii b){return a.second>=b.first && a.first<=b.second;}
bool whole (pii a, pii b)	{return a.first>=b.first && a.second<=b.second;}
void findits ()
{
	it1 = it2 = gap.upper_bound(mp(curr.first,-1));
    if (intersect(*prev(it1),curr)) it1--;
    else it1=gap.end();
    if (!whole(*it2,curr)) it2=gap.end();
    
    it3 = it4 = prev(gap.upper_bound(mp(curr.second,inf)));
    if (!intersect(*it4,curr)) it3=it4=gap.end();
    if (whole(*it4,curr)) it4 = gap.end();
	else it3--;
	if (it3 != gap.end() && !whole(*it3,curr)) it3 = gap.end();
	
	if (it1==it4) it4=gap.end();
}

void delmid()
{
	it3++;
	for (itr it=it2; it!=it3; it++) 
		gapsize.erase(gapsize.find(it->second - it->first + 1));
	gap.erase(it2,it3);
}

void fix(itr it)
{
	pii prev = *it;
	gapsize.erase(gapsize.find(prev.second - prev.first + 1));
	gap.erase(it);
	if (whole(curr,prev))
	{
		if (prev.first < curr.first)
		{
			gap.insert({prev.first,curr.first-1});
			gapsize.insert(curr.first-prev.first);
		}
		if (prev.second > curr.second)
		{
			gap.insert({curr.second+1,prev.second});
			gapsize.insert(prev.second-curr.second);
		}
	}
	else if (prev.first <= curr.second)
	{
		gap.insert({curr.second+1,prev.second});
		gapsize.insert(prev.second-curr.second);
	}
	else
	{
		gap.insert({prev.first,curr.first-1});
		gapsize.insert({curr.first-prev.first});
	}
}

int main()
{
    scanf("%d%d%d",&n,&l,&k);
    gap.insert({-100,-10});
    gap.insert({0,l-1});
    gapsize.insert(l);

    for (int i=1; i<=n; i++)
    {
		scanf("%d%d",&curr.first,&curr.second);
		curr.second--;
		findits();
        if (it3 != gap.end()) delmid();
		if (it1 != gap.end()) fix(it1);
		if (it4 != gap.end()) fix(it4);
		
		if (*prev(gapsize.end()) <= k)
		{
			printf("%d\n",i);
			return 0;
		}
    }
    printf("-1\n");
}
