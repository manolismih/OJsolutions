#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

FILE *fin = fopen("eforia.in","r"), *fout = fopen("eforia.out","w");
int n,m,akres[2],akresi=0;
long long apantisi=0;
struct node{
	int v;
	long long dist;
};
bool operator<(node a, node b)
{
	return a.dist>b.dist;
}
vector<node> alist[1000005];
priority_queue<node> oura;
long long best[10000005];

int main()
{
	fscanf(fin,"%i%i",&n,&m);
	node temp;
	for (int v, i=0; i<m; i++)
	{
		fscanf(fin,"%i%i%lli",&v,&temp.v,&temp.dist);
		alist[v].push_back(temp);
		swap(v,temp.v);
		alist[v].push_back(temp);
		apantisi += temp.dist;
	}
	for (int i=1; i<=n; i++)
		if (alist[i].size()%2)
			akres[akresi++] = i;
	for (int i=1; i<=n; i++)
		best[i] = 9000000000000000000;
	best[akres[0]] = 0;
	temp.v = akres[0];
	temp.dist = 0;
	oura.push(temp);
	while (!oura.empty())
	{
		node curr=oura.top();
		oura.pop();
		if (curr.v == akres[1])
		{
			fprintf(fout,"%lli\n",apantisi+curr.dist);
			return 0;
		}
		if (curr.dist == best[curr.v])
		{
			for (vector<node>::iterator it=alist[curr.v].begin(); it!=alist[curr.v].end(); it++)
				if (curr.dist+it->dist < best[it->v])
				{
					best[it->v] = curr.dist+it->dist;
					temp.v = it->v;
					temp.dist = best[it->v];
					oura.push(temp);
				}
		}
	}
	return 0;
}

