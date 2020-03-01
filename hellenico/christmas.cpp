#include <cstdio>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;

FILE *fin = fopen("christmas.in","r"), *fout = fopen("christmas.out","w");
struct alistnode{
	int v,dist,id;
};
list<alistnode> alist[50005];

struct queuenode{
	int v,prev,dist,depth,id;
};
bool operator<(queuenode a, queuenode b)
{
	return a.dist > b.dist;
}
queuenode tonode(int v, int prev, int dist, int depth, int id)
{
	queuenode ret={v,prev,dist,depth,id};
	return ret;
}
priority_queue<queuenode> oura;

struct treenode{
	int parent, max;
};
treenode tree[50005][20];

bool used[100005], visited[50005];
int n, m, better[50005], depths[50005];
long long mst, mst2=9000000000000000000;

void process(int &v, int &prev, int &prevdist, int &depth)
{
	tree[v][0].parent = prev;
	tree[v][0].max = prevdist;
	depths[v] = depth;
	for (int i=1; i<17; i++)
	{
		tree[v][i].parent = tree[tree[v][i-1].parent][i-1].parent;
		tree[v][i].max = max(tree[v][i-1].max, tree[tree[v][i-1].parent][i-1].max);
	}
}

void findmst()
{
	queuenode temp = {1,0,0,1,100004}; // queuenode{v,prev,dist,depth,id}
	oura.push(temp);
	while (!oura.empty())
	{
		queuenode curr = oura.top();
		oura.pop();
		if (visited[curr.v]) continue;
		visited[curr.v] = true;
		mst += curr.dist;
		used[curr.id] = true;
		process(curr.v,curr.prev,curr.dist,curr.depth);
		for (list<alistnode>::iterator it=alist[curr.v].begin(); it != alist[curr.v].end(); it++)
			if (it->dist < better[it->v])
			{
				better[it->v] = it->dist;
				oura.push(tonode(it->v,curr.v,it->dist,curr.depth+1,it->id));
			}
	}
}

void check(int v1, int v2, int dist)
{
	long long curr = mst+dist;
	int biggest=0,i;
	if (depths[v2] > depths[v1]) swap(v1,v2);
	while (depths[v1] > depths[v2])
	{
		for (i=0; depths[tree[v1][i].parent] >= depths[v2]; i++);
		if (tree[v1][i-1].max > biggest) biggest = tree[v1][i-1].max;
		v1 = tree[v1][i-1].parent;
	}
	if (v1 != v2)
	{
		while (tree[v1][0].parent != tree[v2][0].parent)
		{
			for (i=0; tree[v1][i].parent != tree[v2][i].parent; i++);
			if (max(tree[v1][i-1].max,tree[v2][i-1].max) > biggest) biggest = max(tree[v1][i-1].max,tree[v2][i-1].max);
			v1 = tree[v1][i-1].parent, v2 = tree[v2][i-1].parent;
		}
		if (max(tree[v1][0].max,tree[v2][0].max) > biggest) biggest = max(tree[v1][0].max,tree[v2][0].max);
	}
	if (curr-biggest < mst2) mst2 = curr-biggest;
}

int main()
{
	fscanf(fin,"%i%i",&n,&m);
	alistnode temp={0,0,0};
	for (int i=2; i<=n; i++)
		better[i] = 2000000000;
	for (int from, i=0; i<m; i++, temp.id++)
	{
		fscanf(fin,"%i%i%i",&from,&temp.v,&temp.dist);
		alist[from].push_back(temp);
		swap(from,temp.v);
		alist[from].push_back(temp);
	}
	findmst();
	
	for (int i=1; i<=n; i++)
		for (list<alistnode>::iterator it=alist[i].begin(); it!=alist[i].end(); it++)
			if (!used[it->id])
			{
				check(i,it->v,it->dist);
				used[it->id] = true;
			}
				
	fprintf(fout,"%lli %lli\n",mst,mst2);
	return 0;
}

