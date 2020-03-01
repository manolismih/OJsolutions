#include <cstdio>
#include <set>
using namespace std;

struct coder{ int a,b,id;	};
bool operator<(coder c1, coder c2) {	return (c1.a != c2.a ? c1.a<c2.a : c1.b<c2.b);	}
set<coder> coders;
int n, tree[400000], ans[300005], count[300005]; //το count για να κρατάει πόσα διπλά έχουμε

void add(int pos, int val)
{
	int i=1, posfrom=1, posto=100000;
	while (posfrom != posto)
	{
		tree[i] += val;
		if (pos <= (posfrom+posto)/2) posto = (posfrom+posto)/2, i*=2;
		else posfrom = (posfrom+posto)/2+1, i = i*2+1;
	}
	tree[i] += val;
}

int sum(int from, int to, int i=1, int posfrom=1, int posto=100000)
{
	if (from==posfrom && to==posto) return tree[i];
	int middle = (posfrom+posto)/2;
	return (from <= middle ? sum(from,min(to,middle),2*i,posfrom,middle) : 0)
		+  (to > middle ? sum(max(middle+1,from),to,2*i+1,middle+1,posto) : 0);
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	coder temp;
	for (temp.id=1; temp.id<=n; temp.id++)
	{
		scanf("%d%d",&temp.a,&temp.b);
		ans[temp.id] = -coders.insert(temp).first->id;
		count[-ans[temp.id]]++;
	}
	
	for (auto it:coders)
	{
		ans[it.id] = sum(1,it.b);
		add(it.b,count[it.id]);
	}
	
	for (int i=1; i<=n; i++)
		if (ans[i]>= 0) printf("%d\n",ans[i]);
		else printf("%d\n",ans[-ans[i]]);
	return 0;
}

