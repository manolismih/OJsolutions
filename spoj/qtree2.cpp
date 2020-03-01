#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n;
bool visited[10005];
struct node{
	int16_t parent, edgedist;
	int fulldist;
};
node tree[10005][15];

struct alistnode{
	int to, dist;
};
alistnode alist[10005][10005];
int16_t sizes[10005], depths[10005];

void process(int v, int prev, int prevdist, int depth)
{
	tree[v][0].parent = prev;
	tree[v][0].fulldist = prevdist;
	tree[v][0].edgedist = 1;
	depths[v] = depth;
	for (int i=1; i<15; i++)
	{
		tree[v][i].parent = tree[tree[v][i-1].parent][i-1].parent;
		tree[v][i].edgedist = tree[v][i-1].edgedist + tree[tree[v][i-1].parent][i-1].edgedist;
		tree[v][i].fulldist = tree[v][i-1].fulldist + tree[tree[v][i-1].parent][i-1].fulldist;
	}
	
	for (int i=0; i<sizes[v]; i++)
		if (!visited[alist[v][i].to])
		{
			visited[alist[v][i].to] = true;
			process(alist[v][i].to,v,alist[v][i].dist,depth+1);
		}
}

int fulldist(int v1, int v2)
{
	int ret=0, i;
	if (depths[v2] > depths[v1]) swap(v1,v2);
	while (depths[v1] > depths[v2])
	{
		for (i=0; depths[tree[v1][i].parent] >= depths[v2]; i++);
		ret += tree[v1][i-1].fulldist;
		v1 = tree[v1][i-1].parent;
	}
	if (v1==v2) return ret;
	
	while (tree[v1][0].parent != tree[v2][0].parent)
	{
		for (i=0; tree[v1][i].parent != tree[v2][i].parent; i++);
		ret += tree[v1][i-1].fulldist + tree[v2][i-1].fulldist;
		v1 = tree[v1][i-1].parent, v2 = tree[v2][i-1].parent;
	}
	return ret + tree[v1][0].fulldist + tree[v2][0].fulldist; 
}

int kth (int a, int b, int k)
{
	int v1=a, v2=b, i, lca_level;
	if (depths[v2] > depths[v1]) swap(v1,v2);
	while (depths[v1] > depths[v2])
	{
		for (i=0; depths[tree[v1][i].parent] >= depths[v2]; i++);
		v1 = tree[v1][i-1].parent;
	}
	if (v1 != v2)
	{
		while (tree[v1][0].parent != tree[v2][0].parent)
		{
			for (i=0; tree[v1][i].parent != tree[v2][i].parent; i++);
			v1 = tree[v1][i-1].parent, v2 = tree[v2][i-1].parent;
		}
		lca_level = depths[v1]-1;
	}
	else lca_level = depths[v1];
	
	int goal, start, curr=0;
	if (k <= depths[a]-lca_level)
		start = a, goal = k-1;
	else
		start = b, goal = depths[a]+depths[b]-2*lca_level-k+1;
		
	while (curr < goal)
	{
		for (i=0; curr+tree[start][i].edgedist <= goal; i++);
		curr += tree[start][i-1].edgedist;
		start = tree[start][i-1].parent;
	}
	return start;
}

int main()
{
	scanf("%i",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%i",&n);
		memset(sizes,0,(n+1)*2);
		memset(visited,0,n+1);
		for (int a,b,dist, i=0; i<n-1; i++)
		{
			scanf("%d%d%d",&a,&b,&dist);
			alist[a][sizes[a]].to = b;
			alist[a][sizes[a]++].dist = dist;
			alist[b][sizes[b]].to = a;
			alist[b][sizes[b]++].dist = dist;
		}
		
		visited[1] = true;
		process(1,0,0,1);
		
		char c=0;
		int a, b, k;
		while (c != 'O')
		{
			scanf(" %c%c",&c,&c);
			switch (c)
			{
				case 'T':
					scanf("H %i%i%i",&a,&b,&k);
					printf("%i\n",kth(a,b,k));
					break;
				case 'I':
					scanf("ST %i%i",&a,&b);
					printf("%i\n",fulldist(a,b));
					break;
				case 'O':
					scanf("NE");
					printf("\n");
					break;
			}
		}
	}
	return 0;
}

