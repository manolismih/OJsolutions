#include <cstdio>
#include <algorithm>
using namespace std;

//general
int n, cow[100005], ans, best;

//count inversions
int pos[100005], s[400000];
void inc(int pos, int i=1, int from=1, int to=n)
{
	int middle;
	while (from != to)
	{
		s[i]++;
		middle = (from+to)/2;
		if (pos<=middle)
		{
			to = middle;
			i<<=1;
		}
		else
		{
			from = middle+1;
			i = (i<<1)+1;
		}
	}
	s[i]++;
}

int sum(int from, int to, int i=1, int posfrom=1, int posto=n)
{
	if (posfrom==posto) return s[i];
	int middle = (posfrom+posto)/2;
	return (from<=middle ? sum(from,min(middle,to),2*i,posfrom,middle) : 0) +
		(to>middle ? sum(max(from,middle+1),to,2*i+1,middle+1,posto) : 0);
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&cow[i]);
		pos[cow[i]] = i;
	}
	
	for (int i=n; i>0; i--)
	{
		inc(pos[i]);
		int proig = pos[i]==1 ? 0 : sum(1,pos[i]-1);
		ans += i - pos[i] + proig;
	}
	best = ans;
	
	for (int i=n; i>0; i--)
	{
		ans += n-1;
		ans -= 2*(n-pos[i]);
		best = min(best,ans);
	}
	printf("%d\n",best);
	return 0;
}

