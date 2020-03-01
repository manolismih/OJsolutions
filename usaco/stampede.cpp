#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

struct node{
	int from,to;
};
inline bool operator<(node a, node b)
{
	return a.from < b.from;
}
multiset<node> times;

struct cow{
	int x,y,speed;
};
cow cows[50005];
inline bool comp(cow a, cow b)
{
	return a.y < b.y;
}

FILE *fin=fopen("stampede.in","r"), *fout=fopen("stampede.out","w");
int n, vlepei;

int main()
{
	fscanf(fin,"%i",&n);
	for (int i=0; i<n; i++)
		fscanf(fin,"%i%i%i",&cows[i].x,&cows[i].y,&cows[i].speed);
	sort(cows,cows+n,comp);
	
	node curr={cows[0].speed*(-1-cows[0].x)};
	curr.to = curr.from + cows[0].speed;
	times.insert(curr);
	vlepei=1;
	for (int i=1; i<n; i++)
	{
		curr.from = cows[i].speed*(-1-cows[i].x);
		curr.to = curr.from + cows[i].speed;
		auto it = times.upper_bound(curr);
		if (it!=times.begin()) it=prev(it);
		if (it->from > curr.from || it->to < curr.to)
			vlepei++;
		
		//insert
		node insert;
		if (it==times.begin() && curr.from <= it->from)
		{
			while (curr.to >= it->from && it != prev(times.end()))
				it++;
			it--;
			insert.to=(max(it->to,curr.to));
			times.erase(times.begin(),next(it));
			times.insert(insert);
		}
				
		else if (it == prev(times.end()))
		{
			while (curr.from <= it->to && it!=times.begin())
				it--;
			it++;
			times.erase(it,times.end());	
			insert.from=min(it->from,curr.from);
			times.insert(insert);
		}
		else
		{
			insert = curr;
			if (curr.from <= it->to && curr.to > it->to)
			{
				insert.from = it->from;
				it = times.erase(it);
			}
			if (curr.to >= it->from)
			{
				insert.to = max(curr.to,it->to);
				it = times.erase(it);
			}
			times.insert(it,insert);
		}
	}
	fprintf(fout,"%i\n",vlepei);
	return 0;
}

