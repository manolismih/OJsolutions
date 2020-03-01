#include <cstdio>
#include <queue>
#include <list>
#include <set>
using namespace std;

FILE *fin=fopen("alexandros.in","r"), *fout=fopen("alexandros.out","w");
int n, q, dfs[400005], apantiseis[400005];
list<int> oalist[400005]; 

struct poli{
	int to, cost;
	list<pair<int,int> > querries; //pair<water,id>
};
poli poleis[400005];

struct node{
	int v, cost, poleis;
};
bool operator<(node a, node b)
{
	return a.cost > b.cost;
}
inline node tonode(int v, int cost, int poleis)
{
	node ret={v,cost,poleis};
	return ret;
}

struct point{
	int bound, extra;
};
point topoint(int bound, int extra)
{
	point ret={bound,extra};
	return ret;
}
bool operator<(point a, point b)
{
	return a.bound < b.bound;
}

int do_dfs(int v)
{
	while (!dfs[v])
	{
		dfs[v] = 1;
		v = poleis[v].to;
	}
	int max = -2000000000, maxloc;
	while (dfs[v] != 2)
	{
		dfs[v] = 2;
		if (poleis[v].cost > max)
		{
			max = poleis[v].cost;
			maxloc = v;
		} 
		v = poleis[v].to;
	}
	for (list<int>::iterator it=oalist[poleis[maxloc].to].begin(); ; it++)
		if (*it == maxloc)
		{
			oalist[poleis[maxloc].to].erase(it);
			return maxloc;
		}
}

int main()
{
	fscanf(fin,"%i%i",&n,&q);
	for (int i=1; i<=n; i++)
	{
		fscanf(fin,"%d%d",&poleis[i].to,&poleis[i].cost);
		oalist[poleis[i].to].push_back(i);
	}
	for (int v,water, i=0; i<q; i++)
	{
		fscanf(fin,"%d%d",&v,&water);
		poleis[v].querries.push_back(make_pair(water,i));
	}
	
	for (int i=1; i<=n; i++)
	{
		if (dfs[i]) continue;
		priority_queue<node> oura;
		set<point> minus;
		int start = do_dfs(i);
		oura.push(tonode(start,poleis[start].cost,1));
		
		while (!oura.empty())
		{
			node curr = oura.top();
			oura.pop();
			dfs[curr.v] = 1000;
			
			set<point>::iterator it=minus.upper_bound(topoint(curr.cost,-100));
			if (it!=minus.begin())
			{
				minus.erase(minus.begin(),it);
				it = minus.begin();
			}
			minus.insert(it,topoint(curr.cost,curr.poleis-1));
			
			for (list<pair<int,int> >::iterator lit=poleis[curr.v].querries.begin(); lit!=poleis[curr.v].querries.end(); lit++)
			{
				it = minus.upper_bound(topoint(lit->first,-100));
				if (it == minus.end())
					apantiseis[lit->second] = -1;
				else
					apantiseis[lit->second] = curr.poleis - it->extra;
			}
			
			for (list<int>::iterator lit=oalist[curr.v].begin(); lit!=oalist[curr.v].end(); lit++)
				oura.push(tonode(*lit,poleis[*lit].cost,curr.poleis+1));
		}
	}
		
	for (int i=0; i<q; i++)
		fprintf(fout,"%i\n",apantiseis[i]);
	return 0;
}

