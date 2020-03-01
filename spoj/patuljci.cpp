#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,q,tree[1200000],ni=1;
vector<int> instances[100001];

int emf(int num, int from, int to)
{
	return upper_bound(instances[num].begin(),instances[num].end(),to) 
	     - lower_bound(instances[num].begin(),instances[num].end(),from);
}

void read(int i, int posfrom, int posto)
{
	if (posfrom==posto)
	{
		scanf("%d",&tree[i]);
		instances[tree[i]].push_back(ni++);
		return;
	}
	int middle = (posfrom+posto)/2;
	read(2*i,posfrom,middle);
	read(2*i+1,middle+1,posto);
	if (tree[2*i] && emf(tree[2*i],posfrom,posto) > (posto-posfrom+1)/2.0) tree[i]=tree[2*i];
	else if (tree[2*i+1] && emf(tree[2*i+1],posfrom,posto) > (posto-posfrom+1)/2.0) tree[i]=tree[2*i+1];
}

int query(int from, int to, int i, int posfrom, int posto)
{
	if (from==posfrom && to==posto) return tree[i];
	int middle = (posfrom+posto)/2;
	if (to <= middle) return query(from,to,2*i,posfrom,middle);
	if (from > middle) return query(from,to,2*i+1,middle+1,posto);
	int a = query(from,middle,2*i,posfrom,middle), b = query(middle+1,to,2*i+1,middle+1,posto);
	if (!(a||b)) return 0;
	if (a==b) return a;
	if (a && emf(a,from,to) > (to-from+1)/2.0) return a;
	if (b && emf(b,from,to) > (to-from+1)/2.0) return b;
	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%*d",&n);
	read(1,1,n);
	scanf("%d",&q);
	for (int from,to,apantisi,i=0; i<q; i++)
	{
		scanf("%d%d",&from,&to);
		apantisi = query(from,to,1,1,n);
		if (apantisi) printf("yes %d\n",apantisi);
		else printf("no\n");
	}
	return 0;
}

