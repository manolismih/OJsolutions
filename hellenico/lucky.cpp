#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int tree[4000000], n[4000000], num=1;
vector<int> lucky;

void make(int i=1, int posfrom=1, int posto=1000000)
{
	n[i] = posto-posfrom+1;
	if (posfrom==posto)
	{
		tree[i] = num;
		num += 2;
	}
	else
	{
		make(2*i,posfrom,(posfrom+posto)/2);
		make(2*i+1,(posfrom+posto)/2 +1,posto);
	}
}

int kth(int k, bool del, int i=1, int posfrom=1, int posto=1000000)
{
	if (del) n[i]--;
	if (posfrom==posto) return tree[i];
	if (n[2*i] >= k) return kth(k,del,2*i,posfrom,(posfrom+posto)/2);
	else return kth(k-n[2*i],del,2*i+1,(posfrom+posto)/2 +1, posto);
}

void collect(int i=1, int posfrom=1, int posto=1000000)
{
	if (posfrom==posto) lucky.push_back(tree[i]);
	else
	{
		if (n[2*i]) collect(2*i,posfrom,(posfrom+posto)/2);
		if (n[2*i+1]) collect(2*i+1,(posfrom+posto)/2 +1,posto);
	}
}

int main()
{
	freopen("luckynum.in","r",stdin);
	freopen("luckynum.out","w",stdout);
	make();
	for (int i=2; ; i++)
	{
		int k = kth(i,0);
		if (k>n[1]) break;
		for (int i=k; i<=n[1]; i += k-1)
			kth(i,1);
	}
	collect();
	
	//for (int i=0; i<10; i++) printf("%d\n",lucky[i]);
	
	int a, b=0, c=0;
	scanf("%d",&a);
	for (vector<int>::iterator it=lucky.begin(); it!=lucky.end(); it++)
		if (binary_search(it,lucky.end(),a-*it))
		{
			b = *it;
			c = a-*it;
		}
	printf("%d %d\n",b,c);
	return 0;
}

