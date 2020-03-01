#include <cstdio>
#include <algorithm>
using namespace std;
#define mod 10007

int *sx = new int[100005]()+1, *sx2 = new int[100005]()+1;
struct node{
	int la,lb,lc,sum;
	void add(int, int, int, int, int);
	void propagate(int, int, int, int);
};
node tree[800000];
int n,q;

int s(initializer_list<int> lista)
{
	int ret=0;
	for (auto it:lista) ret += it;
	return ret>=0 ? ret%mod : ret%mod + mod;
}

void node::add(int a, int b, int c, int posfrom, int posto)
{
	int x2 = s({sx2[posto],-sx2[posfrom-1]}), x = s({sx[posto],-sx[posfrom-1]}), size = s({posto,-posfrom+1});
	sum = s({sum,a*x2,b*x,size*c});
	la = s({la+a}), lb = s({lb+b}), lc = s({lc+c});
}

void node::propagate(int i, int posfrom, int middle, int posto)
{
	tree[2*i].add(la,lb,lc,posfrom,middle);
	tree[2*i+1].add(la,lb,lc,middle+1,posto);
	la = lb = lc = 0;
}

void add(int from, int to, int a, int b, int c, int i=1, int posfrom=0, int posto=n-1)
{
	if (from==posfrom && to==posto)
	{
		tree[i].add(a,b,c,posfrom,posto);
		return;
	}
	int middle = (posfrom+posto)/2;
	if (tree[i].la || tree[i].lb || tree[i].lc) tree[i].propagate(i,posfrom,middle,posto);
	if (from <= middle) add(from,min(to,middle),a,b,c,2*i,posfrom,middle);
	if (to > middle) add(max(middle+1,from),to,a,b,c,2*i+1,middle+1,posto);
	tree[i].sum = s({tree[2*i].sum,tree[2*i+1].sum});
}

int sum(int from, int to, int i=1, int posfrom=0, int posto=n-1)
{
	if (from==posfrom && to==posto) return tree[i].sum;
	int middle = (posfrom+posto)/2;
	if (tree[i].la || tree[i].lb || tree[i].lc) tree[i].propagate(i,posfrom,middle,posto);
	return s({from<=middle ? sum(from,min(middle,to),2*i,posfrom,middle) : 0
			, to>middle ? sum(max(middle+1,from),to,2*i+1,middle+1,posto) : 0});
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	
	for (long long i=1; i<n; i++)
	{
		sx[i] = (sx[i-1]+i) % mod;
		sx2[i] = (sx2[i-1] + i*i) % mod;
	}	
	
	for (int type,from,to,a,b,c, i=0; i<q; i++)
	{
		scanf("%d%d%d",&type,&from,&to);
		if (type) printf("%d\n",sum(from,to));
		else
		{
			scanf("%d%d%d",&a,&b,&c);
			add(from,to,a,b,c);
		}
	}
}
