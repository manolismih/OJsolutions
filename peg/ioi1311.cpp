#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

struct node{
	int par,pardist,maxloc;
	long long max,max2;
};
node tree[100001];
int n,m,l,groups;
list<pair<int,int>> alist[100001];
bool vis[100001];
long long best, max1, max2, max3, apantisi=0;

void insert3()
{
	if (best > max1)
	{
		max3 = max2;
		max2 = max1;
		max1 = best;
	}
	else if (best > max2)
	{
		max3 = max2;
		max2 = best;
	}
	else if (best > max3) max3 = best;
}

void insert(node &curr, long long dist, int loc)
{
	if (dist > curr.max)
	{
		curr.max2 = curr.max;
		curr.max = dist;
		curr.maxloc = loc;
	}
	else if (dist > curr.max2) curr.max2 = dist;
}

void process(int v)
{
	vis[v] = true;
	for (auto it : alist[v])
		if (it.first != tree[v].par) 
		{
			tree[it.first].par = v;
			tree[it.first].pardist = it.second;
			process(it.first);
			insert(tree[v],it.second+tree[it.first].max,it.first);
		}	
}

void findmax(int v)
{
	if (tree[tree[v].par].maxloc == v) insert(tree[v],tree[v].pardist+tree[tree[v].par].max2,tree[v].par);
	else insert(tree[v],tree[v].pardist+tree[tree[v].par].max,tree[v].par);
	if (tree[v].max < best) best = tree[v].max;
	if (tree[v].max > apantisi) apantisi = tree[v].max;
	for (auto it : alist[v])
		if (it.first != tree[v].par)
			findmax(it.first);
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&l);
	pair<int,int> temp;
	for (int v,i=0; i<m; i++)
	{
		scanf("%d%d%d",&v,&temp.first,&temp.second);
		alist[v].push_back(temp);
		swap(v,temp.first);
		alist[v].push_back(temp);
	}
	
	for (int i=0; i<n; i++)
		if (!vis[i])
		{
			++groups;
			tree[i].par = 100000; // no par
			process(i);
			best = 9000000000000000000;
			findmax(i);
			insert3();
		}	
	if (groups>1 && max1+max2+l > apantisi) apantisi = max1+max2+l;
	if (groups > 2 && max2+l > max1 && max2+l+max3+l > apantisi) apantisi = max2+l+max3+l;
	printf("%lld\n",apantisi);
	return 0;
}
