#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 2e9
#define ll long long

//general
int n, x[300005];
bool type[300005]; // 0 for tele, 1 for coin
ll dp[300005];

//segment tree
ll val[2][1200000];

void putcoin(int &i, int &k, int *coin)
{
	x[k] = coin[i++];
	type[k++] = 1;
}

void puttele(int &j, int &k, int *tele)
{
	x[k] = x[k+1] = tele[j++];
	type[k] = 0;
	type[k+1] = 1;
	k += 2;
}

void read()
{	
	int m, coin[100005], tele[100005];
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) scanf("%d",&coin[i]);
	for (int i=1; i<=m; i++) scanf("%d",&tele[i]);
	int i=1, j=1, k=1;
	while (i<=n || j<=m)
		if (i>n) puttele(j,k,tele);
		else if (j>m) putcoin(i,k,coin);
		else if (coin[i] == tele[j])
		{
			puttele(j,k,tele);
			i++;
		}
		else if (coin[i] < tele[j]) putcoin(i,k,coin);
		else puttele(j,k,tele);
	n = k-1;
}

void set(int pos, ll x1, ll x2, int i=1, int beg=0, int end=300000)
{
	while (beg<end)
	{
		val[0][i] = min(val[0][i],x1);
		val[1][i] = min(val[1][i],x2);
		int mid=(beg+end)/2;
		if (pos <= mid) i*=2, end=mid;
		else i=2*i+1, beg=mid+1;
	}
	val[0][i] = x1;
	val[1][i] = x2;
}

ll query(int tree, int from, int to, int i=1, int beg=0, int end=300000)
{
	if (from>to) return inf;
	if (from==beg && to==end) return val[tree][i];
	int mid=(beg+end)/2;
	return min(query(tree,from,min(mid,to),2*i,beg,mid),query(tree,max(from,mid+1),to,2*i+1,mid+1,end));
}

int main()
{
	//freopen("in.txt","r",stdin);
	read();
	for (int i=0; i<2; i++)
		for (int j=0; j<1200000; j++) val[i][j]=inf;
		
	int t1=0,t2=0,t3=0,prv; //t1: pio prev, t2:prev, t3:next teleporter
	long long l;
	for (t3++; t3 <= n && type[t3]; t3++);
	for (int i=1; i<=n; i++)
		if (type[i])
		{
			if (!t2) dp[i] = inf;
			else
			{
				l = x[i]-x[t2];
				int b = lower_bound(x+t1,x+t2+1,x[t2]-l) - x;
				dp[i] = min({l+dp[prv], l+query(0,b,t2), 2*l+query(1,t1,b)});
			}
			l = x[t3]-x[i];
			set(i,2*l+dp[i-1],l+dp[i-1]);
		}
		else
		{
			prv = i-1;
			dp[i] = dp[i-1];
			t1 = t2;
			t2 = t3;
			for (t3++; t3 <= n && type[t3]; t3++);
		}
	printf("%lld\n",dp[n]);
}
