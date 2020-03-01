#include <cstdio>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

FILE *fin=fopen("resistance.in","r"), *fout=fopen("resistance.out","w");
struct node{
	int v,id, cost;
};
inline bool operator<(node a, node b)
{
	return a.cost < b.cost;
}
list<node> alist[20005];
priority_queue<node> oura;

int n,m,tnt, needsi, needs[1000005], better[20005];
bool used[1000005], visited[20005];

void findmaxst()
{
	node temp={1,1000003,0};
	oura.push(temp);
	while (!oura.empty())
	{
		node curr=oura.top();
		oura.pop();
		if (visited[curr.v]) continue;
		visited[curr.v] = used[curr.id] = true;
		for (list<node>::iterator it=alist[curr.v].begin(); it!=alist[curr.v].end(); it++)
			if (!visited[it->v] && it->cost > better[it->v])
			{
				better[it->v] = it->cost;
				oura.push(*it);
			}
	}
}

int main()
{
	fscanf(fin,"%i%i%i",&n,&m,&tnt);
	node temp={0};
	for (int v, i=0; i<m; i++, temp.id++)
	{
		fscanf(fin,"%d%d%d",&v,&temp.v,&temp.cost);
		alist[v].push_back(temp);
		swap(v,temp.v);
		alist[v].push_back(temp);
	}
	
	findmaxst();
	for (int i=1; i<=n; i++)
		for (list<node>::iterator it=alist[i].begin(); it!=alist[i].end(); it++)
			if (!used[it->id])
			{
				used[it->id] = true;
				if (it->cost <= tnt)
					needs[needsi++] = it->cost; 
			}
			
	sort(needs,needs+needsi);
	int i=0;
	for (; tnt-needs[i]>=0; i++)
		tnt -= needs[i];
	
	fprintf(fout,"%i\n",i);
	return 0;
}

