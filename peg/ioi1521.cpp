#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define mod 1000000007

int n,q, bestpos[2000000], yint[500005];
long long gin[2000000];
double x[500005], y[500005], lazy[2000000], best[2000000];

void setx(int pos, int val, int i=1, int posfrom=0, int posto=n-1)
{
	if (posfrom==posto)
	{
		gin[i] = val;
		bestpos[i] = posfrom;
		return;
	}
	int middle = (posfrom+posto)/2;
	if (pos<=middle) setx(pos,val,2*i,posfrom,middle);
	else setx(pos,val,2*i+1,middle+1,posto);
	gin[i] = (gin[2*i] * gin[2*i+1]) % mod;
}

long long P(int from, int to, int i=1, int posfrom=0, int posto=n-1)
{
	if (from==posfrom && to==posto) return gin[i];
	int middle = (posfrom+posto)/2;
	return (from<=middle ? P(from,min(middle,to),2*i,posfrom,middle) : 1)
		* (to>middle ? P(max(from,middle+1),to,2*i+1,middle+1,posto) : 1) % mod;
}

void add(int from, int to, double val, int i=1, int posfrom=0, int posto=n-1)
{
	if (from==posfrom && to==posto)
	{
		lazy[i] += val;
		best[i] += val;
		return;
	}
	int middle = (posfrom+posto)/2;
	if (lazy[i])
	{
		lazy[2*i] += lazy[i];
		best[2*i] += lazy[i];
		lazy[2*i+1] += lazy[i];
		best[2*i+1] += lazy[i];
		lazy[i] = 0;
	}
	if (from<=middle) add(from,min(middle,to),val,2*i,posfrom,middle);
	if (to>middle) add(max(middle+1,from),to,val,2*i+1,middle+1,posto);
	if (best[2*i] > best[2*i+1])
	{
		best[i] = best[2*i];
		bestpos[i] = bestpos[2*i];
	}
	else
	{
		best[i] = best[2*i+1];
		bestpos[i] = bestpos[2*i+1];
	}
}

int query()
{
	return (P(0,bestpos[1]) * yint[bestpos[1]]) % mod;
}

int main()
{
	scanf("%d",&n);
	for (int num, i=0; i<n; i++)
	{
		scanf("%d",&num);
		setx(i,num);
		x[i] = log2(num);
		add(i,n-1,x[i]);
	}
	for (int i=0; i<n; i++)
	{
		scanf("%d",&yint[i]);
		y[i] = log2(yint[i]);
		add(i,i,y[i]);
	}
	printf("%d\n",query());
	
	scanf("%d",&q);
	double fval;
	for (int type,pos,val, i=0; i<q; i++)
	{
		scanf("%d%d%d",&type,&pos,&val);
		fval = log2(val);
		if (type==1)
		{
			setx(pos,val);
			add(pos,n-1,fval-x[pos]);
			x[pos] = fval;
		}
		else
		{
			add(pos,pos,fval-y[pos]);
			y[pos] = fval;
			yint[pos] = val;
		}
		printf("%d\n",query());
	}
	return 0;
}
