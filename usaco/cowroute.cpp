#include <cstdio>
#include <list>
#include <queue>
using namespace std;

struct node{
	int to, flights;
	long long cost;
};
inline bool operator<(node a, node b)
{
	return (a.cost == b.cost ? a.flights > b.flights : a.cost > b.cost);
}
list<node> alist[1005];
priority_queue<node> oura;

FILE *fin=fopen("cowroute.in","r"), *fout=fopen("cowroute.out","w");
int a,b,m,n,from,curr;
node temp;
list<node>::iterator pos,it;
long long best[1005][2];

int main()
{
	for (int i=0; i<1005; i++)
		for (int j=0; j<2; j++)
			best[i][j] = 9000000000000000000;
	fscanf(fin,"%i%i%i",&a,&b,&m);
	best[a][0] = best[a][1] = 0;
	for (int i=0; i<m; i++)
	{
		fscanf(fin,"%i%i%i",&temp.cost,&n,&from);
		pos = prev(alist[from].end());
		for (temp.flights=1; temp.flights<n; ++temp.flights)
		{
			fscanf(fin,"%i",&temp.to);
			alist[from].push_back(temp);
		}
		curr = from;
		for (pos++; pos!=alist[curr].end(); pos++)
		{
			from = pos->to;
			for (it=next(pos), temp.flights=1; it!=alist[curr].end(); it++,++temp.flights)
			{
				temp.to = it->to;
				alist[from].push_back(temp);
			}	
		}
	}
	
	oura.push({a,0,0});
	while (!oura.empty())
	{
		node curr=oura.top();
		oura.pop();
		if (curr.cost != best[curr.to][0] || curr.flights != best[curr.to][1]) continue;
		if (curr.to == b)
		{
			fprintf(fout,"%lli %i\n",curr.cost,curr.flights);
			return 0;
		}
		
		for (it=alist[curr.to].begin(); it!=alist[curr.to].end(); it++)
			if (curr.cost+it->cost < best[it->to][0] || 
			curr.cost+it->cost == best[it->to][0] && curr.flights+it->flights < best[it->to][1])
			{
				best[it->to][0] = curr.cost+it->cost;
				best[it->to][1] = curr.flights+it->flights;
				oura.push({it->to,best[it->to][1],best[it->to][0]});
			}
	}
	fprintf(fout,"-1 -1\n");
	return 0;
}

