#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mod 5000000

int n,k, s[100005], dp[100005][2], tree[400000];

int add(int pos, int val)
{
	int i=1,posfrom=0,posto=100001;
	while (posfrom != posto)
	{
		tree[i] += val;
		if (tree[i]>=mod) tree[i] -= mod;
		if (pos <= (posfrom+posto)/2) posto = (posfrom+posto)/2, i*=2;
		else posfrom = (posfrom+posto)/2 +1, i = i*2 +1;
	}
	tree[i] += val;
	if (tree[i]>=mod) tree[i] -= mod;
}

int sum(int from, int to, int i=1, int posfrom=0, int posto=100001)
{
	if (from==posfrom && to==posto) return tree[i];
	int middle = (posfrom+posto)/2;
	int ret = (from <= middle ? sum(from,min(to,middle),2*i,posfrom,middle) : 0) +
			(to > middle ? sum(max(from,middle+1),to,2*i+1,middle+1,posto) : 0);
	return ret>=mod ? ret-mod : ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; i++) scanf("%d",&s[i]);
	
	for (int i=1; i<=n; i++) dp[i][1]=1;
	for (int l=2; l<=k; l++)
	{
		for (int i=n; i>0; i--)
		{
			dp[i][l%2] = sum(s[i]+1,100001);
			add(s[i],dp[i][(l-1)%2]);
		} 
		memset(tree,0,400000*4);
	}
	for (int i=n-1; i>0; i--) dp[i][k%2] = (dp[i][k%2] + dp[i+1][k%2])%mod;	
	printf("%d\n",dp[1][k%2]);
	return 0;
}

